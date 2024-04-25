/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robernar <robernar@student.42.rj>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:34:22 by robernar          #+#    #+#             */
/*   Updated: 2024/04/23 18:34:24 by robernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

void	handler(int sig)
{
	static int				i;
	static unsigned char	c;
	static int				first_time;

	if (!first_time)
	{
		first_time = 1;
		i = 0;
		c = 0;
	}
	if (sig == SIGUSR2)
		c = c << 1;
	else if (sig == SIGUSR1)
		c = (c << 1) | 0b00000001;
	i++;
	if (i == 8)
	{
		ft_printf("%c", c);
		i = 0;
		c = 0;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	(void) argc;
	(void) argv;
	pid = getpid();
	ft_printf("Welcome to server: <%d>\n", pid);
	while (1)
	{
		signal(SIGUSR1, handler);
		signal(SIGUSR2, handler);
	}
}
