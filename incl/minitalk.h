/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:21:29 by smelicha          #+#    #+#             */
/*   Updated: 2023/12/05 19:40:08 by smelicha         ###   ########.fr       */
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

/*
state_flag:
	0: receiving clinet PID -> 1
	1: receiving data size & allocating memory -> 2
	2: 
bit_pos: position of received bit in character
zeros: number of zeros in the received data
ones: number of ones in the received data
*/
typedef struct s_s_data
{
	pid_t	client_pid;
	int		state_flag;
	int		bit_pos;
	int		zeros;
	int		ones;
}	t_s_data;

/*

*/
typedef struct	s_c_data
{
	pid_t	server_pid;
	int		state_flag;
	int		zeros;
	int		ones;
	int		outgoing_data_size;
}	t_c_data;


#endif