/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redarnet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 14:44:11 by redarnet          #+#    #+#             */
/*   Updated: 2020/07/22 13:19:24 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_space2(t_data *data, int x, int y, int z)
{
	if (z != 1)
		while (data->map[y] != 0)
		{
			x = 0;
			while (data->map[y][x] != '\0')
			{
				if (data->map[y][x] == '1')
					ft_error2("space map");
				x++;
			}
			y++;
		}
}

void	ft_space(t_data *data, char c, int x, int y)
{
	int z;

	z = 0;
	if (c == ' ')
		while (data->map[y][x] != '\0')
		{
			if (data->map[y][x] != ' ')
			{
				z = 1;
				break ;
			}
			x++;
		}
	else
		z = 1;
	ft_space2(data, x, y, z);
}

void	ft_double_start2(char **str, char c)
{
	int i;
	int x;

	i = 0;
	x = 0;
	while (str[i] != 0)
	{
		if (str[i][0] == c)
		{
			i++;
			while (str[i] != 0)
			{
				if (str[i][0] == c)
					x++;
				if (str[i][0] == c && x == 2)
					ft_error2("bad syntaxe");
				i++;
			}
			break ;
		}
		i++;
	}
}

void	ft_free_map(int **map, t_data *data)
{
	int x;

	x = 1;
	while (x != data->size_free)
	{
		if (map[x])
			free(map[x]);
		x++;
	}
	free(map);
}

void	ft_free_m(char **map)
{
	int x;

	x = 0;
	while (map[x] != 0)
	{
		if (map[x])
			free(map[x]);
		x++;
	}
	free(map);
}
