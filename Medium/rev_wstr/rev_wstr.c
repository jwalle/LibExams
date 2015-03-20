

#include <unistd.h>

int		is_space(char c)
{
	if (c == '\t' || c == ' ')
		return (1);
	return (0);
}

int		ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putnstr(char *s, int n)
{
	int i;

	i = 0;
	while(is_space(s[i]))
		i++;
		
	while (i < n)
	{
		write(1, &s[i], 1);
		i++;
	}
}

void	rev_wstr(char *s)
{
	int i;
	int k;
	int word;

	word = 0;
	k = -1;
	i = ft_strlen(s);
	while(i >= 0)
	{
		k++;
		if (is_space(s[i]) || i == 0)
		{
			if (!word)
			{
				ft_putnstr(&s[i], k);
				if (i != 0)
					write(1, " ", 1);
			}
			else if (i != 0 && word > 0)
			{
				ft_putnstr(&s[i + 1], k);
				write(1, " ", 1);
			}
			else
				ft_putnstr(&s[i], k + 1);

			k = 0;
			i--;
			word++;
		}
		i--;
	}
}

int main(int ac, char **av)
{
	if (ac == 2)
		rev_wstr(av[1]);
	write(1, "\n", 1);
	return (0);
}
