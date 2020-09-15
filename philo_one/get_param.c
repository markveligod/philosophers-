/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_param.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <ckakuna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 11:47:48 by ckakuna           #+#    #+#             */
/*   Updated: 2020/09/15 13:39:55 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "one.h"

int		get_time_param(t_ptr *ptr, char **av, int ac)
{
	if (!(ptr->times = (t_time *)malloc(sizeof(t_time))))
		return (ERROR_MALLOC);
	if (!(ptr->times->num_philo = ft_atoi(av[1])))
		return (ERROR_VALUE);
	if (!(ptr->times->time_to_die = ft_atoi(av[2])))
		return (ERROR_VALUE);
	if (!(ptr->times->time_to_eat = ft_atoi(av[3])))
		return (ERROR_VALUE);
	if (!(ptr->times->time_to_sleep = ft_atoi(av[4])))
		return (ERROR_VALUE);
	if (ac == 6)
		if (!(ptr->times->num_eat = ft_atoi(av[5])))
			return (ERROR_VALUE);
	else if (ac == 5)
		ptr->times->num_eat = 0;
	return (0);
}

int		get_philo_param(t_ptr *ptr)
{
	int i;

	if (!(ptr->philos = (t_philo *)malloc(sizeof(t_philo) * ptr->times->num_philo)))
		return (ERROR_MALLOC);
	i = 0;
	while (i < ptr->times->num_philo)
	{
		ptr->philos[i].index = i;
		ptr->philos[i].num_eat = ptr->times->num_eat;
		ptr->philos[i].start = get_time();
		ptr->philos[i].last_eat = get_time();
		i++;
	}
	return (0);
}

int		get_mutex_param(t_ptr *ptr)
{
	int i;

	if (!(ptr->mut = (t_mutex *)malloc(sizeof(t_mutex))))
		return (ERROR_MUTEX);
	if (!(ptr->mut->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * (ptr->times->num_philo + 1))))
		return (ERROR_MUTEX);
	if (!(ptr->mut->die_to_eat = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * ptr->times->num_philo)))
		return (ERROR_MUTEX);
	i = 0;
	while (++i < ptr->times->num_philo)
	{
		if (pthread_mutex_init(&ptr->mut->forks[i], NULL) || pthread_mutex_init(&ptr->mut->die_to_eat[i], NULL))
			return (ERROR_MUTEX);
	}
	return (0);
}

int		init_ptr_param(char **av, t_ptr *ptr, int ac)
{
	int rec;

	ptr->times = NULL;
	ptr->philos = NULL;
	ptr->mut = NULL;
	ptr->alive = 1;
	if ((rec = get_time_param(ptr, av, ac)) < 0)
		return (rec);
	if ((rec = get_philo_param(ptr)) < 0)
		return (rec);
	if ((rec = get_mutex_param(ptr)) < 0)
		return (rec);
	return (0);
}
