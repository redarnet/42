/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redarnet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 13:01:27 by redarnet          #+#    #+#             */
/*   Updated: 2019/11/18 15:59:59 by redarnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_count_space(int n, char *str, char d, struct s_stock_str *par)
{
	int i;

	i = ft_strlen(str);
	if (i >= n)
		return ;
	else
		while (i != n)
		{
			ft_putchar(d, par);
			i++;
		}
}

void	ft_count(int n, char c, struct s_stock_str *par)
{
	while (n > 0)
	{
		ft_putchar(c, par);
		n--;
	}
}

void	ft_count2(int y, int n, int z, struct s_stock_str *par)
{
	while (n - z > 0)
	{
		ft_putchar(' ', par);
		n--;
	}
	while (z - y > 0)
	{
		ft_putchar('0', par);
		z--;
	}
}

int		ft_point_etoile(int i, const char *str, int *z)
{
	while (str[i + 1] >= '0' && str[i + 1] <= '9')
	{
		*z = *z * 10 + str[i + 1] - '0';
		i++;
	}
	return (i);
}

void	ft_format_point_count(int y, int z, struct s_stock_str *par)
{
	if (y > z)
		ft_count(par->n - y - 1, ' ', par);
	if (z >= y)
		ft_count(par->n - z - 1, ' ', par);
	ft_putchar('-', par);
	if (z > y)
		ft_count(z - y, '0', par);
}
