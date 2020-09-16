/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <ckakuna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 11:57:01 by ckakuna           #+#    #+#             */
/*   Updated: 2020/09/16 16:00:17 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "two.h"

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
	sem_wait(ptr->sem->forks);
	print_do(philo, TAKE_FORK);
	sem_wait(ptr->sem->forks);
	print_do(philo, TAKE_FORK);
	sem_wait(ptr->sem->die_eat);
	philo->last_eat = get_time_is();
	print_do(philo, EATING);
	get_sleeping(ptr->times->time_to_eat);
	sem_post(ptr->sem->die_eat);
	sem_post(ptr->sem->forks);
	sem_post(ptr->sem->forks);
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
		if (get_time_is() - philo->last_eat > ptr->times->time_to_die
		&& ptr->alive)
		{
			sem_wait(ptr->sem->die_eat);
			ptr->alive = 0;
			print_do(philo, DIED);
			sem_post(ptr->sem->die_eat);
			free_ptr(ptr);
			break ;
		}
		get_sleeping(5);
	}
	return (NULL);
}
