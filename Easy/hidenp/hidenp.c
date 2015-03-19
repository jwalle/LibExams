/*
Fichiers à rendre : hidenp.c
Fonctions Autorisées : write

Écrire un programme nommé "hidenp" qui prend en paramètres deux chaînes de ca-
ractères et qui affiche 1 suivi de ’\n’ si la chaîne du premier paramètre est cachée dans
la deuxième chaîne. Sinon il affiche 0 suivi de ’\n’.

Soit s1 et s2 des chaînes de caractères. On dit que la chaîne s1 est cachée dans la chaîne
s2 si on peut trouver chaque caractère de s1 dans s2 et ce dans le même ordre que dans s1.

Si le nombre de paramètres transmis est différent de 2, le programme affiche ’\n’.
*/

#include <unistd.h>

int ft_strlen(char *s1)
{
	int i;

	i = 0;
	while (s1[i])
		i++;
	return (i);
}

int hidenp(char *s1, char *s2)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s2[j])
	{
		if (s2[j] == s1[i])
			i++;
		if (i == ft_strlen(s1))
			return (1);
		j++;
	}
	return (0);
}


int main(int ac, char **av)
{
	if (ac == 3)
	{
		if (hidenp(av[1], av[2]) == 1)
			write(1, "1", 1);
		else
			write(1, "0", 1);
	}
	write(1, "\n", 1);
}
