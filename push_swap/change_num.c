/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_change_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redarnet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 14:08:34 by redarnet          #+#    #+#             */
/*   Updated: 2019/10/23 13:53:18 by redarnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	change_num_bis(int *tab, long int *a, int *i, int compt)
{
	int	indice;
	int	x;

	while (tab[*i] <= *a)
		*i = *i + 1;
	x = tab[*i];
	while (*i != compt)
	{
		if (tab[*i] <= x)
		{
			if (tab[*i] > *a)
			{
				x = tab[*i];
				indice = *i;
			}
		}
		*i = *i + 1;
	}
	*a = x;
	return (indice);
}

int	*change_num(int *tab, int compt, int y)
{
	int			i;
	int			*result;
	int			indice;
	long int	a;

	result = malloc(sizeof(int) * compt + 1);
	indice = 0;
	a = -2147483649;
	while (y != compt)
	{
		i = 0;
		indice = change_num_bis(tab, &a, &i, compt);
		result[indice] = y;
		y++;
	}
	return (result);
}
