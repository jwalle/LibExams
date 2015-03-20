/*
	Fichiers à rendre : fprime.c
	Fonctions Autorisées : printf, atoi

	Écrire un programme qui prend en paramètre un entier strictement positif, et qui
	affiche sa décomposition en facteurs premiers sur la sortie standard, suivie d’un ’\n’.

	Les facteurs doivent être affichés dans l’ordre croissant et séparés par des ’*’, de telle
	sorte que l’expression affichée donne le bon résultat.

	Si le nombre de paramètres est différent de 1, le programme doit afficher ’\n’.

	L’entrée, quand elle est passée, sera toujours un nombre valide sans caractères para-
	sites.
*/

# include <stdlib.h>
# include <stdio.h>

int is_prime(int i)
{
	int j;

	j = 2;
	while(i > j)
	{
		if (i % j == 0)
			return (0);
		j++;
	}
	return (1);
}

void fprime(int ent)
{
	int i;

	i = 2;
	if (ent == 1)
		printf("1");
	if (ent == 0)
		printf("0");
	while (i <= ent)
	{
		if (is_prime(ent))
		{
			printf("%d", ent);
			return ;
		}
		if (is_prime(i) && ((ent % i) == 0))
		{
			printf("%d*", i);
			ent = (ent / i);
			i = 1;
		}
		i++;
	}
}

int main(int ac, char **av)
{
	if (ac == 2)
		fprime(atoi(av[1]));
	printf("\n");
	return (0);
}
