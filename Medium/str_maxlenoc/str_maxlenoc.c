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

int ft_strlen(char *str)
{
	return (*str ? ft_strlen(++str) + 1 : 0);
}

char *ft_strnndup(char *str, int start, int end)
{
	char *ret;
	int i;

	i = 0;
	ret = (char *)malloc(sizeof(char) * (end - start)); 
	while (start < end)
	{
		ret[i] = str[start];
		start++;
	}
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


int find(char *current, char **stock)
{
	int i;

	i = 0;
	while (stock[i])
	{
		if (!ft_strnncmp(stock[i], current, 0, ft_strlen(current)))
			return (1);
		i++;
	}
	return (0);
}

void init_stock(char **stock)
{
	int i;

	i = 0;
	while (i < 1000)
	{
		stock[i] = (char *)malloc(100);
		i++;
	}
}

void fill_stock(char **stock, char *first)
{
	int i;
	int j;
	char *temp;
	int start;
	int end = 1;
	i = 0;
	while (end <= ft_strlen(first))
	{
		start = 0;
		while (start < end)
		{		
			temp = ft_strnndup(first, start, end); 
			if (!find(temp, stock))
				stock[i++] = ft_strnndup(first, start, end);
			free(temp);
			start++;
		}
		end++;
	}
}


void str_maxlenoc(char **av ,int n, int (*f)(char *))
{
	int i;
	int j;
	char *first;
	char **stock;
	char *ret;

	first = av[0];
	*av++;
	i = 0;
	stock = malloc(10000);
	init_stock(stock);
	printf("1\n");
	fill_stock(stock, first);
	printf("2\n");
	/*while (*av)
	{
		ret = find(ret, *av);
		av++;
	}*/
	while (*stock)
	{
		printf("%s\n",*stock);
		*stock++;
	}
	//write(1, ret, ft_strlen(ret));
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

