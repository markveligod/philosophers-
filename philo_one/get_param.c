/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_param.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <ckakuna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 16:53:08 by ckakuna           #+#    #+#             */
/*   Updated: 2020/09/18 15:18:17 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "one.h"

/*
**============================================================================
** Набор функций для парсинга стартовых аргументов.
** + иницилизация мьютексов.
**============================================================================
*/

int		get_philos(t_argv *argv)
{
	int i;

	i = 0;
	while (i < argv->num_philo)
	{
		argv->philos[i].index = i;
		argv->philos[i].is_eat = 0;
		argv->philos[i].left_fork = i;
		argv->philos[i].right_fork = (i + 1) % argv->num_philo;
		argv->philos[i].eat_count = 0;
		argv->philos[i].argv = argv;
		if (pthread_mutex_init(&argv->philos[i].mutex, NULL))
			return (ERROR_MUTEX);
		if (pthread_mutex_init(&argv->philos[i].eat_m, NULL))
			return (ERROR_MUTEX);
		pthread_mutex_lock(&argv->philos[i].eat_m);
		i++;
	}
	return (0);
}

int		init_mutex(t_argv *argv)
{
	int i;
	
	if (pthread_mutex_init(&argv->who_write, NULL))
		return (ERROR_MUTEX);
	if (pthread_mutex_init(&argv->who_dead, NULL))
		return (ERROR_MUTEX);
	pthread_mutex_lock(&argv->who_dead);
	if (!(argv->forks = (pthread_mutex_t*)malloc(sizeof(*(argv->forks)) * argv->num_philo)))
		return (ERROR_MALLOC);
	i = 0;
	while (i < argv->num_philo)
		if (pthread_mutex_init(&argv->forks[i++], NULL))
			return (ERROR_MUTEX);
	return (0);
}

int		init_param(t_argv *argv, int ac, char **av)
{
	int status;

	argv->num_philo = ft_atoi(av[1]);
	argv->time_to_die = ft_atoi(av[2]);
	argv->time_to_die = ft_atoi(av[3]);
	argv->time_to_sleep = ft_atoi(av[4]);
	argv->must_eat_end = (ac == 6) ? ft_atoi(av[5]) : 0;
	if (argv->num_philo < 2 || argv->num_philo > 200 || argv->time_to_die < 60
	|| argv->time_to_eat < 60 || argv->time_to_sleep < 60
	|| argv->must_eat_end < 0)
		return (ERROR_VALUE);
	argv->forks = NULL;
	argv->philos = NULL;
	if (!(argv->philos = (t_philo *)malloc(sizeof(t_philo) * argv->num_philo)))
		return(ERROR_MALLOC);
	if ((status = get_philos(argv)) != 0)
		return (status);
	if ((status = init_mutex(argv)) != 0 )
		return (status);
	return (0);
}
