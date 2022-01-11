#include "push_swap.h"

int	ft_is_croissant(int *tab, int y)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (i != y - 1)
	{
		if (tab[i] < tab[i + 1])
			x++;
		i++;
	}
	if (x == i)
	{
		free(tab);
		return (1);
	}
	return (0);
}

int	error(char **argv, int i)
{
	if (i == 1)
		return (0);
	while (i != 1)
	{
		if (ft_error(argv[i - 1]) == 1)
		{
			ft_putstr_fd("Error\n", 1);
			return (0);
		}
		i--;
	}
	return (1);
}

int	ft_error2(char *str)
{
	int	i;
	int	p;

	i = 0;
	p = 1;
	while (str[i] != '\0')
	{
		if (!(ft_isdigit(str[i]) || (str[i] == '-') || (str[i] == ' ')))
			return (-1);
		if (str[i] == ' ')
		{
			if (str[i + 1] == ' ')
				return (-1);
			p++;
		}
		if (str[i] == '-')
		{
			if (str[i - 1] != ' ' && i != 0)
				return (-1);
		}
		i++;
	}
	if (str[i - 1] == ' ')
		return (-1);
	return (p);
}

int	ft_error(char *str)
{
	int	i;

	i = 0;
	if (ft_isdigit(str[0]) || str[0] == '-')
		;
	else
		return (1);
	i++;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]))
			;
		else
			return (1);
		i++;
	}
	return (0);
}
