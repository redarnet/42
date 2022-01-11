/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertisseur.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redarnet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 16:54:39 by redarnet          #+#    #+#             */
/*   Updated: 2020/08/05 16:21:54 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_atoi2(char *str)
{
	int x;
	int i;

	i = 0;
	x = 0;
	while (str[i] != '\0')
	{
		x = x * 10 + str[i] - 48;
		i++;
	}
	return (x);
}

int		rgb_hex(int red, int green, int blue, t_data *data)
{
	char	*red2;
	char	*green2;
	char	*blue2;
	char	*end;

	if (red > 255 || blue > 255 || green > 255)
		ft_error2("color range");
	red2 = ft_itoa_base(red, "0123456789ABCDEF");
	green2 = ft_itoa_base(green, "0123456789ABCDEF");
	blue2 = ft_itoa_base(blue, "0123456789ABCDEF");
	end = ft_strjoin_free(red2, green2);
	end = ft_strjoin_free(end, blue2);
	data->couleur1 = ft_atoi_base(end, "0123456789ABCDEF");
	free(end);
	return (data->couleur1);
}

int		parse_s_p2(char *line, t_data *data)
{
	int i;

	i = 1;
	while (line[i] == ' ')
		i++;
	if (line[i] == ',')
		ft_error2("color syntax");
	while (line[i] >= '0' && line[i] <= '9')
	{
		data->red = data->red * 10 - '0' + line[i];
		i++;
	}
	if (line[i] != ',')
		ft_error2("color syntax");
	i++;
	if (line[i] == ',')
		ft_error2("color syntax");
	while (line[i] >= '0' && line[i] <= '9')
	{
		data->green = data->green * 10 - '0' + line[i];
		i++;
	}
	return (i);
}

int		parse_s_p(char *line, t_data *data)
{
	int i;
	int x;

	data->blue = 0;
	data->red = 0;
	data->green = 0;
	i = parse_s_p2(line, data);
	if (line[i] != ',')
		ft_error2("color syntax");
	i++;
	if (line[i] < '0' || line[i] > '9')
		ft_error2("color syntax");
	while (line[i] >= '0' && line[i] <= '9')
	{
		data->blue = data->blue * 10 - '0' + line[i];
		i++;
	}
	while (line[i] != '\0')
	{
		if (line[i] != ' ')
			ft_error2("color syntax");
		i++;
	}
	x = rgb_hex(data->red, data->green, data->blue, data);
	return (x);
}
