/* blabla */

#include <stdlib.h>
//#include <stdio.h>

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return(i);
}

char *ft_strdup(char *str)
{
	char *ret;
	int i;

	i = 0;
	if ((ret = (char *)malloc(sizeof(char) * ft_strlen(str) + 1)) == NULL)
		return (NULL);
	while (str[i])
	{
		ret[i] = str[i];
		i++;
	}
	return(ret);
}
/*
int main(int ac, char **av)
{
	char *str;

	if (ac == 2)
	{
		str = ft_strdup(av[1]);
		printf("%s\n", str);
	}
	return(0);
}*/
