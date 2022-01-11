/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redarnet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 14:08:34 by redarnet          #+#    #+#             */
/*   Updated: 2019/10/23 13:53:18 by redarnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_limit(char *str)
{
	if (str[0] != '-')
	{
		if (ft_strlen(str) > 10)
			return (0);
		if (ft_strlen(str) == 10)
		{
			if (str[0] > '2' || str[1] > '1' || str[2] > '4'
				|| str[3] > '7' || str[4] > '4' || str[5] > '8'
				|| str[6] > '3' || str[7] > '6' || str[8] > '4' || str[9] > '7')
				return (0);
		}
	}
	else
	{
		if (ft_strlen(str) > 11)
			return (0);
		if (ft_strlen(str) == 11)
		{
			if (str[1] > '2' || str[2] > '1' || str[3] > '4' || str[4]
				> '7' || str[5] > '4' || str[6] > '8' || str[7]
				> '3' || str[8] > '6' || str[9] > '4' || str[10] > '8' )
				return (0);
		}
	}
	return (1);
}

void	tri_bis(int *tab, int a, int indice)
{
	int	i;

	i = 0;
	if (indice == a - 1)
		ft_rra(tab, a);
	else if (indice == a - 2)
	{
		ft_rra(tab, a);
		ft_rra(tab, a);
	}
	else
	{
		while (i != indice)
		{
			ft_ra(tab, a);
			i++;
		}
	}
}

void	push_b_long(int *tab, int *tab2, t_data *data, int x)
{
	int	hold_first;
	int	hold_second;
	int	i;

	hold_second = 0;
	i = 0;
	hold_first = push_b_long_bis(tab, data->a, x, &hold_second);
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

void	push_to_a(int *tab, int *tab2, t_data data)
{
	int	i;

	i = 0;
	while (i != data.a + 1)
	{
		push_a(tab, tab2, &data.a, &data.b);
		i++;
	}
}

int	push_a_bis(int *tab2, int *b)
{
	int	indice;
	int	i;
	int	x;

	indice = 0;
	i = 0;
	x = tab2[i];
	while (i != *b)
	{
		if (tab2[i] > x)
		{
			x = tab2[i];
			indice = i;
		}
		i++;
	}
	return (indice);
}
