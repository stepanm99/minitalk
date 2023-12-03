/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stepan <stepan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:21:21 by smelicha          #+#    #+#             */
/*   Updated: 2023/12/03 02:52:54 by stepan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minitalk.h"

int	g_bit_position;

void	print_world(int n)
{
	printf("world from server %i\n", n & 1);
}


void	handler(int	num)
{
	char	c;
	
	
}


void	clean(int n)
{
	exit(0);
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	printf("pid: %i\n", pid);
	while(1)
	{
		signal(SIGUSR1, handler);
		signal(SIGUSR2, handler);
		signal(SIGINT, clean);
	}
	return (0);
}

/*
int	main(void)
{
	struct sigaction *restrict	signal_action;
	pid_t				pid;

	signal_action->sa_handler = handler;
	pid = getpid();
	printf("pid: %i\n", pid);
	while (1)
	{
		sigaction(SIGUSR1, signal_action, NULL);
		sigaction(SIGUSR2, signal_action, NULL);
		usleep(100);
	}
	return (0);
}
*/
