/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:21:14 by smelicha          #+#    #+#             */
/*   Updated: 2023/12/11 18:20:20 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minitalk_bonus.h"

t_bit_counter	g_bit_counter;

void	send_pid(pid_t pid, pid_t server_pid)
{
	int	i;

	i = 32;
	while (i != -1)
	{
		if ((pid >> i) & 1)
			kill(server_pid, SIGUSR2);
		else
			kill(server_pid, SIGUSR1);
		usleep(DELAY);
		i--;
	}
}

void	send_string(const char *str, pid_t server_pid)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (str[i])
	{
		j = 7;
		c = str[i];
		while (j != -1)
		{
			if ((c >> j) & 1)
				kill(server_pid, SIGUSR2);
			else
				kill(server_pid, SIGUSR1);
			usleep(DELAY);
			j--;
		}
		i++;
	}
}

void	print_result(void)
{
	write(1, "\nbits sent: ", 12);
	print_number(g_bit_counter.sent, 1);
	write(1, "\nbits received: ", 16);
	print_number((g_bit_counter.received - 7), 1);
	write(1, "\n", 1);
	exit(0);
}

void	handler(int num)
{
	if (num - SIGUSR1)
		print_result();
	else
		g_bit_counter.received++;
}

int	main(int argc, const char **argv)
{
	pid_t	server_pid;
	pid_t	pid;
	char	c[2];

	c[0] = 4;
	c[1] = '\0';
	pid = getpid();
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	if (argc == 3)
	{
		server_pid = ft_atoi(argv[1]);
		g_bit_counter.sent = (ft_strlen(argv[2]) * 8);
		send_pid(pid, server_pid);
		send_string(argv[2], server_pid);
		send_string(c, server_pid);
	}
	return (0);
}
