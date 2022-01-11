/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redarnet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 09:48:16 by redarnet          #+#    #+#             */
/*   Updated: 2019/06/10 14:27:25 by redarnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_check_base(char *base)
{
	int	i;
	int	y;

	i = 0;
	if ((base[0] == '\0') || (base[1] == '\0'))
		return (0);
	while (base[i] != '\0')
	{
		y = i + 1;
		if (base[i] == '+' || base[i] == '-' || base[i]
			== ' ' || base[i] == '\f' || base[i]
			== '\t' || base[i] == '\n' || base[i]
			== '\r' || base[i] == '\v')
			return (0);
		while (base[y] != '\0')
		{
			if (base[y] == base[i])
				return (0);
			y++;
		}
		i++;
	}
	return (1);
}

int	value_base(char str, char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == str)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int		i;
	int		result;
	int		len;
	int		a;

	result = 0;
	a = -1;
	i = 0;
	len = 0;
	while (str[i] == ' ' || base[i] == '\t' | base[i] == '\n')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			a = -a;
		i++;
	}
	while (base[len] != '\0')
		len++;
	while (value_base(str[i], base) != -1)
	{
		result = result * len + value_base(str[i], base);
		i++;
	}
	return (-a * result);
}
