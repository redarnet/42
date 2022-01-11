#include "so_long.h"

int	algo(t_data *data, char c)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (c == '1')
		return (0);
	if (c == 'E')
	{
		while (data->map[y] != 0)
		{
			x = 0;
			while (data->map[y][x] != '\0')
			{
				if (data->map[y][x] == 'C')
					return (0);
				x++;
			}
			y++;
		}
		ft_quit();
		return (2);
	}
	return (1);
}

void	algo_key2(t_data *data, int key, int x, int y)
{
	if (key == KEY_W)
	{
		if (algo(data, data->map[y - 1][x]) == 0)
			return ;
		data->map[y][x] = '0';
		data->map[y - 1][x] = 'P';
		data->u = data->u + 1;
		ft_putnbr_fd(data->u, 1);
		ft_putchar_fd('\n', 1);
	}
	if (key == KEY_S)
	{
		if (algo(data, data->map[y + 1][x]) == 0)
			return ;
		data->map[y][x] = '0';
		data->map[y + 1][x] = 'P';
		data->u = data->u + 1;
		ft_putnbr_fd(data->u, 1);
		ft_putchar_fd('\n', 1);
	}
}

void	alog_key(t_data *data, int key, int x, int y)
{
	if (key == KEY_D)
	{
		if (algo(data, data->map[y][x + 1]) == 0)
			return ;
		data->map[y][x] = '0';
		data->map[y][x + 1] = 'P';
		data->u = data->u + 1;
		ft_putnbr_fd(data->u, 1);
		ft_putchar_fd('\n', 1);
	}
	if (key == KEY_A)
	{
		if (algo(data, data->map[y][x - 1]) == 0)
			return ;
		data->map[y][x] = '0';
		data->map[y][x - 1] = 'P';
		data->u = data->u + 1;
		ft_putnbr_fd(data->u, 1);
		ft_putchar_fd('\n', 1);
	}
	algo_key2(data, key, x, y);
}

void	ft_algo(t_data *data, int key)
{
	int	y;
	int	x;

	y = 0;
	while (data->map[y] != 0)
	{
		x = 0;
		while (data->map[y][x] != '\0')
		{
			if (data->map[y][x] == 'P')
			{
				alog_key(data, key, x, y);
				if (key == KEY_W || key == KEY_D
					|| key == KEY_A || key == KEY_S)
					return ;
			}
			x++;
		}
		y++;
	}
}
