/*
	Fichiers à rendre : union.c
	Fonctions Autorisées : write

	Écrire un programme qui prend en paramètre deux chaînes de caractères et qui affiche
	sans doublon les caractères qui apparaissent dans l’une ou dans l’autre.
	
	L’affichage se fera dans l’ordre d’apparition dans la ligne de commande.

	L’affichage doit etre suivi d’un retour à la ligne.

	Si le nombre de paramètres transmis est différent de 2, le programme affiche ’\n’.
*/

#include <unistd.h>

int ft_strlen(char *str)
{
	return (*str ? ft_strlen(++str) + 1 : 0);
}

int ft_strnchr(char *str, char c, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void  ft_union(char *s1, char *s2, int (*f)(char *))
{
	int i;

	i = 0;
	while(s1[i])
	{
		if (!ft_strnchr(s1, s1[i], i))
			write(1, &s1[i], 1);
		i++;
	}
	i = 0;
	while (s2[i])
	{
		if (!ft_strnchr(s1, s2[i], f(s1)) && !ft_strnchr(s2, s2[i], i))
			write(1, &s2[i], 1);
		i++;
	}
}

int main(int ac, char **av)
{
	int (*f)(char*);

	f = &ft_strlen;
	if (ac == 3)
		ft_union(av[1], av[2], f);
	write(1, "\n", 1);
	return (0);
}
