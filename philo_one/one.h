/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <ckakuna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 16:26:18 by ckakuna           #+#    #+#             */
/*   Updated: 2020/09/18 19:57:12 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H
# define PHILO_ONE_H
# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define RESET "\033[0m"
# define ERROR_VALUE 20
# define ERROR_THREAD 21
# define ERROR_MALLOC 22
# define ERROR_MUTEX 23

# include <pthread.h>
# include <sys/time.h>
# include <stdlib.h>
# include <unistd.h>

/*
**============================================================================
** Две структуры: с основными аргументами и персональной для философа.
** + нумерация статуса философа.
**============================================================================
*/

struct s_argv;

typedef enum		e_state
{
	THINKING, EATING, SLEEPING, DIED, TAKE_FORK, END
}					t_state;

typedef struct		s_philo
{
	int				index;
	int				is_eat;
	unsigned long	limit;
	unsigned long	last_eat;
	int				left_fork;
	int				right_fork;
	int				eat_count;
	struct s_argv	*argv;
	pthread_mutex_t	mutex;
	pthread_mutex_t	eat_m;
}					t_philo;

typedef struct		s_argv
{
	int				num_philo;
	unsigned long	time_to_die;
	unsigned long	time_to_eat;
	unsigned long	time_to_sleep;
	int				must_eat_end;
	unsigned long	start_time;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	who_write;
	pthread_mutex_t	who_dead;
}					t_argv;

/*
**============================================================================
** Костыль на ft_print_mess
**============================================================================
*/

int					g_dead;

/*
**============================================================================
** Функции для leaks.
**============================================================================
*/

void				clear_leaks(t_argv *argv);

/*
**============================================================================
** Функции для потоков.
**============================================================================
*/

int					start_threads(t_argv *argv);
unsigned long		ft_time_is(void);
void				ft_print_mess(t_philo *philo, t_state status);
void				ft_take_forks(t_philo *philo);
void				ft_sleep(t_philo *philo);
void				ft_eat(t_philo *philo);

/*
**============================================================================
** Функции для парсинга.
**============================================================================
*/

int					init_param(t_argv *argv, int ac, char **av);
size_t				ft_strlen(const char *str);
int					ft_atoi(const char *str);
char				*ft_strdup(const char *str);
char				*ft_itoa(unsigned long n);

#endif
