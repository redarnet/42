/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redarnet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 13:14:18 by redarnet          #+#    #+#             */
/*   Updated: 2019/11/18 15:15:48 by redarnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_flag(const char *str, int i, struct s_stock_str *par)
{
	if (str[i + 1] == '*')
		return (i + 1);
	while (str[i + 1] >= '0' && str[i + 1] <= '9')
	{
		par->n = par->n * 10 + str[i + 1] - '0';
		i++;
	}
	if (str[i + 1] == '.')
		i++;
	return (i);
}

int		ft_flag2(const char *str, int i, struct s_stock_str *par)
{
	while (str[i + 1] == '-')
	{
		par->x = 2;
		i++;
	}
	if (str[i + 1] == '0')
	{
		if (str[i] != '-')
			par->c = '0';
		i++;
	}
	while (str[i + 1] == '-')
	{
		par->x = 2;
		par->c = ' ';
		i++;
	}
	return (i);
}

int		ft_affiche2(struct s_stock_str *par,
			const char *str, int i, va_list (ap), ...)
{
	if (str[i] == '%')
	{
		if (str[i + 1] == '%')
		{
			ft_putchar('%', par);
			return (i + 1);
		}
		i = ft_flag2(str, i, par);
		i = ft_flag(str, i, par);
		i = ft_condition(par, str, i, ap);
		if (str[i] == '.')
			i = ft_format_point(str, par, i, ap);
		else if (par->x == 2)
			ft_format2(str[i + 1], par, ap);
		else
			ft_format(str[i + 1], par, ap);
		i++;
	}
	else
		ft_putchar(str[i], par);
	return (i);
}

int		ft_affiche(int i, const char *str, va_list (ap), ...)
{
	struct s_stock_str	*par;

	par = (t_stock_str*)malloc(sizeof(t_stock_str) * 1);
	par->r = 0;
	i = -1;
	while (str[++i] != '\0')
	{
		par->n = 0;
		par->x = 0;
		par->c = ' ';
		i = ft_affiche2(par, str, i, ap);
	}
	i = par->r;
	return (i);
}

int		ft_printf(const char *str, ...)
{
	va_list	(ap);
	int		i;

	i = 0;
	va_start(ap, str);
	i = ft_affiche(i, str, ap);
	va_end(ap);
	return (i);
}
