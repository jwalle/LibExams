/*

Fichiers à rendre : ft_range.c
Fonctions Autorisées : malloc

Écrire la fonction suivante :
int *ft_range(int start, int end);

Cette fonction doit allouer avec malloc() un tableau d’ints, le remplir avec les valeurs
(consécutives) démarrant à start et finissant à end (start et end inclus !), et renvoyer
un pointeur vers la première valeur du tableau.

Exemples :
• Avec (1, 3) vous devrez renvoyer un tableau contenant 1, 2 et 3.
• Avec (-1, 2) vous devrez renvoyer un tableau contenant -1, 0, 1 et 2.
• Avec (0, 0) vous devrez renvoyer un tableau contenant 0.
• Avec (0, -3) vous devrez renvoyer un tableau contenant 0, -1, -2 et -3.

*/

#include <stdlib.h>
//#include <stdio.h>

int *ft_range(int start, int end)
{
	int *tab;
	int size;
	int i;

	i = 0;
	size = end - start;
	tab = malloc(sizeof(int*) * size);
	while (size != -1)
	{
		tab[i] = start;
		start++;
		i++;
		size--;
	}
	return (tab);
}
/*
int main(int ac, char **av)
{
	int *tab;
	int size;


	size = atoi(av[2]) - atoi(av[1]);
	tab = ft_range(atoi(av[1]), atoi(av[2]));
	while(size != -1)
	{
		printf("%d", *tab);
		printf(" ");
		*tab++;
		size--;
	}
	printf("\n");
	return(0);
}*/
