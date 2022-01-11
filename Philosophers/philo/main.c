/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redarnet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/21/08 14:08:34 by redarnet          #+#    #+#             */
/*   Updated: 2021/21/10 13:53:18 by redarnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init_philo(t_indi *in, char **str, int y)
{
	int				i;
	struct timeval	start;

	i = 0;
	gettimeofday(&start, NULL);
	while (i != y)
	{
		in[i].time_s = start.tv_sec;
		in[i].time_m = start.tv_usec;
		in[i].time_to_eat = ft_atoi(str[3]);
		in[i].time_to_sleep = ft_atoi(str[4]);
		in[i].time_to_die = ft_atoi(str[2]);
		in[i].l_fork = i;
		in[i].r_fork = (i + 1) % y;
		in[i].last_eat = 0;
		in[i].id = i;
		in[i].count = 0;
		in[i].die = 1;
		in[i].all_ate = 1;
		i++;
	}
}

int	ft_thread_bis(t_indi *in, t_philo philo)
{
	int	i;

	i = 0;
	while (i != philo.number_of_philo)
	{
		if (pthread_join(in[i].thread_id, NULL) != 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_thread(t_indi *in, t_philo philo)
{
	int	i;

	i = 0;
	if (is_alone(in, philo) == 0)
		return (1);
	while (i < philo.number_of_philo)
	{
		in[i].philo = philo;
		in[i].last_eat = time_begin();
		if (pthread_create(&in[i].thread_id, NULL,
				philo_thread, &in[i]) != 0)
		{
			ft_clear(philo, in);
			return (0);
		}
		i++;
	}
	dead_thread(&philo, in);
	if (ft_thread_bis(in, philo) == 0)
	{
		ft_clear(philo, in);
		return (0);
	}
	return (1);
}

int	init_arg(t_philo *philo, char **argv, int argc)
{
	int	i;

	i = 0;
	philo->number_of_philo = ft_atoi(argv[1]);
	philo->time_to_die = ft_atoi(argv[2]);
	philo->die = 1;
	if (argc == 6)
		philo->run_nb = ft_atoi(argv[5]);
	else
		philo->run_nb = -1;
	philo->fork_t = NULL;
	philo->fork_t = malloc(sizeof(*(philo->fork_t)) * philo->number_of_philo);
	if (philo->fork_t == NULL)
	{
		return (0);
	}
	while (i != philo->number_of_philo)
	{
		if (pthread_mutex_init(&philo->fork_t[i], NULL))
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_philo		philo;
	t_indi		*in;

	if (argc != 5 && argc != 6)
		return (message_return("wrong number of arg"));
	if (verif_num(argv, argc) == 0)
		return (message_return("Arg error"));
	if (init_arg(&philo, argv, argc) == 0)
		return (message_return("init fail"));
	in = malloc(sizeof(t_indi) * philo.number_of_philo);
	if (in == NULL)
	{
		free(philo.fork_t);
		return (message_return("malloc fail"));
	}
	if (pthread_mutex_init(&philo.write, NULL))
		return (message_return("init fail"));
	if (pthread_mutex_init(&philo.eat_check, NULL))
		return (message_return("init fail"));
	init_philo(in, argv, philo.number_of_philo);
	if (ft_thread(in, philo) == 0)
		return (message_return("thread fail"));
	ft_clear(philo, in);
	return (0);
}
