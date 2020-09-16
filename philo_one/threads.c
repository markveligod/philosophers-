/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <ckakuna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 11:56:52 by ckakuna           #+#    #+#             */
/*   Updated: 2020/09/16 16:04:24 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "one.h"

void	get_sleeping(int n)
{
	unsigned long start;
	unsigned long passed;

	start = get_time_is();
	while (1)
	{
		passed = get_time_is() - start;
		if (passed >= (unsigned long)n)
			break ;
		usleep(200);
	}
}

int		try_fork(t_philo *philo)
{
	t_ptr *ptr;

	ptr = get_ptr();
	pthread_mutex_lock(&ptr->mutex->forks[philo->index]);
	print_do(philo, TAKE_FORK);
	pthread_mutex_lock(&ptr->mutex->forks[(philo->index + 1)
	% ptr->times->num_ph]);
	pthread_mutex_lock(&ptr->mutex->die_eat[philo->index]);
	print_do(philo, TAKE_FORK);
	philo->last_eat = get_time_is();
	print_do(philo, EATING);
	get_sleeping(ptr->times->time_to_eat);
	pthread_mutex_unlock(&ptr->mutex->die_eat[philo->index]);
	pthread_mutex_unlock(&ptr->mutex->forks[philo->index]);
	pthread_mutex_unlock(&ptr->mutex->forks[(philo->index + 1)
	% ptr->times->num_ph]);
	return (1);
}

void	*threads_live(void *args)
{
	t_ptr	*ptr;
	t_philo	*philo;

	ptr = get_ptr();
	philo = (t_philo*)args;
	while (1)
	{
		print_do(philo, THINKING);
		try_fork(philo);
		if (ptr->times->num_eat && ++philo->num_eat == ptr->times->num_eat)
			break ;
		print_do(philo, SLEEPING);
		get_sleeping(ptr->times->time_to_sleep);
	}
	ptr->num_philo--;
	return (NULL);
}

void	*threads_check(void *args)
{
	t_ptr	*ptr;
	t_philo	*philo;

	ptr = get_ptr();
	philo = (t_philo*)args;
	while (42)
	{
		pthread_mutex_lock(&ptr->mutex->die_eat[philo->index]);
		if (get_time_is() - philo->last_eat > ptr->times->time_to_die
		&& ptr->alive)
		{
			ptr->alive = 0;
			print_do(philo, DIED);
			free_ptr(ptr);
			break ;
		}
		pthread_mutex_unlock(&ptr->mutex->die_eat[philo->index]);
		get_sleeping(5);
	}
	return (NULL);
}
