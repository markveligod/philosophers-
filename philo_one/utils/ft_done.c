/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_done.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <ckakuna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 17:15:10 by ckakuna           #+#    #+#             */
/*   Updated: 2020/09/18 17:29:35 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../one.h"

void	ft_take_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->argv->forks[philo->left_fork]);
	ft_print_mess(philo, TAKE_FORK);
	pthread_mutex_lock(&philo->argv->forks[philo->right_fork]);
	ft_print_mess(philo, TAKE_FORK);
}

void	ft_sleep(t_philo *philo)
{
	ft_print_mess(philo, SLEEPING);
	pthread_mutex_unlock(&philo->argv->forks[philo->left_fork]);
	pthread_mutex_unlock(&philo->argv->forks[philo->right_fork]);
	usleep(philo->argv->time_to_sleep * 1000);
}

void	ft_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->mutex);
	philo->is_eat = 1;
	philo->last_eat = ft_time_is();
	philo->limit = philo->last_eat + philo->argv->time_to_die;
	ft_print_mess(philo, EATING);
	usleep(philo->argv->time_to_eat * 1000);
	philo->eat_count++;
	philo->is_eat = 0;
	pthread_mutex_unlock(&philo->mutex);
	pthread_mutex_unlock(&philo->eat_m);
}
