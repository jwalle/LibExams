/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infin_mult.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <jwalle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/26 12:09:49 by jwalle            #+#    #+#             */
/*   Updated: 2015/03/26 14:48:11 by jwalle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>




int ft_atoi(char c)
{
		return (c - '0');
}

int ft_strlen(char *str)
{
	return (*str ? ft_strlen(++str) + 1 : 0);
}

char				*ft_strjoin(char *s1, char *s2)
{
	int				s1_len;
	int				s2_len;
	char			*str;

	if ((str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)) == NULL)
		return (NULL);
	s1_len = -1;
	while (s1[++s1_len])
		str[s1_len] = s1[s1_len];
	s2_len = -1;
	while (s2[++s2_len])
		str[s1_len + s2_len] = s2[s2_len];
	str[s1_len + s2_len] = 0;
	free(s2);
	return (str);
}

char *ft_zerodup(char *str, int n)
{
	char *ret;
	int i;

	i = 0;
	ret = malloc(ft_strlen(str) + n + 1);
	while (str[i])
	{
		ret[i] = str[i];
		i++;
	}
	while (n--)
	{
		ret[i] = '0';
		i++;
	}
	ret[i] = 0;
	return (ret);
}

void	init_tab(char **tab)
{
	int i;
	int k;

	i = 0;
	while (i < (1000000))
	{
		tab[i] = malloc(100);
		i++;
	}
}

void	destroy_tab(char **tab)
{
	int i;
	int k;

	i = 0;
	while (i < (1000000))
	{
		free(tab[i]);
		i++;
	}
}


char *ft_itoa(int n)
{
	char *s;

	s = malloc(100);
	s += 100;
	*s = 0;
	while (1)
	{
		s--;
		*s = n % 10 + '0';
		n = n / 10;
		if (!n)
			break;
	}
	return (s);
}

char ft_unitoa(int n)
{
	return (n + '0');
}

int is_num(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

char *infin_add(char *s1, char *s2)
{
	int i = ft_strlen(s1) - 1;
	int j = ft_strlen(s2) - 1;
	int max = (i > j) ? i : j;
	char *result;
	int tenth = 0;
	int rest = 0;
	

	result = malloc(max + 1);
	while (is_num(s1[i]) || is_num(s2[j]))
	{
		int a = 0;
		int b = 0;
		is_num(s1[i]) ? a = ft_atoi(s1[i]) : 0;
		is_num(s2[j]) ? b = ft_atoi(s2[j]) : 0;
		result[max] = ft_unitoa((a + b + tenth) % 10);
		((a + b + tenth) > 9) ? (tenth = 1) : (tenth = 0);
		i--;
		j--;
		max--;
	}
	if (tenth)
		result = ft_strjoin("1", result);
	//free(result);
	return (result);
}

void print_tab(char **tab, int signe)
{
	int i;

	i = 0;
	char *str;

	str = (char *)malloc(10000);
	str = "0";
		while (tab[i] && tab[i][0])
	{
		str = infin_add(str, tab[i]);
		i++;
	}
	if (signe == -1)
		write(1, "-", 1);
	write(1, str, ft_strlen(str));
}

void infin_mult(char *s1, char *s2)
{
	int i;
	int j;
	char **tab;
	int temp;
	int k;
	int n;
	int signe;
	int *ten;
	int r;


	r = 0;
	ten = malloc(10000);
	signe = 1;
	if (s1[0] == '-')
	{
		signe *= -1;
		s1++;
	}
	if (s2[0] == '-')
	{
		signe *= -1;
		s2++;
	}
	k = 0;
	n = -1;
	tab = malloc(ft_strlen(s1) * ft_strlen(s2) + 1);
	init_tab(tab);
	j = ft_strlen(s2) - 1;
	while (j >= 0)
	{
		i = ft_strlen(s1) - 1;
		n++;
		while (i >= 0)
		{
			temp += (ft_atoi(s2[j]) * ft_atoi(s1[i]));
			if (r > 0 && ten[r] > 9)

			k++;
			i--;
		}
		n++;
		j--;
	}
	tab[k] = 0;
	print_tab(tab, signe);
	//destroy_tab(tab);
}


int main(int ac, char **av)
{
	if (ac == 3)
		infin_mult(av[1], av[2]);
	write(1, "\n", 1);
	return(0);
}
