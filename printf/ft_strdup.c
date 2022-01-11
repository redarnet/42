/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redarnet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 09:28:22 by redarnet          #+#    #+#             */
/*   Updated: 2019/11/18 16:04:50 by redarnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dest;
	int		i;

	i = 0;
	while (s[i] != '\0')
		i++;
	if ((dest = malloc(sizeof(*dest) * i + 1)) == NULL)
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		dest[i] = (char)s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	ft_format_point_nombre3(struct s_stock_str *par,
	char c, va_list (ap), ...)
{
	int		nb;
	char	*str2;
	int		y;

	nb = va_arg(ap, int);
	if (nb == 0)
		return ;
	par->c = ' ';
	if ((nb < 0 && c == 'd') || (nb < 0 && c == 'i'))
	{
		nb = -nb;
		ft_putchar('-', par);
		str2 = ft_affiche_nombre(nb, c);
		y = ft_strlen(str2);
		ft_putstr(str2, par);
		ft_count_space(par->n - 1, str2, par->c, par);
		return ;
	}
	str2 = ft_affiche_nombre(nb, c);
	y = ft_strlen(str2);
	ft_putstr(str2, par);
	ft_count_space(par->n, str2, par->c, par);
}
