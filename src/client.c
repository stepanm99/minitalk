/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:21:14 by smelicha          #+#    #+#             */
/*   Updated: 2023/12/11 19:52:37 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minitalk.h"

int	ft_atoi(const char *str)
{
	size_t	i;
	int		negflag;
	int		n;

	i = 0;
	n = 0;
	negflag = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i + 1] == '-' || str[i + 1] == '+')
			return (0);
		if (str[i] == '-')
			negflag = (-1);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + (str[i] - '0');
		i++;
	}
	return (n * negflag);
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

int	main(int argc, const char **argv)
{
	pid_t	server_pid;

	if (argc == 3)
	{
		server_pid = ft_atoi(argv[1]);
		send_string(argv[2], server_pid);
	}
	return (0);
}
