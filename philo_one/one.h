/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <ckakuna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 16:26:18 by ckakuna           #+#    #+#             */
/*   Updated: 2020/09/16 10:21:06 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H
# define PHILO_ONE_H
# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define RESET "\033[0m"
# define ERROR_VALUE -1
# define ERROR_MALLOC -2
# define ERROR_MUTEX -3
# define ERROR_THREAD -4

# include <pthread.h>
# include <sys/time.h>
# include <stdio.h> //delete
# include <stdlib.h>
# include <unistd.h>

typedef enum {
					THINKING, EATING, SLEEPING, DIED, TAKE_FORK
}					t_state;

typedef struct		s_argv
{
	unsigned long	time_to_eat;
	unsigned long	time_to_die;
	unsigned long	time_to_sleep;
	int				num_ph;
	int				num_eat;
}					t_argv;

typedef struct		s_mutex
{
	pthread_mutex_t	*forks;
	pthread_mutex_t	*die_eat;
}					t_mutex;

typedef struct		s_philo
{
	int				index;
	unsigned long	start;
	int				num_eat;
	unsigned long	last_eat;
	pthread_t		live;
	pthread_t		check;
}					t_philo;

typedef struct		s_ptr
{
	t_argv			*times;
	t_philo			*philos;
	t_mutex			*mutex;
	int				num_philo;
	int				alive;
}					t_ptr;

/*
** Threads
*/

void				*threads_check(void *philo);
void				*threads_live(void *philo);

/*
** Get param
*/

t_ptr				*get_ptr(void);
t_ptr				*init_param(char **av);
void				free_ptr(t_ptr *ptr);

/*
** Utils
*/

unsigned long		get_time_is(void);
char				*ft_itoa(unsigned long n);
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlen(const char *str);
int					ft_atoi(const char *str);
char				*ft_strdup(const char *s1);
int					ft_len(unsigned long nb);
void				print_do(t_philo *philo, t_state status);

#endif
