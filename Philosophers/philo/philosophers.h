/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redarnet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/21/08 14:08:34 by redarnet          #+#    #+#             */
/*   Updated: 2021/21/10 13:53:18 by redarnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>
# include <stdlib.h>
# include <pthread.h>

typedef struct s_philo
{
	int				number_of_philo;
	long int		time_to_die;
	pthread_mutex_t	*fork_t;
	int				i;
	int				run_nb;
	int				die;
	pthread_mutex_t	write;
	pthread_mutex_t	eat_check;
}					t_philo;

typedef struct s_indi
{
	int				id;
	int				count;
	pthread_t		thread_id;
	long int		last_eat;
	int				l_fork;
	int				r_fork;
	int				die;
	int				all_ate;
	long int		time_to_die;
	long int		time_to_eat;
	long int		time_to_sleep;
	long int		time_s;
	long int		time_m;
	t_philo			philo;
}				t_indi;

int			ft_atoi(const char *nptr);
void		*philo_thread(void *arg);
long int	time_begin(void);
void		affiche_time(t_indi *philo);
void		affiche_tab(int *tab, int i);
void		dead_thread(t_philo *philo, t_indi *in);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_strlen_nb(int nb);
void		affiche_time(t_indi *in);
void		eat(t_indi *in, t_philo philo);
void		leave_fork(t_indi *in, t_philo philo);
void		take_fork(t_indi *in, t_philo philo);
long int	time_rest(long int time, long int die);
void		print_message(t_indi *in, char *str, int i, t_philo philo);
void		ft_clear(t_philo philo, t_indi *in);
int			message_return(char *str);
int			verif_num(char **str, int i);
int			is_alone(t_indi *in, t_philo philo);

#endif
