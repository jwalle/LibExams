/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infin_mult.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <jwalle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/26 12:09:49 by jwalle            #+#    #+#             */
/*   Updated: 2015/03/26 15:30:54 by jwalle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "infin_mult.h"

void print_tab(char **tab, int signe)
{
	int i;

	i = 0;
	char *str;

	str = (char *)malloc(10000000);
	str = "0";
		while (tab[i] && tab[i][0])
	{
		//str = infin_add(str, tab[i]);
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
			temp = ft_atoi(s2[j]) * ft_atoi(s1[i]);
			tab[k] = ft_zerodup(ft_itoa(temp), (ft_strlen(s2) - 1 - j) + (ft_strlen(s1) - 1 - i));
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
