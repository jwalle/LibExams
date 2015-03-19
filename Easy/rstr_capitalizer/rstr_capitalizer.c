/*
	Fichiers à rendre : rstr_capitalizer.c
	Fonctions Autorisées : write

	Ecrire un programme qui prend en paramètre une ou plusieurs chaînes de caractères,
	et qui, pour chaque argument, met la dernière lettre de chaque mot en majuscule et le
	reste en minuscule, et affiche le résultat sur la sortie standard suivi d’un ’\n’.

	On appelle "mot" une portion de chaîne de caractères délimitée soit par des espaces
	et/ou des tabulations, soit par le début / fin de la chaîne. Si un mot a une seule lettre,
	elle devra être mise en majuscule.

	S’il n’y a aucun paramêtre, le programme devra afficher ’\n’.
*/

# include <unistd.h>
void ft_putstr(char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int ft_isalpha(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	if (c >= 'A' && c <= 'Z')
		return (2);
	return (0);
}

void capital(char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		if (ft_isalpha(str[i]))
		{
			if (ft_isalpha(str[i]) == 2)
				str[i] = str[i] + ' ';
			if (str[i + 1] == ' ' || str[i + 1] == '\t' || str[i + 1] == '\0')
			{
				if (ft_isalpha(str[i]) == 1)
					str[i] = str[i] - ' ';
			}
		}
		i++;
	}
	ft_putstr(str);
}


int main(int ac, char **av)
{
	int i;

	i = 1;
	if (ac > 1)
	{
		while (i < ac)
		{
			capital(av[i]);
			write (1, "\n", 1);
			i++;
		}
	}
	else
		write (1, "\n", 1);
}
