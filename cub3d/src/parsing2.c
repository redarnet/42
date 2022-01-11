/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redarnet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 12:55:43 by redarnet          #+#    #+#             */
/*   Updated: 2020/07/17 20:55:38 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_double_start(char **str, char c)
{
	int i;

	i = 0;
	while (str[i] != 0)
	{
		if (str[i][0] == c)
		{
			i++;
			while (str[i] != 0)
			{
				if (str[i][0] == c)
					ft_error2("bad syntax");
				i++;
			}
			break ;
		}
		i++;
	}
}

int		first_letter(char c, int count, int i, t_data *data)
{
	if ((c == 'N' || c == 'R' || c == 'S' || c == 'W' || c == 'E'
		|| c == 'F' || c == 'C') && i == 0)
		return (1);
	else if (c == '1' && count < 8)
		ft_error2("bad syntax");
	else if (c == '1')
		return (0);
	else if (c == '\0' || c == '\n')
		return (0);
	else
		ft_error2("bad syntax");
	return (0);
}

void	ft_syntax(char **str, t_data *data)
{
	int y;
	int i;
	int count;

	i = 0;
	count = 0;
	y = 0;
	while (str[y] != 0)
	{
		while (str[y][i] == ' ')
		{
			while (str[y][i] == ' ')
				i++;
			if (count += first_letter(str[y][i], count, i, data))
				;
		}
		if (count += first_letter(str[y][i], count, i, data))
			;
		i = 0;
		y++;
	}
}

void	ft_check_pars(char **str, t_data *data)
{
	ft_double_start(str, 'R');
	ft_double_start(str, 'W');
	ft_double_start(str, 'N');
	ft_double_start(str, 'E');
	ft_double_start(str, 'C');
	ft_double_start(str, 'F');
	ft_double_start2(str, 'S');
	ft_syntax(str, data);
}

void	split(char *line, t_data *data)
{
	int	i;

	i = 2;
	while (line[i] == ' ')
		i++;
	while (line[i] >= '0' && line[i] <= '9')
	{
		data->x = data->x * 10 - '0' + line[i];
		i++;
	}
	if (data->x == 0)
		ft_error2("resolution");
	while (line[i] == ' ')
		i++;
	while (line[i] >= '0' && line[i] <= '9')
	{
		data->y = data->y * 10 - '0' + line[i];
		i++;
	}
	if (data->y == 0)
		ft_error2("resolution");
	while (line[i] == ' ')
		i++;
	if (line[i] != '\0')
		ft_error2("syntax config");
}
