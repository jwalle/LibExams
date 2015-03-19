/*
	Fichiers à rendre : wdmatch.c
	Fonctions Autorisées : write

	Le programme prend en paramètres deux chaines de caractères et vérifie qu’il est
	possible d’écrire la première chaine de caractères a l’aide des caractères de la deuxiême
	chaine, tout en respectant l’ordre des caractères dans la deuxième chaine.

	Si cela est possible, le programme affiche la première chaine de caractères suivi de
	’\n’. Sinon le programme affiche seulement ’\n’.

	Si le nombre de paramètres transmis est différent de 2, le programme affiche ’\n’.
*/

# include <unistd.h>

int ft_strlen(char *s)
{
	int i;

	i = 0;
	while (*s++)
		i++;
	return (i);
}

void ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
}

void wdmatch(char *s1, char *s2)
{
	int i;

	i = 0;	
	while (*s2 && s1[i])
	{
		if (*s2 == s1[i])
			i++;
		*s2++;
	}
	if (i == ft_strlen(s1))
		ft_putstr(s1);
}

int main(int ac, char **av)
{
	if (ac == 3)
		wdmatch(av[1], av[2]);
	write(1, "\n", 1);
	return (0);
}
