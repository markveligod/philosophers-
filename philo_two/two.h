/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <ckakuna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 16:26:18 by ckakuna           #+#    #+#             */
/*   Updated: 2020/09/19 11:17:39 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_TWO_H
# define PHILO_TWO_H
# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define RESET "\033[0m"
# define ERROR_VALUE 20
# define ERROR_THREAD 21
# define ERROR_MALLOC 22
# define ERROR_SEMA 23
# define SEMA_FORK "Sema_Fork"
# define SEMA_WRITE "Sema_Write"
# define SEMA_DEAD "Sema_Dead"
# define SEMA_PHILO "Sema_Philo"
# define SEMA_PHILOEAT "Sema_Philo_Eat"

# include <pthread.h>
# include <sys/time.h>
# include <stdlib.h>
# include <unistd.h>
# include <semaphore.h>
# include <fcntl.h>

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
	int				eat_count;
	char			*sema_name;
	char			*sema_eat;
	struct s_argv	*argv;
	sem_t			*sema;
	sem_t			*eat_m;
}					t_philo;

typedef struct		s_argv
{
	int				num_philo;
	unsigned long	time_to_die;
	unsigned long	time_to_eat;
	unsigned long	time_to_sleep;
	int				must_eat_end;
	int				curr_eat;
	unsigned long	start_time;
	int				end_time;
	t_philo			*philos;
	sem_t			*forks;
	sem_t			*who_write;
	sem_t			*who_dead;
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
char				*ft_strjoin(char const *s1, char const *s2);

#endif
