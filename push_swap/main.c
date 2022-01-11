/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redarnet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 14:08:34 by redarnet          #+#    #+#             */
/*   Updated: 2019/10/23 13:53:18 by redarnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	part_string(int *tab, char **argv, int argc)
{
	int	i;

	i = ft_error2(argv[1]);
	if (i == -1)
	{
		ft_putstr_fd("Error\n", 1);
		return (0);
	}
	tab = malloc(sizeof(int) * (i + 1));
	if (tab == 0)
		return (0);
	tab = ft_string(argv[1], tab, i);
	if (tab == 0)
		return (0);
	argc = i + 1;
	if (ft_same_num(tab, argc - 1) == 1)
		return (0);
	if (ft_is_croissant(tab, argc - 1) == 1)
		return (0);
	algo(tab, argc);
	free(tab);
	return (1);
}

int	part_arg(char **argv, int argc, int *tab, int i)
{
	if (error(argv, argc) == 0)
		return (0);
	tab = malloc(sizeof(int) * argc);
	if (tab == 0)
		return (0);
	i = 0;
	while (i != argc - 1)
	{
		tab[i] = ft_atoi(argv[i + 1]);
		if (ft_limit(argv[i + 1]) == 0)
		{
			ft_putstr_fd("Error\n", 1);
			free(tab);
			return (0);
		}
		i++;
	}
	if (ft_same_num(tab, argc - 1) == 1)
		return (0);
	if (ft_is_croissant(tab, argc - 1) == 1)
		return (0);
	algo(tab, argc);
	free(tab);
	return (1);
}

int	main(int argc, char **argv)
{
	int	*tab;
	int	i;

	if (argc == 2)
	{
		if (part_string(tab, argv, argc) == 0)
			return (0);
	}
	else
	{
		if (part_arg(argv, argc, tab, i) == 0)
			return (0);
	}
	return (0);
}
