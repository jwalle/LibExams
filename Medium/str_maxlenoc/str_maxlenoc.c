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

void str_maxlenoc(char **av ,int n)
{
	int i;
	int j;
	char *ret;

	ret = av[0];
	*av++;
	while (*av)
	{

	}
}

int main(int ac, char **av)
{
	if (ac > 1)
		str_maxlenoc(av + 1, ac - 1);
	write(1, "\n", 1);
	return (0);
}

