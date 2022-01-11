/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redarnet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/21/08 14:08:34 by redarnet          #+#    #+#             */
/*   Updated: 2021/21/10 13:53:18 by redarnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	is_alone(t_indi *in, t_philo philo)
{
	if (philo.number_of_philo == 1)
	{
		affiche_time(in);
		printf("philo 1 has taken a fork\n");
		usleep(philo.time_to_die * 1000);
		affiche_time(in);
		printf("philo 1 died\n");
		return (0);
	}
	return (1);
}

int	message_return(char *str)
{
	printf("%s\n", str);
	return (0);
}

void	ft_clear(t_philo philo, t_indi *in)
{
	int	i;

	i = 0;
	while (i != philo.number_of_philo)
	{
		pthread_mutex_destroy(&philo.fork_t[i]);
		i++;
	}
	pthread_mutex_destroy(&philo.write);
	pthread_mutex_destroy(&philo.eat_check);
	free(philo.fork_t);
	free(in);
}
