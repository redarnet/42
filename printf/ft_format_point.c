/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_point.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redarnet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 12:42:23 by redarnet          #+#    #+#             */
/*   Updated: 2019/11/18 16:04:08 by redarnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_format_point_nombre_pos(int nb, char c, int z,
		struct s_stock_str *par)
{
	char	*str2;
	int		y;

	str2 = ft_affiche_nombre(nb, c);
	y = ft_strlen(str2);
	if (z > y && z > par->n)
		ft_count(z - y, '0', par);
	else if (par->n >= y && y >= z)
		ft_count(par->n - y, ' ', par);
	else if (par->n >= y && z >= y)
		ft_count2(y, par->n, z, par);
	str2 = ft_affiche_nombre(nb, c);
	ft_putstr(str2, par);
}

void	ft_format_point_nombre(int z, struct s_stock_str *par,
	char c, va_list (ap), ...)
{
	int		nb;
	char	*str2;
	int		y;

	nb = va_arg(ap, int);
	if (nb == 0)
		return ;
	if ((nb < 0 && c == 'd') || (nb < 0 && c == 'i'))
	{
		nb = -nb;
		str2 = ft_affiche_nombre(nb, c);
		y = ft_strlen(str2);
		if (par->n > y && par->n > z)
		{
			ft_format_point_count(y, z, par);
			ft_putstr(str2, par);
			return ;
		}
		ft_putchar('-', par);
	}
	ft_format_point_nombre_pos(nb, c, z, par);
}

void	ft_format_nombre_neg(struct s_stock_str *par,
	char c, va_list (ap), ...)
{
	int		nb;
	char	*str2;
	int		y;

	nb = va_arg(ap, int);
	if ((nb < 0 && c == 'd') || (nb < 0 && c == 'i'))
	{
		nb = -nb;
		if (par->c == '0')
			ft_putchar('-', par);
		str2 = ft_affiche_nombre(nb, c);
		y = ft_strlen(str2);
		ft_count(par->n - y - 1, par->c, par);
		if (par->c != '0')
			ft_putchar('-', par);
		ft_putstr(str2, par);
	}
	else
	{
		str2 = ft_affiche_nombre(nb, c);
		y = ft_strlen(str2);
		ft_count(par->n - y, par->c, par);
		ft_putstr(str2, par);
	}
}

void	ft_format_point_neg(int z,
		struct s_stock_str *par, char c, va_list (ap), ...)
{
	if (c == 'd' || c == 'u' || c == 'i'
	|| c == 'o' || c == 'x' || c == 'X')
	{
		if (par->x != 2)
			ft_format_nombre_neg(par, c, ap);
		else
			ft_format_point_nombre3(par, c, ap);
	}
	else
		ft_format_point_string(par, c, -z, ap);
}

int		ft_format_point(const char *str,
		struct s_stock_str *par, int i, va_list (ap), ...)
{
	int		z;

	z = 0;
	if (str[i + 1] == '*')
	{
		z = va_arg(ap, int);
		i++;
	}
	else if (str[i + 1] == 'p')
		ft_format(str[i + 1], par, ap);
	else
		i = ft_point_etoile(i, str, &z);
	if (z < 0)
		ft_format_point_neg(z, par, str[i + 1], ap);
	else if (str[i + 1] == 'd' || str[i + 1] == 'u' || str[i + 1] == 'i'
		|| str[i + 1] == 'o' || str[i + 1] == 'x' || str[i + 1] == 'X')
		if (par->x != 2)
			ft_format_point_nombre(z, par, str[i + 1], ap);
		else
			ft_format_point_nombre2(z, par, str[i + 1], ap);
	else if (str[i + 1] == 's' || str[i + 1] == 'c' || str[i + 1] == '%')
		ft_format_point_string(par, str[i + 1], z, ap);
	return (i);
}
