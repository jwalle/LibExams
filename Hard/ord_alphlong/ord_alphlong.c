/*
	Fichiers à rendre : *.c, *.h
	Fonctions Autorisées : write, malloc, free

	Écrire un programme qui prend en paramètre une chaine de caractères et qui affiche
	les mots de cette chaine par ordre de longueur puis dans l’ordre ascii. Les majuscules et
	minuscules sont identiques dans l’ordre alphabetique (bien regarder les exemples). En cas
	d’égalité alphabetique (ex aA et Aa) les mots doivent rester dans l’ordre ou ils etaient
	dans la chaine d’origine (second exemple). En cas de doublons, les doublons sont conserves
	(dernier exemple).

	Si le nombre de paramètres transmis est différent de 1, le programme affiche ’\n’.

	Dans les chaines, il n’y aura que des espaces, des tabulations et des caractères alpha-
	numeriques.

	Vous n’afficherez qu’un espace entre les mots. Aucun avant le premier ni après le der-
	nier de chaque ligne.
*/

#include <stdlib.h>
#include <unistd.h>

int ft_strlen(char *s)
{
	return(*s ? ft_strlen(++s) + 1 : 0);
}

void ft_putstr(char *s)
{
	write(1, s, ft_strlen(s));
}

int ft_strcmp(char *s1, char *s2)
{
	if (!s1 || !s2)
		return (0);
	while (*s1 == *s2 || *s1 == *s2 + ' ' || *s1 == *s2 - ' ')
	{
		*s1++;
		*s2++;
		if (!*s1 || !*s2)
			return (*s1 - *s2);
	}
	return (*s1 - *s2);
}

int ft_isspace(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

char *ft_strnndup(char *str, int start, int end)
{
	char *ret;
	int i;
	int j;

	j =0;
	i = start;
	ret = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	while (str[i] && i < end)
	{
		ret[j] = str[i];
		i++;
		j++;
	}
	ret[j] = '\0';
	return (ret);
}

void init_list(char **list)
{
	int i;

	i = 0;
	while(i < 100)
	{
		list[i] = (char *)malloc(1000);
		i++;
	}
}

void destroy_list(char **list)
{
	int i;

	i = 0;
	while(i < 100)
	{
		free(list[i]);
		i++;
	}
}

void ft_capital(char *str)
{
	int i;

	i  = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] - ' ';
		i++;
	}
}

void ft_sort(char **list, int n)
{
	int i;
	int j;
	char *temp;
	char *s1;
	char *s2;

	i = 0;
	while (i < (n - 1))
	{
		j = 0;
		while (j < (n - 1 - i))
		{
			s1 = ft_strnndup(list[j], 0, ft_strlen(list[j]));
			s2 = ft_strnndup(list[j + 1], 0, ft_strlen(list[j + 1]));
			ft_capital(s1);
			ft_capital(s2);
			if (ft_strcmp(s1, s2) > 0)
			{
				temp = list[j + 1];
				list[j + 1] = list[j];
				list[j] = temp;
			}
			j++;
		}
		i++;
	}
}

void print_list(char **list, int n)
{
	int i;
	int max;
	int flag;
	int j;

	j = 1;
	i = 0;
	flag = 0;
	max = 1;
	while (i < n)
	{
		if (ft_strlen(list[i]) > max)
			max = ft_strlen(list[i]);
		i++;
	}
	i = 0;
	while (j <= max)
	{
		i = 0;
		if (flag)
			write(1, "\n", 1);
		flag = 0;
		while(i < n)
		{
			if (ft_strlen(list[i]) == j)
			{
				if (flag)
					write(1, " ", 1);
				ft_putstr(list[i]);
				flag++;
			}
			i++;
		}
		j++;
	}
}

void ord_alphalong(char *str)
{
	char **list;
	int i;
	int k;
	int j;
	int start;
	int end;

	k = ft_strlen(str);
	list = malloc(100);
	init_list(list);
	j = 0;
	i = 0;
	while (i < k)
	{
		if (!ft_isspace(str[i]) && i < k)
		{
			start = i;
			end = i;
			while (!ft_isspace(str[end]) && end < k)
				end++;
			list[j] = ft_strnndup(str, start, end);
			j++;
			i = end;
		}
		i++;
	}
	ft_sort(list, j);
	print_list(list, j);
	destroy_list(list);
}

int main(int ac, char **av)
{
	if (ac == 2)
		ord_alphalong(av[1]);
	write(1, "\n", 1);
	return (0);
}
