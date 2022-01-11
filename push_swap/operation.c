/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redarnet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 14:08:34 by redarnet          #+#    #+#             */
/*   Updated: 2019/10/23 13:53:18 by redarnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(int *tab, int a)
{
	int	tmp;

	if (a == 0)
		return ;
	if (a == 1)
		return ;
	if (a > 1)
	{
		tmp = tab[0];
		tab[0] = tab[1];
		tab[1] = tmp;
	}
	ft_putstr_fd("sa\n", 1);
}

void	ft_ra(int *tab, int a)
{
	int	tmp;
	int	i;

	i = 0;
	if (a == 0)
		return ;
	if (a == 1)
		return ;
	if (a > 1)
	{
		tmp = tab[0];
		while (i != a)
		{
			tab[i] = tab[i + 1];
			i++;
		}
		tab[i - 1] = tmp;
	}
	ft_putstr_fd("ra\n", 1);
}

void	ft_rb(int *tab2, int b)
{
	int	tmp;
	int	i;

	i = 0;
	if (b == 0)
		return ;
	if (b == 1)
		return ;
	if (b > 1)
	{
		tmp = tab2[0];
		while (i != b)
		{
			tab2[i] = tab2[i + 1];
			i++;
		}
		tab2[i - 1] = tmp;
	}
	ft_putstr_fd("rb\n", 1);
}

void	ft_rrb(int *tab2, int b)
{
	int	tmp;
	int	i;

	i = b;
	if (b == 0)
		return ;
	if (b == 1)
		return ;
	if (b > 1)
	{
		tmp = tab2[b - 1];
		while (i != 0)
		{
			tab2[i] = tab2[i - 1];
			i--;
		}
		tab2[i] = tmp;
	}
	ft_putstr_fd("rrb\n", 1);
}

void	ft_rra(int *tab, int a)
{
	int	tmp;
	int	i;

	i = a;
	if (a == 0)
		return ;
	if (a == 1)
		return ;
	if (a > 1)
	{
		tmp = tab[a - 1];
		while (i != 0)
		{
			tab[i] = tab[i - 1];
			i--;
		}
		tab[i] = tmp;
	}
	ft_putstr_fd("rra\n", 1);
}
