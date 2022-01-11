#include "so_long.h"

void	pars(t_data *data)
{
	data->text_nord[0] = "textures/eagle.xpm";
	data->text_nord[1] = "textures/barrel.xpm";
	data->text_nord[2] = "textures/pillar.xpm";
	data->text_nord[3] = "textures/sapin.xpm";
	data->text_nord[4] = "textures/redbrick.xpm";
}

void	ft_extention(char *argv)
{
	int	i;

	i = ft_strlen(argv);
	i--;
	if (argv[i] != 'r' || argv[i - 1] != 'e')
		ft_error2("argv");
	if (argv[i - 2] != 'b' || argv[i - 3] != '.')
		ft_error2("argv");
}

void	ft_check_map2(int e, int p, int c)
{
	if (e == 0)
		ft_error2("map");
	if (p != 1)
		ft_error2("map");
	if (c == 0)
		ft_error2("map");
}

void	ft_check_map(char **map)
{
	int	y;
	int	x;
	int	e[3];

	y = 0;
	e[0] = 0;
	e[1] = 0;
	e[2] = 0;
	while (map[y] != 0)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == 'E')
				e[0]++;
			if (map[y][x] == 'P')
				e[1]++;
			if (map[y][x] == 'C')
				e[2]++;
			x++;
		}
		y++;
	}
	ft_check_map2(e[0], e[1], e[2]);
}
