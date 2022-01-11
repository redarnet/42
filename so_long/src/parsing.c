#include "so_long.h"

void	ft_pars_map2(char **map, t_data *data, int x, int y)
{
	if (data->y - 1 == y)
		if (map[y][x] != '1')
			ft_error2("map");
	if (y == 0)
		if (map[y][x] != '1')
			ft_error2("map e");
	if ((map[y][x] != '1') && (map[y][x] != '0') && (map[y][x]
			!= 'P') && (map[y][x] != 'C') && (map[y][x] != 'E'))
		ft_error2("map c");
	if (map[y][x + 1] == '\0')
		if (map[y][x] != '1')
			ft_error2("map r");
}

void	ft_pars_map(char **map, t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map[y] != 0)
	{
		x = 0;
		if (x == 0)
			if (map[y][x] != '1')
				ft_error2("map x");
		while (map[y][x] != '\0')
		{
			ft_pars_map2(map, data, x, y);
			x++;
		}
		y++;
		if (x != data->x)
			ft_error2("mape");
	}
}

void	check_line(char *tab)
{
	int	i;

	i = 0;
	while (tab[i] != '\0')
	{
		if (tab[i] == '\n')
			if (tab[i + 1] == '\n')
				ft_error2("map");
		i++;
	}
}

char	*ft_pars_fichier2(char *tab, char *line)
{
	char	*str;

	str = tab;
	tab = ft_strjoin(str, line);
	free(str);
	free(line);
	str = tab;
	tab = ft_strjoin(str, "\n");
	free(str);
	return (tab);
}

void	ft_pars_fichier(struct s_data *data, char *argv)
{
	char	*line;
	char	*tab;
	char	*str;
	int		fd;

	ft_extention(argv);
	tab = NULL;
	str = NULL;
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		ft_error2("wrong open");
	pars(data);
	while (get_next_line(fd, &line) == 1)
		tab = ft_pars_fichier2(tab, line);
	check_line(tab);
	data->map = ft_split((tab), '\n');
	free(line);
	free(tab);
}
