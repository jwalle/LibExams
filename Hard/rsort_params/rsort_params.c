/*
	Fichiers à rendre : rsort_params.c
	Fonctions Autorisées : write, malloc, free

	Ecrire un programme qui prend en paramètres une ou plusieurs chaînes de caractères,
	et qui les affiche sur la sortie standard après les avoir triées dans l’ordre ASCII décroissant,
	chacune suivie d’un ’\n’.

	S’il n’y a aucun paramêtre, le programme devra afficher ’\n’.
*/

#include <stdlib.h>
#include <unistd.h>

int ft_strlen(char *s)
{
	return (*s ? ft_strlen(++s) + 1 : 0);
}

void ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
}

int ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

char *ft_strdup(char *str)
{
	int i;
	char *ret;

	i = 0;
	ret = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	while (str[i])
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

void init_list(char **list, int ac, char **av)
{
	int i;

	i = 0;
	while (i < ac)
	{
		list[i] = ft_strdup(av[i]);
		i++;
	}
}

void print_list(char **list, int ac)
{
	int i;

	i = 0;
	while (i < ac)
	{
		ft_putstr(list[i]);
		i++;
	}
}

void rsort_params(char **av, int ac)
{
	char **list;
	int i;
	int j;
	char *temp;

	list = malloc(ac);
	init_list(list, ac, av);
	i = 0;
	while (i < ac - 1)
	{
		j = 0;
		while (j < ac - i - 1)
		{
			if (ft_strcmp(list[j], list[j + 1]) < 0)
			{
				temp = list[j];
				list[j] = list[j + 1];
				list[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
	print_list(list, ac);
}

int main(int ac, char **av)
{
	if (ac == 2)
		ft_putstr(av[1]);
	if (ac > 2)
		rsort_params(av + 1, ac - 1);
	if (ac == 1)
		write(1, "\n", 1);
	return (0);
}
