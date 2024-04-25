/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robernar <robernar@student.42.rj>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:34:22 by robernar          #+#    #+#             */
/*   Updated: 2024/04/23 18:34:24 by robernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

void	signal_action(int pid, char *str)
{
	int	i;
	int	c;

	i = 0;
	while (*str)
	{
		c = *(str);
		while (i < 8)
		{
			if (c << i & 0b10000000)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			i++;
			usleep(100);
		}
		str++;
		i = 0;
	}
}

int	main(int argc, char **argv)
{
	(void) argc;
	(void) argv;
	if (argc != 3)
	{
		ft_printf("Invalid number of arguments.\n");
		ft_printf("Usage: %s <server_pid> <message>\n", argv[0]);
		exit(1);
	}
	signal_action(ft_atoi(argv[1]), argv[2]);
	return (0);
}
