#ifndef CLIENT_H
# define CLIENT_H

# include <unistd.h>
# include <signal.h>

int		ft_isdigit(int c);
int		ft_atoi(const char *nptr);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *str, int fd);

#endif
