/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:21:29 by smelicha          #+#    #+#             */
/*   Updated: 2023/12/04 22:06:40 by smelicha         ###   ########.fr       */
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

typedef struct s_dts{
	int		i;
	int		c;
}	t_dts;


#endif