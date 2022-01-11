#include "so_long.h"

void	ft_error2(char *str)
{
	ft_putstr_fd("Error\n", 1);
	ft_putstr_fd(str, 1);
	exit(5);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i] != 0)
	{
		free(map[i]);
		i++;
	}
}

void	lmlx_destroy_image(t_data *img)
{
	mlx_destroy_image(img->mlx_ptr, img->img_ptr);
	free(img);
}

int	run(t_data *data)
{
	int	key;

	key = 112;
	ft_draw_walls(data, key);
	return (0);
}
