/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:21:21 by smelicha          #+#    #+#             */
/*   Updated: 2023/12/04 22:05:54 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minitalk.h"

t_dts	*g_data;

void	print_world(int n)
{
	printf("world from server %i\n", n & 1);
}

void	handler(int	num)
{
	if (num - SIGUSR2)
	{
		g_data->c |= 0;
		write(1, "0", 1);
	}
	else
	{
		g_data->c |= 1;
		write(1, "1", 1);
	}
	g_data->i++;
	g_data->c = g_data->c << 1;
	if (g_data->i == 8)
	{
		g_data->c = g_data->c << 7;
		write(1, &g_data->c, 1);
		write(1, "\n", 1);
		g_data->i = 0;
		g_data->c = '\0';
	}
}

void	clean(int n)
{
	free(g_data);
	exit(0);
}

int	main(void)
{
	pid_t	pid;

	if (!g_data)
	{
		g_data = malloc(sizeof(t_dts));
		g_data->c = '\0';
		g_data->i = 0;
	}
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
