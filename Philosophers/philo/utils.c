/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redarnet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/21/08 14:08:34 by redarnet          #+#    #+#             */
/*   Updated: 2021/21/10 13:53:18 by redarnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_atoi(const char *nptr)
{
	int		i;
	char	signe;
	int		n;
	int		a;

	i = 0;
	n = 0;
	a = -1;
	signe = 'p';
	while (nptr[i] == ' ' || nptr[i] == '\t' || nptr[i] == '\f'
		|| nptr[i] == '\n' || nptr[i] == '\r' || nptr[i] == '\v')
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			a = -a;
		i++;
	}
	while (nptr[i] <= '9' && nptr[i] >= '0')
	{
		n = n * 10 + nptr[i] - 48;
		i++;
	}
	return (n * -a);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while (n--)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		if (str1[i] == '\0' && str2[i] == '\0')
			break ;
		i++;
	}
	return (0);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	verif_num(char **str, int i)
{
	int	y;
	int	x;

	x = 1;
	while (x != i)
	{
		y = 0;
		if (str[x][y] == '\0')
			return (0);
		while (str[x][y] != '\0')
		{
			if (ft_isdigit(str[x][y]) == 0)
				return (0);
			y++;
		}
		x++;
	}
	return (1);
}

int	ft_strlen_nb(int nb)
{
	int	i;

	i = 0;
	while (nb >= 1)
	{
		i++;
		nb = nb / 10;
	}
	return (i);
}
