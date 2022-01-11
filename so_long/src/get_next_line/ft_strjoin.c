/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redarnet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 12:43:40 by redarnet          #+#    #+#             */
/*   Updated: 2020/03/02 15:36:28 by redarnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_joins(char *s1, size_t *x, char *str)
{
	if (s1)
	{
		while (s1[*x] != '\0')
		{
			str[*x] = s1[*x];
			*x = *x + 1;
		}
	}
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	y;
	size_t	x;

	y = 0;
	x = 0;
	if (!s1 && !s2)
		return (NULL);
	str = malloc(sizeof(char ) * ft_strlen2(s1)
			+ ft_strlen2(s2) + 1);
	if (str == NULL)
		return (NULL);
	str = ft_joins(s1, &x, str);
	if (s2)
	{
		while (s2[y] != '\0')
		{
			str[x + y] = s2[y];
			y++;
		}
	}
	str[x + y] = '\0';
	return (str);
}
