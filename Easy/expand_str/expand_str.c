/*
sujet : 

	Fichier : expand_str.c
	Fonction : write

	Ecrire un programme qui prend une chaine de caracteres en parametre, 
	et qui affiche cette chaine avec exactement trois espace entre chaque mots, 
	sans espaces ou tabulation ni au d2but ni a la fin de la chaine, suivie d'un '\n';

	On appelle "mot" une portion de chaîne de caractères délimitée soit par des espaces
et/ou des tabulations, soit par le début / fin de la chaîne.

	Si le nombre de paramètres transmis est différent de 1, ou s’il n’y a aucun mot à
afficher, le programme affiche ’\n’.

*/

# include <unistd.h>

void ft_putstr(char *str)
{
	int i;

	i = -1;
	while (str[++i])
		write(1, &str[i], 1);
}

int is_space(char c)
{
	if (c == '\n' || c == '\t' || c == ' ')
		return (1);
	else
		return (0);
}

void expand_str(char *av)
{
	int i;

	i = 0;
	while (av[i])
	{
		while (!is_space(av[i]) && av[i])
		{
			write(1, &av[i], 1);
			i++;
		}
		while (is_space(av[i]) && av[i])
		{
			i++;
			if (!is_space(av[i]) && av[i])
				ft_putstr("   ");

		}
	}
}

int main(int ac, char **av)
{
	if (ac == 2)
		expand_str(av[1]);
	write(1, "\n", 1);
}
