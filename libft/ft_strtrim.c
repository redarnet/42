/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redarnet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 09:20:43 by redarnet          #+#    #+#             */
/*   Updated: 2019/10/24 14:58:13 by redarnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_present(char str, char *charset)
{
	int i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (str == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int		taille(char *s1, char *set)
{
	int i;
	int y;

	i = ft_strlen(s1);
	y = 0;
	i--;
	while (i != 0 && ft_present(s1[i], (char*)set) == 1)
	{
		i--;
		y++;
	}
	return (y);
}

char	*ft_remplir(int d, int x, char *str, char const *s1)
{
	int i;

	i = 0;
	while (d-- != 0)
	{
		str[i] = s1[i + x];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	x;
	int		d;

	x = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[x] != '\0' && ft_present(s1[x], (char*)set) == 1)
		x++;
	if (x == ft_strlen(s1))
	{
		if ((str = malloc(sizeof(char) * 1)) == NULL)
			return (0);
		str[0] = '\0';
		return (str);
	}
	d = ft_strlen(s1) - taille((char*)s1, (char*)set) - x;
	if ((str = malloc(sizeof(char) * d + 1)) == NULL)
		return (0);
	str = ft_remplir(d, x, str, s1);
	return (str);
}
