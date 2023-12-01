/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smelicha <smelicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:21:29 by smelicha          #+#    #+#             */
/*   Updated: 2023/12/01 21:22:45 by smelicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdio.h>	//delete before submission
#include "libft/libft.h"

typedef struct s_sdt {
	pid_t	pid;
	char	signal;
}	t_sdt;

typedef struct s_cdt {
	pid_t	pid;
}	t_cdt;