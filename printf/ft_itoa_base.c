/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redarnet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 16:51:45 by redarnet          #+#    #+#             */
/*   Updated: 2019/11/11 11:57:24 by redarnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		taille_malloc(int nbr, char *base)
{
	int len;

	len = ft_strlen(base);
	if (nbr >= 0 && nbr < len)
		return (1);
	else if (nbr < 0)
		return (taille_malloc(-nbr, base) + 1);
	else
		return (taille_malloc((nbr / len), base)
				+ taille_malloc(nbr % len, base));
}

char	*remplir(int nb, char *base, char *str, int i)
{
	int len;

	len = ft_strlen(base);
	str[i] = '\0';
	i--;
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	while (nb >= len)
	{
		str[i] = base[nb % len];
		nb = nb / len;
		i--;
	}
	str[i] = base[nb];
	return (str);
}

char	*ft_neg2(int i, char *str, char *base, int nb)
{
	int len;
	int x;

	x = i;
	len = ft_strlen(base);
	nb = -nb - 1;
	str[i] = '\0';
	while (i != -1)
	{
		str[i] = base[0];
		i--;
	}
	while (nb >= len)
	{
		str[x] = base[nb % len];
		nb = nb / len;
		x--;
	}
	str[x] = base[nb];
	return (str);
}

char	*ft_neg(int nb, char *str, char c)
{
	int		i;
	char	*base;

	i = 7;
	if (c == 'x')
		base = "fedcba9876543210";
	else if (c == 'X')
		base = "FEDCBA9876543210";
	else
	{
		i = 10;
		base = "76543210";
	}
	str = ft_neg2(i, str, base, nb);
	return (str);
}

char	*ft_itoa_base(int n, char *base, char c)
{
	char	*str;
	int		i;

	i = 0;
	if (n < 0)
	{
		if ((str = malloc(sizeof(char) * 2)) == NULL)
			return (0);
		str = ft_neg(n, str, c);
	}
	else
	{
		i = taille_malloc(n, base);
		if ((str = malloc(sizeof(char) * i + 1)) == NULL)
			return (0);
		str = remplir(n, base, str, i);
	}
	return (str);
}
