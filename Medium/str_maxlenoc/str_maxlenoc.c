/*
	Fichiers à rendre : str_maxlenoc.c
	Fonctions Autorisées : write, malloc, free

	Ecrire un programme qui prend en parametres n chaines de caractères et qui affiche,
	suivi d’un retour à la ligne, la plus grande chaine de caractères incluse dans toutes les
	chaines passées en paramètres. Si plusieurs chaines correspondent, on affichera celle qui
	apparait en premier dans le premier paramètre. A noter que "" est forcement dans toutes
	les chaines.

	Si aucun parametre n’est transmis, str_maxlenoc affiche un retour à la ligne.

	On dit que A est inclus dans B avec A et B des chaines de caracteres si A est une
	sous-chaine de B ou si A et B sont identiques.
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int ft_strlen(char *str)
{
	return (*str ? ft_strlen(++str) + 1 : 0);
}

char *ft_strnndup(char *str, int start, int end)
{
	char *ret;
	int i;

	i = 0;
	ret = (char *)malloc(sizeof(char) * (end - start) + 1); 
	while (start < end)
	{
		ret[i] = str[start];
		start++;
		i++;
	}
	ret[i] = '\0';
	return (ret);
}


int ft_strnncmp(char *s1, char *s2, int start, int end)
{
	int i;

	i = 0;
	while (s1[i++] == s2[start++] && (start < end))
		;
	return (s1[i] - s2[start]);
}


int ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int ft_strstr(char *s1, char *s2)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (0);
	while (s1[i] != s2[j])
		i++;
	while (s1[i] == s2[j])
	{
		i++;
		j++;
	}
	if (i == ft_strlen(s2))
		return (1);
	return (0);
}

int find(char *current, char **stock)
{
	int i;

	i = 0;
	while (stock[i])
	{
		if (!ft_strcmp(stock[i], current))
			return (1);
		i++;
	}
	return (0);
}

void init_stock(char **stock)
{
	int i;

	i = 0;
	while (i < 100)
	{
		stock[i] = (char *)malloc(100);
		stock[i][0] = '\0';
		i++;
	}
}

int fill_stock(char **stock, char *first, int *len)
{
	int i;
	char *temp;
	int start;
	int end = 1;
	int count;

	count = 0;
	i = 0;
	while (end <= ft_strlen(first))
	{
		start = 0;
		while (start < end)
		{		
			temp = ft_strnndup(first, start, end); 
			if (!find(temp, stock) || count == 0)
			{
				//printf("temp = %s\n", temp);
				stock[i] = strdup(temp);
				len[i] = strlen(temp);
				count++;
				i++;
			}
			free(temp);
			start++;
		}
		end++;
	}
	return (count);
}


void str_maxlenoc(char **av ,int n, int (*f)(char *))
{
	int i;
	int count;
	int j;
	char *first;
	char **stock;
	char *ret;
	int *len;
	int max;

	max = 0;
	first = strdup(av[0]);
	*av++;
	i = 0;
	stock = malloc(10000);
	len = malloc(10000);
	init_stock(stock);
	count = fill_stock(stock, first, len);
	while (*av)
	{
		i = 0;
		while (stock[i])
		{
			if (!strstr(*av, stock[i]))
			{
				len[i] = 0;	
				free(stock[i]);
				//stock[i][0] = 0;
			}
			i++;
		}	
		av++;
	}
	i = 0;
	while (i < 100)
	{
		if (len[i] && len[i] > max)
			max = len[i];
		i++;
	}
	i = 0;
	while (count > i)
	{
		if (len[i] == max)
		{
			write(1, stock[i], max);
			//printf("%s\n", stock[i]);
			return;
		}
		i++;
	}
}

int main(int ac, char **av)
{
	int (*f)(char *);

	f = &ft_strlen;
	if (ac == 2)
		write(1, av[1], f(av[1]));
	if (ac > 2)
		str_maxlenoc(av + 1, ac - 1, f);
	write(1, "\n", 1);
	return (0);
}

