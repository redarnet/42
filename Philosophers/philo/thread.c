/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redarnet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/21/08 14:08:34 by redarnet          #+#    #+#             */
/*   Updated: 2021/21/10 13:53:18 by redarnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	eat_all(t_indi *in, t_philo philo, int i)
{
	int	x;

	x = 0;
	if (philo.run_nb == -1)
		return (0);
	while (i != philo.number_of_philo)
	{
		if (in[i].count >= philo.run_nb)
		{
			x++;
			if (x == (philo.number_of_philo))
			{
				i = 0;
				while (i != philo.number_of_philo)
				{
					in[i].all_ate = 45;
					i++;
				}
				return (1);
			}
		}
		i++;
	}
	return (0);
}

void	print_message(t_indi *in, char *str, int i, t_philo philo)
{
	int			x;
	static int	end;

	if (i != -1)
		x = i + 1;
	else
		x = in->id + 1;
	if (end != 1)
	{
		pthread_mutex_lock(&philo.write);
		if (ft_strncmp(str, "died", 4) == 0)
			end = 1;
		affiche_time(in);
		printf("philo %d %s \n", x, str);
		pthread_mutex_unlock(&philo.write);
	}
}

void	dead_thread_bis(t_philo philo, t_indi *in, int i)
{
	int	x;

	pthread_mutex_lock(&philo.eat_check);
	philo.die = 0;
	x = 0;
	while (x != philo.number_of_philo)
	{
		in[x].die = 45;
		x++;
	}
	print_message(in, "died", i, philo);
	pthread_mutex_unlock(&philo.eat_check);
}

void	dead_thread(t_philo *philo, t_indi *in)
{
	int	i;
	int	x;

	x = 0;
	while (philo->die != 0)
	{
		i = 0;
		while (i != philo->number_of_philo)
		{
			if (time_rest(in[i].last_eat, philo->time_to_die) == 0)
			{
				dead_thread_bis(*philo, in, i);
				return ;
			}
			i++;
		}
		if (eat_all(in, *philo, 0) == 1)
			return ;
		usleep(100);
	}
}

void	*philo_thread(void *arg)
{
	t_indi	*in;
	t_philo	philo;

	in = (t_indi *)arg;
	philo = in->philo;
	if (in->id % 2)
		usleep(1500);
	in->die = 1;
	in->all_ate = 1;
	while (in->die != 45 && in->all_ate != 45)
	{
		take_fork(in, philo);
		eat(in, philo);
		leave_fork(in, philo);
		if (in->all_ate != 45)
			print_message(in, "is thinking", -1, philo);
	}
	return (NULL);
}
