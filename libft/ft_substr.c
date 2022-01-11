/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redarnet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 09:23:24 by redarnet          #+#    #+#             */
/*   Updated: 2019/10/23 12:32:20 by redarnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_taille_malloc(int i, int start, int len)
{
	int x;

	if (i - start > len)
		x = len;
	else
		x = i - start;
	return (x);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;
	size_t			x;

	if (!s)
		return (0);
	i = ft_strlen(s);
	if (i <= start)
	{
		if ((str = malloc(sizeof(char) * 1)) == NULL)
			return (0);
		str[0] = '\0';
		return (str);
	}
	x = ft_taille_malloc(i, start, len);
	if ((str = malloc(sizeof(char) * x + 1)) == NULL)
		return (0);
	i = 0;
	while (s[i + start] != '\0' && i != len)
	{
		str[i] = s[i + start];
		i++;
	}
	str[i] = '\0';
	return (str);
}
