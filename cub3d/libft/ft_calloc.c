/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redarnet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 08:40:39 by redarnet          #+#    #+#             */
/*   Updated: 2019/10/23 13:59:32 by redarnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned int	i;
	char			*str;
	unsigned int	y;

	i = nmemb * size;
	y = 0;
	if ((str = malloc(sizeof(char) * i)) == NULL)
		return (0);
	while (y != i)
	{
		str[y] = 0;
		y++;
	}
	return ((void*)str);
}
