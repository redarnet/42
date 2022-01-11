/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redarnet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 16:51:45 by redarnet          #+#    #+#             */
/*   Updated: 2019/11/11 16:02:25 by redarnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*remplir_tab(long int nb, char *str, int i, char signe)
{
	int n;

	n = 0;
	if (signe == 'n')
	{
		str[0] = '-';
		n++;
	}
	str[i] = '\0';
	i--;
	while (i != n)
	{
		str[i] = (nb % 10) + 48;
		nb = nb / 10;
		i--;
	}
	str[i] = (nb % 10) + 48;
	return (str);
}

int		ft_compteur(long int n, int i)
{
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(long int n)
{
	char	*str;
	char	signe;
	int		i;

	i = 1;
	signe = 'p';
	if (n < -2147483647)
	{
		str = ft_strdup("-2147483648");
		return (str);
	}
	if (n < 0)
	{
		i++;
		n = -n;
		signe = 'n';
	}
	i = ft_compteur(n, i);
	if ((str = malloc(sizeof(char) * i + 1)) == NULL)
		return (0);
	str = remplir_tab(n, str, i, signe);
	return (str);
}
