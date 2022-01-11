/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long_tri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redarnet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 14:08:34 by redarnet          #+#    #+#             */
/*   Updated: 2019/10/23 13:53:18 by redarnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_hold_first1(int *tab, int a, int hold_first, int x)
{
	int	y;

	y = 0;
	hold_first = 0;
	while (y != a)
	{
		if (tab[y] <= (19 + x) && tab[y] >= (0 + x))
		{
			hold_first = y;
			break ;
		}
		y++;
	}
	return (hold_first);
}

int	ft_hold_second1(int *tab, int i, int x)
{
	int	hold_second;

	hold_second = 0;
	while (i != 0)
	{
		if (tab[i] <= (19 + x) && tab[i] >= (0 + x))
			break ;
		hold_second++;
		i--;
	}
	return (hold_second);
}

void	push_a(int *tab, int *tab2, int *a, int *b)
{
	int	i;
	int	indice;

	indice = push_a_bis(tab2, b);
	i = 0;
	if (indice > *b / 2 )
	{
		while (i != (*b - indice))
		{
			ft_rrb(tab2, *b);
			i++;
		}
		ft_pa(tab, tab2, a, b);
	}
	else
	{
		while (i != indice)
		{
			ft_rb(tab2, *b);
			i++;
		}
		ft_pa(tab, tab2, a, b);
	}
}

void	push_b(int *tab, int *tab2, t_data *data, int x)
{
	int	i;
	int	hold_first;
	int	hold_second;

	if (data->a > 1)
		i = data->a - 1;
	else
		i = 0;
	hold_first = ft_hold_first1(tab, data->a, 0, x);
	hold_second = ft_hold_second1(tab, i, x);
	i = 0;
	if (hold_first <= hold_second)
		push_hold_first(tab, tab2, data, hold_first);
	else if (hold_second < hold_first)
	{
		while (i != hold_second + 1)
		{
			ft_rra(tab, data->a);
			i++;
		}
		ft_pb(tab, tab2, &data->a, &data->b);
	}
	else
		ft_pb(tab, tab2, &data->a, &data->b);
}

void	long_tri(int *tab, int *tab2, int a, int b)
{
	int		i;
	int		y;
	int		x;
	t_data	data;

	x = 0;
	data.a = a;
	data.b = b;
	y = 0;
	while (y != 5)
	{
		i = 0;
		while (i != 20)
		{
			push_b(tab, tab2, &data, x);
			i++;
		}
		y++;
		x = x + 20;
	}
	i = 0;
	push_to_a(tab, tab2, data);
}
