#include "so_long.h"

void	ft_sol(t_data *img, t_data *data)
{
	data->z = 0;
	while (data->z < data->y)
	{
		data->r = 0;
		while (data->r < data->x)
		{
			data->a = 0;
			while (data->a != 64)
			{
				data->b = 0;
				while (data->b != 64)
				{
					data->color = data->text.texture[4][data->b][data->a];
					img->img_data[(data->b + data->z)*data->x
						+ data->r] = data->color;
					data->b++;
				}
				data->r++;
				data->a++;
			}
		}
		data->z = data->z + 64;
	}
}

int	ft_affiche_color(char c, t_data *data, int b, int a)
{
	int	color;

	color = 0;
	if (c == 'P')
		color = data->text.texture[1][b][a];
	else if (c == '1')
		color = data->text.texture[0][b][a];
	else if (c == 'C')
		color = data->text.texture[2][b][a];
	else if (c == 'E')
		color = data->text.texture[3][b][a];
	else if (c == '0')
		color = data->text.texture[4][b][a];
	return (color);
}

void	ft_affiche(t_data *img, t_data *data)
{
	data->z = 0;
	while (data->z < data->y)
	{
		data->r = 0;
		while (data->r < data->x)
		{
			data->a = 0;
			while (data->a != 64)
			{
				data->b = 0;
				while (data->b != 64)
				{
					data->color = ft_affiche_color(data->map[data->z
							/ 64][data->r / 64], data, data->b, data->a);
					if ((data->color & 0x00FFFFFF) != 0)
						img->img_data[(data->b + data->z)*data->x
							+ data->r] = data->color;
					data->b++;
				}
				data->r++;
				data->a++;
			}
		}
		data->z = data->z + 64;
	}
}

t_data	*lmlx_new_image(void *mlx_ptr, void *win_ptr, int width, int height)
{
	t_data	*new;
	int		trsh;
	int		bpp;
	int		endian;

	bpp = 32;
	endian = 1;
	new = (struct s_data *)malloc(sizeof (struct s_data));
	if (new == NULL)
		return (NULL);
	new->x = width;
	new->y = height;
	new->mlx_ptr = mlx_ptr;
	new->win_ptr = win_ptr;
	new->img_ptr = mlx_new_image(mlx_ptr, width, height);
	if (new->img_ptr == NULL)
	{
		free(new);
		return (NULL);
	}
	new->img_data = (int *)mlx_get_data_addr(new->img_ptr,
			&bpp, &trsh, &endian);
	return (new);
}

void	ft_draw_walls(struct s_data *data, int key)
{
	int		texheight;
	t_data	*img;

	texheight = 64;
	img = lmlx_new_image(data->mlx_ptr, data->win_ptr, data->x, data->y);
	ft_algo(data, key);
	ft_sol(img, data);
	ft_affiche(img, data);
	mlx_put_image_to_window(img->mlx_ptr, img->win_ptr, img->img_ptr, 0, 0);
	lmlx_destroy_image(img);
}
