/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redarnet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 14:44:11 by redarnet          #+#    #+#             */
/*   Updated: 2020/07/22 13:19:24 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_check2_bis(t_data *data, char c, int x, int y)
{
	int x1;
	int y1;

	x1 = x;
	y1 = y;
	if (c == '0')
	{
		while (y1 != data->count2 + 1)
		{
			y1--;
			if (data->map[y1][x1] == '1')
				break ;
			if (data->map[y1][x1] == ' ' || y1 < data->count2)
				ft_error2("map");
		}
	}
}

void	ft_check2(t_data *data, char c, int x, int y)
{
	int x1;
	int y1;

	x1 = x;
	y1 = y;
	if (c == '0')
	{
		while (data->map[y1] != 0)
		{
			if (data->map[y1][x1] == '1')
				break ;
			if (data->map[y1][x1] == ' ' || data->map[y1 + 1] == 0)
				ft_error2("map");
			y1++;
		}
	}
	ft_check2_bis(data, data->map[y][x], x, y);
}

void	ft_check(t_data *data, char c, int x, int y)
{
	int x1;

	if (c != 'N' && c != 'S' && c != 'E' && c != 'O'
			&& c != '1' && c != ' ' && c != '0' && c != '\0')
		ft_error2("map");
	if (c == 'N' || c == 'S' || c == 'E' || c == 'O')
	{
		if (data->count > 0)
			ft_error2("map");
		data->count = 1;
	}
	x1 = x;
	if (c == '0')
		while (data->map[y][x1] != '\0')
		{
			x1++;
			if (data->map[y][x1] == '1')
				break ;
			if (data->map[y][x1] == ' ' || data->map[y][x1 + 1] == '\0')
				ft_error2("map");
		}
	ft_check2(data, c, x, y);
}

void	checkmap2(t_data *data)
{
	int x;
	int z;
	int y;

	y = data->count2;
	z = 0;
	while (data->map[y] != 0)
	{
		x = 0;
		ft_space(data, data->map[y][0], 0, y);
		while (data->map[y][x] != '\0')
		{
			if (data->map[y][x] == 'O' || data->map[y][x] == 'N'
				|| data->map[y][x] == 'S' || data->map[y][x] == 'E')
				z = 1;
			ft_check(data, data->map[y][x], x, y);
			x++;
		}
		y++;
	}
	if (z != 1)
		ft_error2("syntax");
}

int		start_map(struct s_data data)
{
	int x;
	int y;
	int z;

	data.count2 = 0;
	data.count = 0;
	z = 0;
	x = 0;
	y = 0;
	while (data.map[y] != 0)
	{
		x = 0;
		while (data.map[y][x] != '\0')
		{
			if ((data.map[y][0] != 'R') &&
			(data.map[y][0] != 'F') && (data.map[y][0] != 'C'))
				if (data.map[y][x] == '1' && data.count2 == 0)
					data.count2 = y;
			x++;
		}
		y++;
	}
	return (data.count2);
}
