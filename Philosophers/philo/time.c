/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redarnet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/21/08 14:08:34 by redarnet          #+#    #+#             */
/*   Updated: 2021/21/10 13:53:18 by redarnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	affiche_time(t_indi *philo)
{
	struct timeval	start;
	long int		i;

	gettimeofday(&start, NULL);
	i = (start.tv_sec * 1000 + start.tv_usec / 1000)
		- (philo->time_s * 1000 + philo->time_m / 1000);
	printf("%ld ", i);
}

long int	time_begin(void)
{
	struct timeval	start;
	long int		i;

	i = 0;
	gettimeofday(&start, NULL);
	i = (start.tv_sec * 1000) + (start.tv_usec / 1000);
	return (i);
}

long int	time_rest(long int time, long int die)
{
	struct timeval	start;
	long int		i;
	long int		y;

	gettimeofday(&start, NULL);
	i = start.tv_sec * 1000 + start.tv_usec / 1000;
	y = i - time;
	if (die >= y)
		return (1);
	return (0);
}
