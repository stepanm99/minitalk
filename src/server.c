/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:21:21 by smelicha          #+#    #+#             */
/*   Updated: 2023/12/08 19:38:20 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minitalk.h"

int	g_client_pid;

void	print_number(int n, int fd)
{
	int		i;
	int		a[11];
	char	c;

	i = 0;
	c = 0;
	if (n == 0)
		write(fd, "0", 1);
	while (n != 0)
	{
		a[i] = n % 10;
		n = n / 10;
		i++;
	}
	i--;
	while (i >= 0)
	{
		c = a[i] + '0';
		i--;
		write(fd, &c, 1);
	}
}

int	get_client_pid(int num)
{
	static int	i;

	if (num - SIGUSR2)
		g_client_pid += 0;
	else
		g_client_pid += 1;
	i++;
	if (i == 33)
	{
		i = 0;
		return (1);
	}
	g_client_pid = g_client_pid << 1;
	printf("\nclient pid: %i\n", g_client_pid);
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
				client_pid_flag = 0;
				g_client_pid = 0;
			}
			i = 0;
			c = '\0';
		}
		c = c << 1;
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
