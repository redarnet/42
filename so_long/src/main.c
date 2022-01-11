/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redarnet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 14:44:11 by redarnet          #+#    #+#             */
/*   Updated: 2020/07/22 13:19:24 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_quit(void)
{
	exit(5);
	return (0);
}

void	init_so(struct s_data *data)
{
	data->x = 0;
	data->y = 0;
	data->u = 0;
}

int	deal_key_map(int key, t_data *data)
{
	if (key == 65307)
		ft_quit();
	ft_draw_walls(data, key);
	return (0);
}

void	so_long(struct s_data *data)
{
	if (data->x > 1920)
		data->x = 1920;
	if (data->y > 926)
		data->y = 926;
	data->mlx_ptr = mlx_init(&data);
	if (data->mlx_ptr == NULL)
		ft_error2("window");
	data->x = data->x * 64;
	data->y = data->y * 64;
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->x, data->y, "So_long");
	if (data->win_ptr == NULL)
		ft_error2("window");
	textures(data);
	deal_key_map(112, data);
	mlx_hook(data->win_ptr, 17, (1L << 17), ft_quit, &data);
	mlx_loop_hook(data->mlx_ptr, run, data);
	mlx_hook(data->win_ptr, 2, (1L << 0), &deal_key_map, data);
	mlx_loop(data->mlx_ptr);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	free(data);
	ft_quit();
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
	{
		ft_putstr_fd("Error\n arg", 1);
		return (0);
	}
	init_so(&data);
	ft_pars_fichier(&data, argv[1]);
	while (data.map[data.y] != 0)
	{
		data.x = 0;
		while (data.map[data.y][data.x] != '\0')
			data.x++;
		data.y++;
	}
	ft_pars_map(data.map, &data);
	ft_check_map(data.map);
	so_long(&data);
	free(data.map);
	return (0);
}
