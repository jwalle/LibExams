/* --- HEADER --- */

#include "count_island.h"

void    ft_cpy(char *line, char **array)
{
	int i;
	int k;

	k = 0;
	i = 0;
	while (line[i])
	{
		while(line[i] != '\n' && line[i])
			i++;
		array[k] = ft_strsub(line, i);
		line = &line[i];
		k++;
	}
	array[k][i] = '\0';
}

void  print_island(char **array)
{
	int i;
	
	i = 0;
	while (array[i])
	{
		ft_putstr(array[i]);
		i++;
	}
}

char  *next_line(char *s, char *lines)
{
	int fd;
	int flag;
	int j;
	char *buf;

	flag = 0;
	buf = malloc(1024);
	fd = open(s, O_RDONLY);
	while ((j = read(fd, buf, 10)) > 0)
	{
		buf[j] = '\0';
		if (!flag)
		{
			lines = ft_strdup(buf);
			flag++;
		}
		else
			lines = ft_strjoin(lines, buf);
	}
	return(lines);
}

char	**build_array(void)
{
	char **array = malloc(sizeof(char *) * 256);
	int i;

	i = 0;
	while  (i < 256)
	{
		array[i] = malloc(1024 + 1);
		i++;
	}
	return (array);
}

int  is_number(char s)
{
	if (s >= '0' && s <= '9')
		return (1);
	return(0);
}

int  what_number(char s)
{
	ft_putstr("plop");
	if (is_number(s))
		return(s - '0');
	return (-1);
}

void ft_fill(char **array, int count, int i, int j)
{

	if (array[i][j] == 'X')
	{
		array[i][j] = count + '0';
		ft_fill(array, count, i, j + 1);
		ft_fill(array, count, i + 1, j);
		if (array[i][j - 1] == 'X')
			ft_fill(array, count, i, j - 1);
		if (i > 0 && array[i - 1][j] == 'X')
			ft_fill(array, count, i - 1, j);
	}
}

void   ft_numbers(char **array)
{
	int i;
	int k;
	int count;
	int len;

	len = ft_strlen(array[0]) + 1;
	k = -1;
	count = 0;
	while (array[++k])
	{
		i = 0;
		while(i < len)
		{
			if (array[k][i] == 'X')
			{
				ft_fill(array, count, k, i);
				count++;
			}
			i++;
		}
	}
}

int main(int ac, char **av)
{
	char *lines;
	char **array = build_array();
	
	lines = malloc(1024);
	if (ac == 2)
	{
		lines = next_line(av[1], lines);
		ft_cpy(lines, array);
		ft_numbers(array);
		print_island(array);
	}
	else
		ft_putchar('\n');
	return(0);
}
