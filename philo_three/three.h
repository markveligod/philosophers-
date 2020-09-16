/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <ckakuna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 16:26:18 by ckakuna           #+#    #+#             */
/*   Updated: 2020/09/16 15:03:58 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_THREE_H
# define PHILO_THREE_H
# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define RESET "\033[0m"
# define ERROR_VALUE -1
# define ERROR_THREAD -2

# include <pthread.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <semaphore.h>
# include <signal.h>
# include <sys/types.h>

# include <stdio.h> //delete

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

typedef struct		s_sem
{
	sem_t			*forks;
	sem_t			*die_eat;
}					t_sem;

typedef struct		s_philo
{
	int				index;
	unsigned long	start;
	int				num_eat;
	unsigned long	last_eat;
	pthread_t		check;
	pthread_t		live;
}					t_philo;

typedef struct		s_ptr
{
	t_argv			*times;
	t_philo			*philos;
	t_sem			*sem;
	pid_t			pid;
	int				num_philo;
	int				alive;
}					t_ptr;

/*
** Threads
*/

void				*threads_check(void *philo);
void				*threads_live(void *param);

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
