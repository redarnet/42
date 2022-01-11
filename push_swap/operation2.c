/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redarnet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 14:08:34 by redarnet          #+#    #+#             */
/*   Updated: 2019/10/23 13:53:18 by redarnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pa_bis(int *a, int *tab, int tmp, int *y)
{
	int	tmp2;

	if (*a == 0)
		tab[*a] = tmp;
	else
	{
		while (*y != *a)
		{
			tmp2 = tab[*y];
			tab[*y] = tmp;
			tmp = tmp2;
			*y = *y + 1;
		}
		tab[*y] = tmp;
	}
}

void	ft_pa(int *tab, int *tab2, int *a, int *b)
{
	int	i;
	int	y;
	int	tmp;

	i = 0;
	y = 0;
	if (*b == 0)
		return ;
	if (*b > 0)
	{
		tmp = tab2[i];
		while (i != *b)
		{
			tab2[i] = tab2[i + 1];
			i++;
		}
		ft_pa_bis(a, tab, tmp, &y);
		*b = *b - 1;
		*a = *a + 1;
	}
	ft_putstr_fd("pa\n", 1);
}

void	ft_pb_bis(int *b, int *tab2, int tmp, int *y)
{
	int	tmp2;

	if (*b == 0)
		tab2[*b] = tmp;
	else
	{
		while (*y != *b)
		{
			tmp2 = tab2[*y];
			tab2[*y] = tmp;
			tmp = tmp2;
			*y = *y + 1;
		}
		tab2[*y] = tmp;
	}
}

void	ft_pb(int *tab, int *tab2, int *a, int *b)
{
	int	i;
	int	y;
	int	tmp;

	if (*a == 0)
		return ;
	i = 0;
	y = 0;
	if (*a > 0)
	{
		tmp = tab[i];
		while (i != *a)
		{
			tab[i] = tab[i + 1];
			i++;
		}
		ft_pb_bis(b, tab2, tmp, &y);
		*b = *b + 1;
		*a = *a - 1;
	}
	ft_putstr_fd("pb\n", 1);
}
