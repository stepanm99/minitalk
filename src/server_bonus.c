/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 18:20:31 by smelicha          #+#    #+#             */
/*   Updated: 2023/12/11 18:20:36 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minitalk_bonus.h"

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

t_s_data	val_set(t_s_data data, int num)
{
	if (num)
	{
		if (num - SIGUSR2)
			data.c += 0;
		else
			data.c += 1;
		data.i++;
	}
	else
	{
		kill(g_client_pid, SIGUSR2);
		data.client_pid_flag = 0;
		g_client_pid = 0;
		data.i = 0;
		data.c = '\0';
	}
	return (data);
}

void	handler(int num)
{
	static t_s_data	data;

	if (!data.client_pid_flag)
		data.client_pid_flag = get_client_pid(num);
	else
	{
		data = val_set(data, num);
		if (data.i == 8)
		{
			if (data.c != 4)
				write(1, &data.c, 1);
			else
			{
				data = val_set(data, 0);
				return ;
			}
			data.i = 0;
			data.c = '\0';
		}
		data.c = data.c << 1;
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
