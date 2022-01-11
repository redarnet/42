/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redarnet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 10:37:36 by redarnet          #+#    #+#             */
/*   Updated: 2019/11/14 15:37:06 by redarnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2, int y)
{
	char	*str;
	int		x;

	x = 0;
	if (!s1 || !s2)
		return (0);
	if ((str = malloc(sizeof(char) * ft_strlen(s1)
			+ ft_strlen(s2) - y + 1)) == NULL)
		return (0);
	while (s1[x] != '\0')
	{
		str[x] = s1[x];
		x++;
	}
	while (s2[y] != '\0')
	{
		str[x] = s2[y];
		x++;
		y++;
	}
	str[x] = '\0';
	return (str);
}
