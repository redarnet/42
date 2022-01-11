/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redarnet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 13:51:16 by redarnet          #+#    #+#             */
/*   Updated: 2019/11/18 16:00:25 by redarnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_string(const char c, struct s_stock_str *par, va_list (ap), ...)
{
	char			*str;
	long long int	nb;

	if (c == 's' || c == 'c')
	{
		str = va_arg(ap, char*);
		if (str == NULL)
			str = "(null)";
		ft_count_space(par->n, str, par->c, par);
		ft_putstr(str, par);
	}
	if (c == 'p')
	{
		nb = va_arg(ap, long long int);
		str = ft_affiche_adresse(nb);
		ft_count_space(par->n, str, par->c, par);
		ft_putstr(str, par);
	}
}

void	ft_string2(const char c, struct s_stock_str *par, va_list (ap), ...)
{
	char			*str;
	long long int	nb;

	if (c == 's' || c == 'c')
	{
		str = va_arg(ap, char*);
		if (str == NULL)
			str = "(null)";
		ft_putstr(str, par);
		ft_count_space(par->n, str, par->c, par);
		par->n = par->n - 1;
	}
	if (c == 'p')
	{
		nb = va_arg(ap, long long int);
		str = ft_affiche_adresse(nb);
		ft_putstr(str, par);
		ft_count_space(par->n, str, par->c, par);
	}
}

int		ft_zero_neg(int nb, struct s_stock_str *par)
{
	nb = -nb;
	par->n = par->n - 1;
	ft_putchar('-', par);
	return (nb);
}

void	ft_format(const char c, struct s_stock_str *par, va_list (ap), ...)
{
	char		*str;
	long int	nb;

	if (c == 'c')
		ft_string3(par, ap);
	else if (c == 's' || c == 'p')
		ft_string(c, par, ap);
	else if (c == '%')
	{
		if (par->n - 1 > 0)
			ft_count(par->n - 1, par->c, par);
		ft_putchar('%', par);
	}
	else
	{
		nb = va_arg(ap, int);
		if (c == 'u')
			nb = ft_convertion_u(nb);
		if (par->c == '0' && nb < 0 && ((c == 'd') || (c == 'i')))
			nb = ft_zero_neg(nb, par);
		str = ft_affiche_nombre(nb, c);
		ft_count_space(par->n, str, par->c, par);
		ft_putstr(str, par);
	}
}

void	ft_format2(const char c, struct s_stock_str *par, va_list (ap), ...)
{
	char	*str;
	int		nb;

	if (c == 'c')
		ft_string4(par, ap);
	else if (c == 's' || c == 'p')
		ft_string2(c, par, ap);
	else if (c == '%')
	{
		ft_putchar('%', par);
		if (par->n - 1 > 0)
			ft_count(par->n - 1, ' ', par);
	}
	else
	{
		nb = va_arg(ap, int);
		if (c == 'u')
			nb = ft_convertion_u(nb);
		if (par->c == '0' && nb < 0 && ((c == 'd') || (c == 'i')))
			nb = ft_zero_neg(nb, par);
		str = ft_affiche_nombre(nb, c);
		ft_putstr(str, par);
		ft_count_space(par->n, str, par->c, par);
	}
}
