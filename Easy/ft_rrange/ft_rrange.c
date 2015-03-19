/*

Fichiers à rendre : ft_rrange.c
Fonctions Autorisées : malloc

Écrire la fonction suivante :
int *ft_rrange(int start, int end);

Cette fonction doit allouer avec malloc() un tableau d’ints, le remplir avec les valeurs
(consécutives) démarrant à end et finissant à start (start et end inclus !), et renvoyer
un pointeur vers la première valeur du tableau.

Exemples :
• Avec (1, 3) vous devrez renvoyer un tableau contenant 3, 2, 1.
• Avec (-1, 2) vous devrez renvoyer un tableau contenant 2, 1, 0, -1.
• Avec (0, 0) vous devrez renvoyer un tableau contenant 0.
• Avec (0, -3) vous devrez renvoyer un tableau contenant -3, -2, -1, 0.

*/

#include <stdlib.h>
//#include <stdio.h>

int *ft_rrange(int start, int end)
{
	int *tab;
	int size;
	int i;

	i = 0;
	size = end - start;
	tab = malloc(sizeof(int*) * size);
	while (size != -1)
	{
		tab[i] = end;
		end--;
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
	tab = ft_rrange(atoi(av[1]), atoi(av[2]));
	while(size != -1)
	{
		printf("%d", *tab);
		printf(" ");
		*tab++;
		size--;
	}
	printf("\n");
	return(0);
}
*/
