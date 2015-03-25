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

void  infin_add(char *s1, char *s2)
{
	int i = ft_strlen(s1) - 1;
	int j = ft_strlen(s2) - 1;
	int max = (i > j) ? i : j;
	char *result;
	int tenth = 0;
	int rest = 0;
	int a = 0;
	int b = 0;
	

	result = malloc(max + 1);
	while (s1[i] || s2[j])
	{
		a = ft_atoi(s1[i]);
		b = ft_atoi(s2[j]);
		((a + b + tenth) > 9) ? (tenth = 1) : (tenth = 0);
		result[max] = ft_itoa((a + b + tenth) % 10);
		write(1, &result[max], 1);
		i--;
		j--;
		max--;
	}
	result = &result[max - 2];
	//write(1, result - 1, ft_strlen(result));
}

void print_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i] && tab[i][0])
	{
		//printf("tab = %s\n", tab[i]);
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

void infin_mult(char *s1, char *s2)
{
	int i;
	int j;
	char **tab;
	int temp;
	int k;
	int n;

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
			printf("s2 = %c, s1 = %c\n", s2[j], s1[i]);
			temp = ft_atoi(s2[j]) * ft_atoi(s1[i]);
			tab[k] = ft_zerodup(ft_itoa(temp), (ft_strlen(s2) - 1 - j) + (ft_strlen(s1) - 1 - i));
			k++;
			i--;
		}
		n++;
		j--;
	}
	tab[k] = 0;
	print_tab(tab);
}

int main(int ac, char **av)
{
	if (ac == 3)
		infin_mult(av[1], av[2]);
	write(1, "\n", 1);
	return(0);
}
