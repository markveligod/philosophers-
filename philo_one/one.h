/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <ckakuna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 11:09:20 by ckakuna           #+#    #+#             */
/*   Updated: 2020/09/13 17:43:01 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H
# define PHILO_ONE_H
# define RED "\033[1;31m"
# define YELLOW "\033[1;33m"
# define RESET "\033[0m"

#include <pthread.h>
#include <sys/time.h>
#include <unistd.h>
#include <stdlib.h>

# include <stdio.h>

typedef struct		s_argv
{
	unsigned int	philo;
	unsigned int	die;
	unsigned int	eat;
	unsigned int	sleep;
	unsigned int	end;
	pthread_mutex_t *forks;
}					t_argv;

typedef struct		s_philo
{
	unsigned int	index;
	unsigned int	status;
	int				is_die;
}					t_philo;

typedef struct		s_global
{
	t_argv			*argv;
}					t_global;

/*
** Global value
*/

unsigned int		g_time;

/*
** parsing
*/

int					pars_argv(t_global *global, char **av, int ac);

/*
** Utils
*/

int					ft_strlen(char *str);
int					ft_atoi(char *str);
int					print_error(char *str);

#endif
