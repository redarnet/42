/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redarnet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 11:34:49 by redarnet          #+#    #+#             */
/*   Updated: 2019/10/24 14:53:16 by redarnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count_word(char *str, char c)
{
	int i;
	int x;
	int d;

	i = 0;
	x = 1;
	d = 0;
	while (str[i] == c)
		i++;
	if ((str[1] == '\0' && str[0] == c) || str[0] == '\0')
		return (0);
	while (str[d] != '\0')
		d++;
	while (i < d)
	{
		if (str[i] == c)
			x++;
		while (str[i] == c && str[i + 1] != '\0')
			i++;
		i++;
	}
	if (str[d - 1] == c)
		return (x - 1);
	return (x);
}

void	ft_remplir_tab(char **result, char *str, char c, int d)
{
	int i;
	int y;
	int x;

	i = 0;
	y = 0;
	x = 0;
	while (str[i] == c)
		i++;
	while (i < d)
	{
		if (str[i] == c)
		{
			while (str[i] == c && str[i + 1] != '\0')
				i++;
			result[y][x] = '\0';
			y++;
			x = 0;
		}
		result[y][x] = str[i];
		x++;
		i++;
	}
	result[y][x] = '\0';
}

int		ft_malloc_tableau(char **result, char *str, char c, int i)
{
	int y;
	int x;

	x = 0;
	y = 0;
	while (str[i] == c)
		i++;
	while (str[i] != '\0')
	{
		if (str[i] == c)
		{
			if ((result[y] = malloc(sizeof(char) * x + 1)) == NULL)
				return (-1);
			while (str[i] == c && str[i + 1] != '\0')
				i++;
			y++;
			x = 0;
		}
		x++;
		i++;
	}
	if ((result[y] = malloc(sizeof(char) * x + 1)) == NULL)
		return (-1);
	return (y);
}

char	**ft_split(char const *s, char c)
{
	int		y;
	int		x;
	int		d;
	char	**result;

	y = 0;
	d = 0;
	if (!s)
		return (NULL);
	if (*s == 0)
	{
		if ((result = malloc(sizeof(char*) * 1)) == NULL)
			return (0);
		result[0] = NULL;
		return (result);
	}
	d = ft_strlen(s);
	x = ft_count_word((char*)s, c);
	if ((result = malloc(sizeof(char*) * x + 10)) == NULL)
		return (0);
	if ((y = ft_malloc_tableau(result, (char*)s, c, 0)) == -1)
		return (0);
	ft_remplir_tab(result, (char*)s, c, d);
	result[x] = NULL;
	return (result);
}
