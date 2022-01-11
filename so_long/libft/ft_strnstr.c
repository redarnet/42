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
	size_t	i[2];
	size_t	len2;

	i[1] = 0;
	len2 = 0;
	if (*needle == 0)
		return ((char *)(haystack));
	len2 = ft_strlen(needle);
	while (haystack[i[1]] != '\0' && i[1] != len)
	{
		i[0] = 0;
		if (haystack[i[1]] == needle[i[0]])
		{
			while (needle[i[0]] == haystack[i[1] + i[0]])
			{
				if (i[0] + i[1] > len)
					return (0);
				if (i[0] == len2 - 1)
					return ((char *)haystack + i[1]);
				i[0]++;
			}
		}
		i[1]++;
	}
	return (0);
}
