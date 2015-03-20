/*

	Fichiers à rendre : sort_int_tab.c
	Fonctions Autorisées :

	Écrire la fonction suivante : void sort_int_tab(int *tab, unsigned int size);

	Cette fonction doit trier (en place !) le tableau d’ints tab, qui contient exactement
	size entrées, dans l’ordre croissant.

	Les doublons doivent être préservés.

	Les entrées seront toujours cohérentes.

*/
# include <stdio.h>

void sort_int_tab(int *tab, unsigned int size)
{
	int i;
	int j;
	int temp;

	i = 0;
	while (size > i)
	{
		j = 0;
		while (size - i - 1 > j)
		{
			if (tab[j + 1] < tab[j])
			{
				temp = tab[j + 1];
				tab[j + 1] = tab[j];
				tab[j] = temp;
			}
			j++;
		}
		i++;
	}
}

int main()
{
	int tab[7] = {12, 4, 6, 43, 2, 542, 8};
	int i = 0;
	
	sort_int_tab(tab, 7);
	while (i < 7)
	{
		printf("%d ", tab[i]);
		i++;
	}
	printf("\n");
	return (0);
}
