/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redarnet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 14:08:34 by redarnet          #+#    #+#             */
/*   Updated: 2019/10/23 13:53:18 by redarnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_same_num(int *tab, int a)
{
	int	i;
	int	y;
	int	x;

	i = 0;
	y = 0;
	while (i != a)
	{
		x = tab[i];
		y = i + 1;
		while (y != a)
		{
			if (tab[y] == x)
			{
				ft_putstr_fd("Error\n", 1);
				free(tab);
				return (1);
			}
			y++;
		}
		i++;
	}
	return (0);
}

void	algo_bis1(int *tab, int *tab2, int argc)
{
	int	i;
	int	*tab3;
	int	y;

	i = 0;
	y = 0;
	tab3 = change_num(tab, argc - 1, y);
	while (i != argc - 1)
	{
		tab[i] = tab3[i];
		i++;
	}
	long_tri(tab, tab2, argc - 1, 0);
	free(tab3);
}

void	algo_bis(int *tab, int *tab2, int argc)
{
	int	i;
	int	*tab3;
	int	y;

	i = 0;
	y = 0;
	tab3 = change_num(tab, argc - 1, y);
	while (i != argc - 1)
	{
		tab[i] = tab3[i];
		i++;
	}
	very_long_tri(tab, tab2, argc - 1, 0);
	free(tab3);
}

void	algo(int *tab, int argc)
{
	int	*tab2;

	tab2 = malloc(sizeof(int) * argc);
	if (argc == 3)
		very_short_tri(tab, argc - 1);
	else if (argc < 5)
		short_tri(tab, argc - 1);
	else if (argc == 5)
		small_tri4(tab, tab2, argc - 1, 0);
	else if (argc == 6 )
		small_tri(tab, tab2, argc - 1, 0);
	else if (argc < 102)
		algo_bis1(tab, tab2, argc);
	else
		algo_bis(tab, tab2, argc);
	free(tab2);
}
