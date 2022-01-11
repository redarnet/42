#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdio.h>

typedef struct data
{
	int	a;
	int	b;
}		t_data;

void	short_tri(int *tab, int i);
int		*ft_string(char *str, int *tab, int a);
int		ft_error2(char *str);
int		error(char **argv, int i);
void	algo(int *tab, int argc);
void	tri_bis(int *tab, int a, int indice);
int		ft_limit(char *str);
void	very_short_tri(int *tab, int i);
void	long_tri(int *tab, int *tab2, int i, int y);
void	very_long_tri(int *tab, int *tab2, int i, int y);
void	small_tri(int *tab, int *tab2, int i, int y);
void	small_tri4(int *tab, int *tab2, int i, int y);
void	ft_operation(int *a, int *b, int i);
void	ft_sa(int *a, int y);
void	ft_sb(int *b, int y);
void	ft_ss(int *a, int *b, int i, int y);
void	ft_pa(int *tab, int *tab2, int *a, int *b);
void	ft_pb(int *tab, int *tab2, int *a, int *b);
void	ft_ra(int *tab, int a);
void	ft_rb(int *tab2, int b);
void	ft_rrb(int *tab2, int b);
void	ft_rra(int *tab, int a);
int		*change_num(int *tab, int i, int y);
int		ft_is_croissant(int *tab, int y);
void	push_a(int *tab, int *tab2, int *a, int *b);
int		ft_error(char *str);
void	push_to_a(int *tab, int *tab2, t_data data);
void	push_hold_first(int *tab, int *tab2, t_data *data, int hold_first);
int		push_a_bis(int *tab2, int *b);
int		ft_same_num(int *tab, int a);
void	push_b_long(int *tab, int *tab2, t_data *data, int x);
int		push_b_long_bis(int *tab, int a, int x, int *hold_second);

#endif
