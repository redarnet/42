/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redarnet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/21/08 14:08:34 by redarnet          #+#    #+#             */
/*   Updated: 2021/21/10 13:53:18 by redarnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	take_fork(t_indi *in, t_philo philo)
{
	if (in->id % 2 == 0)
	{
		pthread_mutex_lock(&philo.fork_t[in->l_fork]);
		pthread_mutex_lock(&philo.fork_t[in->r_fork]);
	}
	else
	{
		pthread_mutex_lock(&philo.fork_t[in->r_fork]);
		pthread_mutex_lock(&philo.fork_t[in->l_fork]);
	}
	if (in->all_ate != 45)
	{
		print_message(in, "has taken a fork", -1, philo);
		print_message(in, "has taken a fork", -1, philo);
	}
}

void	wait_time(t_indi *in, int y)
{
	long int	i;

	i = time_begin() + y;
	while (time_begin() < i)
	{
		usleep(500);
		if (in->die == 45)
			break ;
		if (in->all_ate == 45)
			break ;
	}
}

void	leave_fork(t_indi *in, t_philo philo)
{
	if (in->id % 2 == 0)
	{
		pthread_mutex_unlock(&philo.fork_t[in->l_fork]);
		pthread_mutex_unlock(&philo.fork_t[in->r_fork]);
	}
	else
	{
		pthread_mutex_unlock(&philo.fork_t[in->r_fork]);
		pthread_mutex_unlock(&philo.fork_t[in->l_fork]);
	}
	if (in->all_ate != 45)
		print_message(in, "is sleeping", -1, philo);
	pthread_mutex_lock(&philo.eat_check);
	in->last_eat = time_begin();
	pthread_mutex_unlock(&philo.eat_check);
	wait_time(in, in[0].time_to_sleep);
}

void	eat(t_indi *in, t_philo philo)
{
	if (in->all_ate != 45)
		print_message(in, "is eating", -1, philo);
	wait_time(in, in[0].time_to_eat);
	in->count = in->count + 1;
}
