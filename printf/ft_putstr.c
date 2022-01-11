/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redarnet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 13:02:41 by redarnet          #+#    #+#             */
/*   Updated: 2019/11/14 14:36:38 by redarnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr(char *str, struct s_stock_str *par)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i], par);
		i++;
	}
}

void	ft_putstr2(char *str, int n, struct s_stock_str *par)
{
	int i;

	i = 0;
	while (str[i] != '\0' && i != n)
	{
		ft_putchar(str[i], par);
		i++;
	}
}
