/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <ckakuna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 11:09:20 by ckakuna           #+#    #+#             */
/*   Updated: 2020/09/15 13:05:52 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H
# define PHILO_ONE_H
# define RED "\033[1;31m"
# define YELLOW "\033[1;33m"
# define RESET "\033[0m"
# define ERROR_VALUE -1
# define ERROR_MALLOC -2

# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdlib.h>

# include <stdio.h> //delete

typedef enum
{
					THINKING, EATING, HUNGRY, SLEEPING, DIED, TAKE_FORK
}					t_state;

typedef struct		s_time
{
	int				time_to_eat;
	int				time_to_die;
	int				time_to_sleep;
	int				num_philo;
	int				num_eat;
}					t_time;

typedef struct		s_mutex
{
	pthread_mutex_t	*forks;
	pthread_mutex_t	*die_to_eat;
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
	t_time			*times;
	t_philo			*philos;
	t_mutex			*mut;
	int				alive;
}					t_ptr;

/*
** Param
*/

int					init_ptr_param(char **av, t_ptr *ptr, int ac);

/*
** Utils
*/

int					ft_strlen(char *str);
int					ft_atoi(char *str);
int					print_error(char *str, int err);
char				*ft_itoa(int n);
unsigned long		get_time(void);

#endif
