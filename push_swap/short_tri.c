/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_short_tri.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redarnet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 14:08:34 by redarnet          #+#    #+#             */
/*   Updated: 2019/10/23 13:53:18 by redarnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	very_short_tri(int *tab, int i)
{
	if (tab[0] > tab[1])
		ft_sa(tab, i);
}

void	short_tri(int *tab, int a)
{
	if (tab[2] > tab[0])
		if (tab[0] > tab[1])
			ft_sa(tab, a);
	if (tab[0] > tab[1])
	{
		if (tab[1] > tab[2])
		{
			ft_sa(tab, a);
			ft_rra(tab, a);
		}
	}
	if (tab[0] > tab[2])
		if (tab[2] > tab[1])
			ft_ra(tab, a);
	if (tab[1] > tab[2])
	{
		if (tab[2] > tab[0])
		{
			ft_sa(tab, a);
			ft_ra(tab, a);
		}
	}
	if (tab[1] > tab[0])
		if (tab[0] > tab[2])
			ft_rra(tab, a);
}

void	small_tri_bis(int *tab, int a)
{
	int		i;
	int		y;
	int		indice;
	int		x;

	i = 0;
	y = 0;
	indice = 0;
	x = tab[i];
	while (i != a)
	{
		if (tab[i] < x)
		{
			x = tab[i];
			indice = i;
		}
		i++;
	}
	i = 0;
	tri_bis(tab, a, indice);
}

void	small_tri(int *tab, int *tab2, int a, int b)
{
	small_tri_bis(tab, a);
	ft_pb(tab, tab2, &a, &b);
	small_tri_bis(tab, a);
	ft_pb(tab, tab2, &a, &b);
	short_tri(tab, a);
	ft_pa(tab, tab2, &a, &b);
	ft_pa(tab, tab2, &a, &b);
}

void	small_tri4(int *tab, int *tab2, int a, int b)
{
	small_tri_bis(tab, a);
	ft_pb(tab, tab2, &a, &b);
	short_tri(tab, a);
	ft_pa(tab, tab2, &a, &b);
	ft_pa(tab, tab2, &a, &b);
}
