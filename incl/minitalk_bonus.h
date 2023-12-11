/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:21:29 by smelicha          #+#    #+#             */
/*   Updated: 2023/12/11 18:29:23 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <unistd.h>
# include <signal.h>
# include <sys/types.h>
# include <stdlib.h>

# ifndef DELAY
#  define DELAY 1000
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