/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redarnet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/21/08 14:08:34 by redarnet          #+#    #+#             */
/*   Updated: 2021/21/10 13:53:18 by redarnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int	ft_is_num(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) != 1)
			return (0);
		i++;
	}
	return (1);
}

void	send_signal(char c, int server_pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c & (1 << i))
			kill(server_pid, SIGUSR2);
		else
			kill(server_pid, SIGUSR1);
		usleep(100);
		i++;
	}
}

void	ft_send_signal(char *str, int server_pid)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		send_signal(str[i], server_pid);
		i++;
	}
	send_signal(str[i], server_pid);
}

int	main(int argc, char **argv)
{
	int	server_pid;

	if (argc != 3)
	{
		ft_putstr_fd("Argument error", 1);
		return (0);
	}
	if (ft_is_num(argv[1]) == 0)
	{
		ft_putstr_fd("Wrong input", 1);
		return (0);
	}
	server_pid = ft_atoi(argv[1]);
	ft_send_signal(argv[2], server_pid);
	return (0);
}
