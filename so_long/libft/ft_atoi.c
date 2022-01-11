/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redarnet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 13:36:14 by redarnet          #+#    #+#             */
/*   Updated: 2019/10/22 16:19:31 by redarnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int			i;
	char		signe;
	int			n;
	int			a;

	i = 0;
	n = 0;
	a = -1;
	signe = 'p';
	while (nptr[i] == ' ' || nptr[i] == '\t' || nptr[i] == '\f'
		|| nptr[i] == '\n' || nptr[i] == '\r' || nptr[i] == '\v')
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			a = -a;
		i++;
	}
	while (nptr[i] <= '9' && nptr[i] >= '0')
	{
		n = n * 10 + nptr[i] - 48;
		i++;
	}
	return (n * -a);
}
