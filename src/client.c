/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:21:14 by smelicha          #+#    #+#             */
/*   Updated: 2023/12/04 20:11:11 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minitalk.h"

void	send_pid(pid_t pid, pid_t server_pid)
{
	int	i;
	int	kill_ret;

	i = 32;
	kill_ret = -1;
	while (i != -1)
		{
			if ((pid >> i) & 1)
				kill_ret = kill(server_pid, SIGUSR2);
			else
				kill_ret = kill(server_pid, SIGUSR1);
			usleep(500);
			i--;
		}
}

void	send_character(char c, pid_t server_pid)
{
	int		i;

	i = 7;
	while (i != -1)
	{
		if ((c >> i) & 1)
			kill(server_pid, SIGUSR2);
		else
			kill(server_pid, SIGUSR1);
		usleep(500);
		i--;
	}
}

void	send_string(const char *str, pid_t server_pid)
{
	int	i;

	i = 0;
	while (str[i])
	{
		send_character(str[i], server_pid);
		i++;
	}
}

int	main(int argc, const char **argv)
{
	pid_t	server_pid;

	if (argc == 3)
	{
		server_pid = ft_atoi(argv[1]);
		send_string(argv[2], server_pid);
		// if (ft_match(argv[2], "0"))
		// 	kill(server_pid, SIGUSR1);
		// else if (ft_match(argv[2], "1"))
		// 	kill(server_pid, SIGUSR2);
	}
//	send_pid(pid, server_pid);
	return (0);
}
