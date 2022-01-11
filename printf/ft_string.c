/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redarnet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 15:55:12 by redarnet          #+#    #+#             */
/*   Updated: 2019/11/18 16:00:13 by redarnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_string3(struct s_stock_str *par, va_list (ap), ...)
{
	int c;

	ft_count_space(par->n, "e", par->c, par);
	c = va_arg(ap, int);
	ft_putchar(c, par);
}

void	ft_string4(struct s_stock_str *par, va_list (ap), ...)
{
	int c;

	c = va_arg(ap, int);
	ft_putchar(c, par);
	ft_count_space(par->n, "e", par->c, par);
}

void	ft_format_point_nombre2_pos(int z, int y,
	struct s_stock_str *par, char *str2)
{
	if (z > y && z > par->n)
	{
		ft_count(z - y, '0', par);
		ft_putstr(str2, par);
	}
	else if (par->n >= y && y >= z)
	{
		ft_putstr(str2, par);
		ft_count(par->n - y, ' ', par);
	}
	else if (par->n >= y && z >= y && par->n >= z)
	{
		ft_count(z - y, '0', par);
		ft_putstr(str2, par);
		ft_count(par->n - z, ' ', par);
	}
	else
		ft_putstr(str2, par);
}

void	ft_format_point_nombre2(int z, struct s_stock_str *par,
		char c, va_list (ap), ...)
{
	int		nb;
	char	*str2;
	int		y;

	nb = va_arg(ap, int);
	if (nb < 0 && (c == 'd' || c == 'i'))
	{
		ft_putchar('-', par);
		nb = -nb;
	}
	str2 = ft_affiche_nombre(nb, c);
	y = ft_strlen(str2);
	ft_format_point_nombre2_pos(z, y, par, str2);
}

void	ft_format_point_string(struct s_stock_str *par,
	char c, int z, va_list (ap), ...)
{
	int		y;
	char	*str2;

	str2 = "%";
	if (c != '%')
		str2 = va_arg(ap, char*);
	if (str2 == NULL)
		str2 = "(null)";
	y = ft_strlen(str2);
	if (par->x != 2)
	{
		if (par->n > y && z > y)
			ft_count(par->n - y, par->c, par);
		else if (par->n > z)
			ft_count(par->n - z, par->c, par);
		ft_putstr2(str2, z, par);
	}
	else
	{
		ft_putstr2(str2, z, par);
		if (par->n > y && z > y)
			ft_count(par->n - y, par->c, par);
		else if (par->n > z)
			ft_count(par->n - z, par->c, par);
	}
}
