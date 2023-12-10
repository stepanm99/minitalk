/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stepan <stepan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:21:29 by smelicha          #+#    #+#             */
/*   Updated: 2023/12/10 03:29:04 by stepan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# define _XOPEN_SOURCE 500
# include <signal.h>
# include <sys/types.h>
# include <locale.h>
# include <wchar.h>
# include <stdio.h>
# include <stdlib.h>

# ifndef DELAY
#  define DELAY 10000
# endif

typedef struct s_s_data
{
	char	c;
	int		i;
	char	client_pid_flag;
}	t_s_data;

typedef struct s_bit_counters
{
	int	sent;
	int	received;
}	t_bit_counter;

void	print_number(int n, int fd);
int		ft_atoi(const char *str);
int		ft_strlen(const char *str);

#endif