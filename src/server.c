/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:21:21 by smelicha          #+#    #+#             */
/*   Updated: 2023/12/01 19:24:15 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minitalk.h"

void	print_hello(void)
{
	printf("hello from server\n");
}

void	print_world(void)
{
	printf("world from server\n");
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	printf("pid: %i\n", pid);
	while (1)
	{
		signal(SIGUSR1, &print_hello);
		signal(SIGUSR2, &print_world);
		usleep(1000);
	}
	return (0);
}