/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_param.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <ckakuna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 16:53:08 by ckakuna           #+#    #+#             */
/*   Updated: 2020/09/16 16:04:48 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "one.h"

t_argv	*init_times(char **av)
{
	t_argv *argv;

	if (!(argv = (t_argv *)malloc(sizeof(t_argv))))
		return (NULL);
	argv->num_ph = ft_atoi(av[1]);
	argv->time_to_die = ft_atoi(av[2]);
	argv->time_to_eat = ft_atoi(av[3]);
	argv->time_to_sleep = ft_atoi(av[4]);
	if (av[5])
		argv->num_eat = ft_atoi(av[5]);
	return (argv);
}

t_philo	*init_philos(int nb_philos)
{
	t_philo	*philos;
	t_ptr	*ptr;
	int		i;

	i = 0;
	ptr = get_ptr();
	ptr->num_philo = ptr->times->num_ph;
	ptr->alive = 1;
	if (!(philos = (t_philo*)malloc(sizeof(t_philo) * nb_philos)))
		return (NULL);
	while (i < nb_philos)
	{
		philos[i].index = i;
		philos[i].num_eat = 0;
		philos[i].start = get_time_is();
		philos[i].last_eat = get_time_is();
		i++;
	}
	return (philos);
}

t_mutex	*init_mutex(int num_philos)
{
	t_mutex	*mutex;
	int		i;

	i = 0;
	if (!(mutex = (t_mutex *)malloc(sizeof(t_mutex))))
		return (NULL);
	if (!(mutex->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
	* (num_philos + 1))))
		return (NULL);
	if (!(mutex->die_eat = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
	* num_philos)))
		return (NULL);
	while (++i < num_philos)
		if (pthread_mutex_init(&mutex->forks[i], NULL) ||
		pthread_mutex_init(&mutex->die_eat[i], NULL))
			return (NULL);
	return (mutex);
}

t_ptr	*get_ptr(void)
{
	static t_ptr ptr;

	return (&ptr);
}

t_ptr	*init_param(char **av)
{
	t_ptr *ptr;

	ptr = get_ptr();
	ptr->times = init_times(av);
	ptr->philos = init_philos(ptr->times->num_ph);
	ptr->mutex = init_mutex(ptr->times->num_ph);
	return (ptr);
}
