/*
	Fichiers à rendre : ulstr.c
	Fonctions Autorisées : write

	Ecrire un programme qui prend en paramètre une chaine de caractères, et qui trans-
	forme toutes les minuscules en majuscules et toutes les majuscules en minuscules. Les
	autres caractères restent inchangés.

	Vous devez afficher le résultat suivi d’un ’\n’.

	Si le nombre de paramètres transmis est différent de 1, le programme affiche ’\n’.
*/

#include <unistd.h>

void ulstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] - ' ';
		else if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + ' ';
		write(1, &str[i], 1);
	i++;
	}
}

int main(int ac, char **av)
{
	if (ac == 2)
		ulstr(av[1]);
	write(1, "\n", 1);
	return (0);
}
