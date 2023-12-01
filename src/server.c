/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:21:21 by smelicha          #+#    #+#             */
/*   Updated: 2023/12/01 22:29:50 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minitalk.h"

void	print_hello(int n)
{
	printf("hello from server %i\n", n & 1);
}

void	print_world(int n)
{
	printf("world from server %i\n", n & 1);
}

void	listen(t_sdt *sdt)
{

}

void	broadcast(t_sdt *sdt)
{

}

void	handler(int	num)
{
	if (num & 1)
		write(1, "1", 1);
	else
		write(1, "0", 1);
}

int	main(void)
{
	struct sigaction	sa;
	t_sdt	*sdt;

	sdt = malloc(sizeof(t_sdt));
	if (!sdt)
		return (-1);
	sdt->pid = getpid();
	printf("pid: %i\n", sdt->pid);
	while (1)
	{
		signal(SIGUSR1, handler);
		signal(SIGUSR2, handler);
		usleep(100);
	}
	free(sdt);
	return (0);
}
