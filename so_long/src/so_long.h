#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include "../libft/libft.h"
# include "get_next_line/get_next_line.h"
# include <math.h>
# include "../minilibx-linux/mlx.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <errno.h>
# define KEY_A 97
# define KEY_S 115
# define KEY_W 119
# define KEY_D 100

typedef struct s_t
{
	int		texture[5][64][64];
	int		i;
	int		x;
	char	*ptr;
	int		y;
}				t_t;

typedef struct s_sprite
{
}				t_sprite;

typedef struct s_data
{
	t_t			text;
	t_sprite	*sprite;
	void		*mlx_ptr;
	void		*win_ptr;
	char		**map;
	void		*img_ptr;
	char		*text_nord[5];
	int			x;
	int			y;
	int			*img_data;
	int			bpp;
	int			size_l;
	int			u;
	int			color;
	int			r;
	int			z;
	int			a;
	int			b;

}				t_data;

void			textures(t_data *data);
void			pars(t_data *data);
void			ft_extention(char *argv);
int				deal_key_map(int key, t_data *data);
void			ft_algo(t_data *data, int key);
void			ft_draw_walls(struct s_data *data, int key);
void			ft_pars_fichier(struct s_data *data, char *argv);
int				ft_quit(void);
void			ft_error2(char *str);
void			ft_pars_map(char **map, t_data *data);
void			free_map(char **map);
t_data			*lmlx_new_image(void *mlx_ptr,
					void *win_ptr, int width, int height);
void			lmlx_destroy_image(t_data *img);
void			ft_check_map(char **map);
void			ft_check_pars(char **str, t_data *data);
int				run(t_data *data);

#endif
