/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redarnet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 14:08:34 by redarnet          #+#    #+#             */
/*   Updated: 2019/10/23 13:53:18 by redarnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	x;
	size_t	len2;

	i = 0;
	len2 = 0;
	if (*needle == 0)
		return ((char*)(haystack));
	while (needle[len2] != '\0')
		len2++;
	while (haystack[i] != '\0' && i != len)
	{
		x = 0;
		if (haystack[i] == needle[x])
			while (needle[x] == haystack[i + x])
			{
				if (x + i > len)
					return (0);
				if (x == len2 - 1)
					return ((char*)haystack + i);
				x++;
			}
		i++;
	}
	return (0);
}
