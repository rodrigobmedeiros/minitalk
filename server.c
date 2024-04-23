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

int main(int argc, char **argv)
{
    int pid;

    (void) argc;
    (void) argv;
    pid = getpid();
    ft_printf("Welcome to server: <%d>\n", pid);
    while (1)
}
