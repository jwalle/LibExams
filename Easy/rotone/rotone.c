/*

	Fichiers à rendre : rotone.c
	Fonctions Autorisées : write

	Écrire un programme nommé "rotone" qui prend en paramètre une chaîne de caractères
	et qui affiche cette chaîne en remplaçant chaque caractère alphabétique par le caractère
	suivant dans l’ordre alphabétique.
	
	’z’ devient ’a’ et ’Z’ devient ’A’. Les majuscules restent des majuscules et les minus-
	cules restent des minuscules.
	
	L’affichage se termine toujours par un retour à la ligne.
	
	Si le nombre de paramètres transmis est différent de 1, le programme affiche ’\n’.

*/

# include <unistd.h>

void rotate(char c)
{
	if (c == 'z')
		write(1, "a", 1);
	if (c == 'Z')
		write(1, "A", 1);
	if ((c >= 'A' && c < 'Z') || (c >= 'a' && c < 'z'))
	{
		c = c + 1;
		write(1, &c, 1);
	}
}

void rotone(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		rotate(str[i]);
		i++;
	}
}


int main(int ac, char **av)
{
	if (ac == 2)
		rotone(av[1]);
	write(1, "\n", 1);
	return (0);
}
