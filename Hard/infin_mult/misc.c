/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <jwalle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/26 16:16:31 by jwalle            #+#    #+#             */
/*   Updated: 2015/03/26 16:16:33 by jwalle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "infin_mult.h"

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
	while (i < (10000000))
	{
		tab[i] = malloc(1000);
		i++;
	}
}

char *ft_itoa(int n)
{
	char *s;

	s = malloc(10000000);
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

void	destroy_tab(char **tab)
{
	int i;
	int k;

	i = 0;
	while (i < (10000000))
	{
		free(tab[i]);
		i++;
	}
}