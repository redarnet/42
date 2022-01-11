/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_affiche_adresse.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redarnet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 12:23:35 by redarnet          #+#    #+#             */
/*   Updated: 2019/11/18 15:59:53 by redarnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	int	ft_convertion_u(long int nb)
{
	if (nb >= 0)
		return (nb);
	else
		nb = 4294967296 + nb;
	return (nb);
}

char		*ft_affiche_nombre(long int nb, char c)
{
	char *str;

	if (c == 'd' || c == 'i')
		str = ft_itoa(nb);
	else if (c == 'u')
	{
		nb = ft_convertion_u(nb);
		str = ft_itoa(nb);
	}
	else if (c == 'o')
		str = ft_itoa_base(nb, "01234567", c);
	else if (c == 'x')
		str = ft_itoa_base(nb, "0123456789abcdef", c);
	else
		str = ft_itoa_base(nb, "0123456789ABCDEF", c);
	return (str);
}

int			ft_condition(struct s_stock_str *par,
		const char *str, int i, va_list (ap), ...)
{
	if (str[i] == '*')
	{
		par->n = va_arg(ap, int);
		if (par->n < 0)
		{
			par->neg = 2;
			par->x = 2;
			par->n = -par->n;
			par->c = ' ';
		}
	}
	if (str[i + 1] == '.')
		i++;
	return (i);
}

char		*ft_adresse(char *base, long long int adr)
{
	int		i;
	char	*res;

	res = malloc(sizeof(char*) * 13);
	i = 12;
	res[13] = '\0';
	while (i != 0)
	{
		res[i] = base[(adr % 16)];
		adr = adr / 16;
		i--;
	}
	res[i] = base[(adr % 16)];
	return (res);
}

char		*ft_affiche_adresse(long long int adr)
{
	char		*base;
	char		*res;
	char		*str;
	int			i;

	i = 0;
	base = "0123456789abcdef";
	str = malloc(sizeof(char*) * 1);
	str[0] = '\0';
	if (adr == 0)
	{
		str = ft_strjoin(str, "0x0", 0);
		return (str);
	}
	str = ft_strjoin(str, "0x", 0);
	res = malloc(sizeof(char*) * 13);
	res = ft_adresse(base, adr);
	while (res[i] == '0')
		i++;
	str = ft_strjoin(str, res, i);
	return (str);
}
