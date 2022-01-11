/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redarnet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 14:08:34 by redarnet          #+#    #+#             */
/*   Updated: 2019/10/23 13:53:18 by redarnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	string_bis(char *str, int *i, int *y)
{
	while (str[*i] != ' ' && str[*i] != '\0')
	{
		*y = *y + 1;
		*i = *i + 1;
	}
	*i = *i - *y;
	return (*i);
}

int	string(char *str, int *i, int *tab, int *x)
{
	int		y;
	char	*tmp;

	y = 0;
	*i = string_bis(str, i, &y);
	tmp = malloc(sizeof(char) * y + 1);
	if (tmp == 0)
		return (0);
	y = 0;
	while (str[*i] != ' ' && str[*i] != '\0')
	{
		tmp[y] = str[*i];
		y++;
		*i = *i + 1;
	}
	tmp[y] = '\0';
	tab[*x] = ft_atoi(tmp);
	if (ft_limit(tmp) == 0)
	{
		ft_putstr_fd("Error\n", 1);
		*i = -1;
	}
	free(tmp);
	return (tab[*x]);
}

int	*ft_string(char *str, int *tab, int a)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (str[i] != '\0')
	{
		tab[x] = string(str, &i, tab, &x);
		if (i == -1)
		{
			free(tab);
			return (0);
		}
		x++;
		if (x == a)
			break ;
		i++;
	}
	return (tab);
}
