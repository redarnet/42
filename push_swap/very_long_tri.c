#include "push_swap.h"

int	ft_hold_first(int *tab, int a, int x)
{
	int	y;
	int	hold_first;

	hold_first = 0;
	y = 0;
	while (y != a)
	{
		if (tab[y] <= (49 + x) && tab[y] >= (0 + x))
		{
			hold_first = y;
			break ;
		}
		y++;
	}
	return (hold_first);
}

int	push_b_long_bis(int *tab, int a, int x, int *hold_second)
{
	int	i;
	int	hold_first;
	int	y;

	if (a > 1)
		i = a - 1;
	else
		i = 0;
	y = 0;
	while (i != 0)
	{
		if (tab[i] <= (49 + x) && tab[i] >= (0 + x))
		{
			*hold_second = y;
			break ;
		}
		y++;
		i--;
	}
	hold_first = ft_hold_first(tab, a, x);
	return (hold_first);
}

void	push_hold_first(int *tab, int *tab2, t_data *data, int hold_first)
{
	int	i;

	i = 0;
	while (i != hold_first)
	{
		ft_ra(tab, data->a);
		i++;
	}
	ft_pb(tab, tab2, &data->a, &data->b);
}

int	chunk(int a)
{
	int	p;

	if (a <= 500)
		p = 10;
	else
		p = a / 40;
	return (p);
}

void	very_long_tri(int *tab, int *tab2, int a, int b)
{
	int		i;
	int		y;
	int		x;
	int		p;
	t_data	data;

	x = 0;
	data.a = a;
	data.b = b;
	y = 0;
	p = chunk(a);
	while (y != p)
	{
		i = 0;
		while (i != 50)
		{
			push_b_long(tab, tab2, &data, x);
			i++;
		}
		y++;
		x = x + 50;
	}
	push_to_a(tab, tab2, data);
}
