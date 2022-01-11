/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redarnet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 15:35:06 by redarnet          #+#    #+#             */
/*   Updated: 2019/11/18 16:03:08 by redarnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __LIBFT_H
# define __LIBFT_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct	s_stock_str
{
	int		n;
	int		x;
	char	c;
	int		r;
	int		neg;
}				t_stock_str;

void			ft_putchar(char c, struct s_stock_str *par);
void			ft_putstr(char *str, struct s_stock_str *par);
void			ft_format(const char c, struct s_stock_str *par,
			va_list(ap), ...);
void			ft_format2(const char c, struct s_stock_str *par,
			va_list(ap), ...);
void			ft_count(int n, char c, struct s_stock_str *par);
void			ft_format_point_count(int y, int z, struct s_stock_str *par);
void			ft_count_space(int n, char *str, char d,
			struct s_stock_str *par);
void			ft_count2(int y, int n, int z, struct s_stock_str *par);
void			ft_putstr2(char *str, int n, struct s_stock_str *par);
void			ft_format_point_string(struct s_stock_str *par,
			char c, int z, va_list(ap), ...);
char			*ft_affiche_nombre(long int nb, char c);
char			*ft_itoa_base(int n, char *base, char c);
char			*ft_itoa(long int n);
char			*ft_strdup(const char *s);
void			ft_string3(struct s_stock_str *par, va_list (ap), ...);
void			ft_string4(struct s_stock_str *par, va_list (ap), ...);
void			ft_format_point_nombre2_pos(int z, int y,
			struct s_stock_str *par, char *str2);
void			ft_format_point_nombre2(int z, struct s_stock_str *par,
			char c, va_list (ap), ...);
void			ft_format_point_nombre3(struct s_stock_str *par,
			char c, va_list (ap), ...);
char			*ft_affiche_nombre(long int nb, char c);
char			*ft_affiche_adresse(long long int nb);
int				ft_condition(struct s_stock_str *par, const char *str,
			int i, va_list (ap), ...);
int				ft_strlen(char *str);
int				ft_printf(const char *str, ...);
int				ft_format_point(const char *str,
			struct s_stock_str *par, int i, va_list(ap), ...);
int				ft_point_etoile(int i, const char *str, int *z);
long int		ft_convertion_u(long int nb);
char			*ft_strjoin(char *s1, char *s2, int x);

#endif
