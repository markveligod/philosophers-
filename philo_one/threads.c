/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <ckakuna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 13:57:41 by ckakuna           #+#    #+#             */
/*   Updated: 2020/09/15 13:37:27 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "one.h"

void	get_sleep(int num)
{
	unsigned long start;
	unsigned long passed;

	start = get_time();
	while (1)
	{
		passed = get_time() - start;
		if (passed >= (unsigned long)num)
			break ;
		usleep(200);
	}
}

void	try_fork(t_ptr *ptr, int index)
{
	pthread_mutex_lock(&ptr->mut->forks[index]);
	print_do(&(ptr->philos[index]), TAKE_FORK);
	pthread_mutex_lock(&ptr->mut->forks[(index + 1) % ptr->times->num_philo]);
	pthread_mutex_lock(&ptr->mut->die_to_eat[index]);
	print_do(&(ptr->philos[index]), TAKE_FORK);
	ptr->philos[index].last_eat = get_time();
	print_do(&(ptr->philos[index]), EATING);
	get_sleep(ptr->times->time_to_eat);
	pthread_mutex_unlock(&ptr->mut->die_to_eat[index]);
	pthread_mutex_unlock(&ptr->mut->forks[(index + 1) % ptr->times->num_philo]);
	pthread_mutex_unlock(&ptr->mut->forks[index]);
}

void	*thread_live(void *param)
{
	t_ptr *ptr;
	int index;

	index = g_index;
	ptr = (t_ptr *)param;
	while (1)
	{
		print_do(&(ptr->philos[index]), THINKING);
		try_fork(ptr, index);
		if (ptr->times->num_eat && ++ptr->philos[index].num_eat == ptr->times->num_eat)
			break ;
		print_do(&(ptr->philos[index]), SLEEPING);
		get_sleep(ptr->times->time_to_sleep);
	}
	
}