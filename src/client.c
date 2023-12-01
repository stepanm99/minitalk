/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:21:14 by smelicha          #+#    #+#             */
/*   Updated: 2023/12/01 19:46:06 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minitalk.h"

int	main(int argc, const char **argv)
{
	pid_t	pid;
	pid_t	server_pid;

	if (argc == 3)
	{
		server_pid = ft_atoi(argv[1]);
		if (ft_match(argv[2], "hello"))
			kill(server_pid, SIGUSR1);
		else if (ft_match(argv[2], "world"))
			kill(server_pid, SIGUSR2);
	}
	pid = getpid();
	printf("pid: %i\n", pid);
	return (0);
}