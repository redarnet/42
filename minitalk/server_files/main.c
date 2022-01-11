/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redarnet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 14:08:34 by redarnet          #+#    #+#             */
/*   Updated: 2019/10/23 13:53:18 by redarnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar_fd(str[i], 1);
		i++;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		if (n < -2147483647)
		{
			ft_putchar_fd('2', fd);
			ft_putnbr_fd(1474483648, fd);
		}
		else
			ft_putnbr_fd(-n, fd);
	}
	else if (n >= 0 && n <= 9)
		ft_putchar_fd(n + 48, fd);
	else
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
}

void	receive_signal(int signal_number)
{
	static int	bit;
	static char	c;

	if (signal_number == SIGUSR2)
	{
		c |= (1 << bit);
	}
	bit++;
	if (bit == 8)
	{
		ft_putchar_fd(c, 1);
		bit = 0;
		c = 0;
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_putstr_fd("Server PID\n", 1);
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
	while (1)
	{
		if (signal(SIGUSR1, receive_signal) == SIG_ERR)
			return (0);
		if (signal(SIGUSR2, receive_signal) == SIG_ERR)
			return (0);
		if (pause() != -1)
			return (0);
	}
	return (0);
}
