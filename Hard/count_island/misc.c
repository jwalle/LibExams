/*----- HEADER -----*/

#include "count_island.h"

char *ft_strsub(char *s, int i)
{
	char *ret;
	int j;

	j = -1;
	ret = malloc(i + 1);
	while(i > ++j)
		ret[j] = s[j];
	return (ret);
}

char *ft_strjoin(char *s1, char *s2)
{
	int i;
	int j;
	int s1len;
	int s2len;
	char *ret;

	i = -1;
	j = -1;
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	ret = malloc(s1len + s2len + 1);
	while(s1[++i])
		ret[i] = s1[i];
	while (s2[++j])
		ret[i + j] = s2[j];
	ret[j + i] = '\0';
	return(ret);
}

char *ft_strnew(int i)
{
	char *s;

	s =  malloc(i);
	while(i)
	{
		s = '\0';
		++s;
	}
	return(s);
}


char *ft_strdup(char *s)
{
	char *ret;
	int  i;

	i = 0;
	ret = malloc(ft_strlen(s) + 1);
	while(s[i])
	{
		ret[i] = s[i];
		i++;
	}
	ret[i] = '\0';
	return(ret);
}

int ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return(i);
}

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putstr(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
}
