/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <ckakuna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 11:09:20 by ckakuna           #+#    #+#             */
/*   Updated: 2020/09/14 16:58:36 by ckakuna          ###   ########.fr       */
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

/*
** Global value
*/

int					g_time;
int					g_status;
int					g_philo;
int					g_die;
int					g_eat;
int					g_sleep;
int					g_end;
int					g_index;
int					*g_forks;
struct timeval		g_start_time;
struct timeval		g_last_time;
pthread_mutex_t		g_waits;

/*
** part_1
*/

int					start_part_1(void);

/*
** Utils
*/

int					ft_strlen(char *str);
int					ft_atoi(char *str);
int					print_error(char *str);
char				*ft_itoa(int n);

#endif
