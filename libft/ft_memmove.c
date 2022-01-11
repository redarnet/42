/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redarnet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 08:50:52 by redarnet          #+#    #+#             */
/*   Updated: 2019/10/23 14:34:05 by redarnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*s1;
	unsigned char	*s2;
	size_t			i;

	s1 = (unsigned char*)dest;
	s2 = (unsigned char*)src;
	i = 0;
	if (!src || !dest)
		return (NULL);
	if (src > dest)
		while (i != n)
		{
			s1[i] = s2[i];
			i++;
		}
	else
		while (n != 0)
		{
			s1[n - 1] = s2[n - 1];
			n--;
		}
	dest = (void*)s1;
	return (dest);
}
