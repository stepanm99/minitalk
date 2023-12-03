/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stepan <stepan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:21:14 by smelicha          #+#    #+#             */
/*   Updated: 2023/12/02 23:28:06 by stepan           ###   ########.fr       */
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
//			printf("%i", (pid >> i) & 1);
			if ((pid >> i) & 1)
				kill_ret = kill(server_pid, SIGUSR2);
			else
				kill_ret = kill(server_pid, SIGUSR1);
			usleep(500);
			i--;
		}
}

int	main(int argc, const char **argv)
{
	pid_t	pid;
	pid_t	server_pid;

	if (argc == 3)
	{
		server_pid = ft_atoi(argv[1]);
		if (ft_match(argv[2], "0"))
			kill(server_pid, SIGUSR1);
		else if (ft_match(argv[2], "1"))
			kill(server_pid, SIGUSR2);
	}
	pid = getpid();
//	send_pid(pid, server_pid);
	printf("pid: %i\n", pid);
	return (0);
}
