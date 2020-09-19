/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_done.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <ckakuna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 17:15:10 by ckakuna           #+#    #+#             */
/*   Updated: 2020/09/19 14:56:45 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../three.h"

void	ft_take_forks(t_philo *philo)
{
	sem_wait(philo->argv->forks);
	ft_print_mess(philo, TAKE_FORK);
	sem_wait(philo->argv->forks);
	ft_print_mess(philo, TAKE_FORK);
}

void	ft_sleep(t_philo *philo)
{
	ft_print_mess(philo, SLEEPING);
	sem_post(philo->argv->forks);
	sem_post(philo->argv->forks);
	usleep(philo->argv->time_to_sleep * 1000);
}

void	ft_eat(t_philo *philo)
{
	sem_wait(philo->sema);
	philo->is_eat = 1;
	philo->last_eat = ft_time_is();
	philo->limit = philo->last_eat + philo->argv->time_to_die;
	ft_print_mess(philo, EATING);
	usleep(philo->argv->time_to_eat * 1000);
	philo->eat_count++;
	philo->is_eat = 0;
	sem_post(philo->sema);
	sem_post(philo->eat_m);
}
