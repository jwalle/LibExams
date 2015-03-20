/*
	Fichiers à rendre : inter.c
	Fonctions Autorisées : write

	Écrire un programme qui prend en paramètres deux chaînes de caractères et qui af-
	fiche sans doublon les caractères communs aux deux chaînes.

	L’affichage se fera dans l’ordre d’apparition dans la premiere chaîne. L’affichage doit
	être suivi d’un ’\n’.
	
	Si le nombre de paramètres transmis est différent de 2, le programme affiche ’\n’.
*/

#include <unistd.h>

int ft_strnchr(char *s1, int n, char c)
{
	int i;

	i = 0;
	while (i < n)
	{
		if (s1[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void inter(char *s1, char *s2)
{
	int i;
	int j;

	i = 0;
	while (s1[i])
	{
		j = 0;
		while (s2[j] && s1[i])
		{
			if (s1[i] == s2[j])
			{
				if (!ft_strnchr(s1, i, s1[i]))
					write(1, &s1[i], 1);
				j = -1;
				i++;
				if (!s1[i])
					return ;
			}
			j++;
		}
		i++;
	}
}

int main(int ac, char **av)
{
	if (ac == 3)
		inter(av[1], av[2]);
	write(1, "\n", 1);
	return (0);
}
