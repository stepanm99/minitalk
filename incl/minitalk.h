/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stepan <stepan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:21:29 by smelicha          #+#    #+#             */
/*   Updated: 2023/12/03 02:25:55 by stepan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

#include <unistd.h>
#include <stdio.h>	//delete before submission
#include "libft/libft.h"

#define _XOPEN_SOURCE 500
#include <signal.h>
#include <sys/types.h>


/*
state:
	0 - receiving client PID && ask client for size-> 1
	1 - receiving data size -> 2
	2 - allocating data size && ask client for data->3
	3 - receiving data -> 4
	4 - printing data -> 5
	5 - freeing data -> 6
	6 - sending confirmation to client && zeroing client PID -> 0
*/
typedef struct s_dts{
	int				state;
	unsigned int	data_size;
	void			*data;
	pid_t			client_pid;
}	t_dts;


#endif