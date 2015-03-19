/*
	Fichiers à rendre : last_word.c
	Fonctions Autorisées : write

	Écrire un programme qui prend une chaîne de caractères en paramètre, et qui affiche
le dernier mot de cette chaîne, suivi d’un ’\n’.

	On appelle "mot" une portion de chaîne de caractères délimitée soit par des espaces
et/ou des tabulations, soit par le début / fin de la chaîne.

	Si le nombre de paramètres transmis est différent de 1, ou s’il n’y a aucun mot à
afficher, le programme affiche ’\n’.
 */

#include <unistd.h>

void last_word(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	i--;
	while(i > 0)
	{
		if (str[i] == ' ' || str[i] == '\t')
			break ;
		i--;
	}
	while (str[i++] != '\0')
		write(1, &str[i], 1);
}


int main(int ac, char **av)
{
	if(ac == 2)
		last_word(av[1]);
	write(1, "\n", 1);
	return (0);
}
