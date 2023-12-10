/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stepan <stepan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:21:21 by smelicha          #+#    #+#             */
/*   Updated: 2023/12/10 02:28:41 by stepan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minitalk.h"

int	g_client_pid;

int	get_client_pid(int num)
{
	static int	i;

	if (num - SIGUSR2)
	{
		g_client_pid += 0;
	}
	else
	{
		g_client_pid += 1;
	}
	if (i == 32)
	{
		i = 0;
		return (1);
	}
	i++;
	g_client_pid = g_client_pid << 1;
	return (0);
}

void	handler(int num)
{
	static char	c;
	static int	i;
	static int	client_pid_flag;

	if (!client_pid_flag)
		client_pid_flag = get_client_pid(num);
	else
	{
		if (num - SIGUSR2)
			c += 0;
		else
			c += 1;
		i++;
		if (i == 8)
		{
			if (c != 4)
				write(1, &c, 1);
			else
			{
				kill(g_client_pid, SIGUSR2);
				client_pid_flag = 0;
				g_client_pid = 0;
				i = 0;
				c = '\0';
				return ;
			}
			i = 0;
			c = '\0';
		}
		c = c << 1;
		kill(g_client_pid, SIGUSR1);
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	print_number(pid, 1);
	write(1, "\n", 1);
	while (1)
	{
		signal(SIGUSR1, handler);
		signal(SIGUSR2, handler);
		usleep(50);
	}
	return (0);
}
