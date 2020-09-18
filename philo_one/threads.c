/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <ckakuna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 15:20:20 by ckakuna           #+#    #+#             */
/*   Updated: 2020/09/18 17:58:49 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "one.h"

void	*check_eat_end(void *param)
{
	t_argv	*argv;
	int		i;
	int		count;
	
	argv = (t_argv*)param;
	count = 0;
	while (count < argv->must_eat_end)
	{
		i = 0;
		while (i < argv->num_philo)
			pthread_mutex_lock(&argv->philos[i++].eat_m);
		count++;
	}
	ft_print_mess(&argv->philos[0], END);
	pthread_mutex_unlock(&argv->who_dead);
	return (NULL);
}

void	*check_live(void *param)
{
	t_philo		*philo;

	philo = (t_philo*)param;
	while (1)
	{
		pthread_mutex_lock(&philo->mutex);
		if (!philo->is_eat && ft_time_is() > philo->limit)
		{
			ft_print_mess(philo, DIED);
			pthread_mutex_unlock(&philo->mutex);
			pthread_mutex_unlock(&philo->argv->who_dead);
			return (NULL);
		}
		pthread_mutex_unlock(&philo->mutex);
		usleep(1000);
	}
	return (NULL);
}

void	*threads_live(void *param)
{
	t_philo		*philo;
	pthread_t	tid;
	
	philo = (t_philo*)param;
	philo->last_eat = ft_time_is();
	philo->limit = philo->last_eat + philo->argv->time_to_die;
	if (pthread_create(&tid, NULL, &check_live, philo))
		return (NULL);
	if (pthread_detach(tid))
		return (NULL);
	while (1)
	{
		ft_take_forks(philo);
		ft_eat(philo);
		ft_sleep(philo);
		ft_print_mess(philo, THINKING);
	}
	return (NULL);
}

int		start_threads(t_argv *argv)
{
	int			i;
	pthread_t	tid;
	void		*philo;

	argv->start_time = ft_time_is();
	if (argv->must_eat_end > 0)
	{
		if (pthread_create(&tid, NULL, &check_eat_end, argv))
			return (ERROR_THREAD);
		if (pthread_detach(tid))
			return (ERROR_THREAD);
	}
	i = 0;
	while (i < argv->num_philo)
	{
		philo = (void*)(&argv->philos[i]);
		if (pthread_create(&tid, NULL, &threads_live, philo))
			return (ERROR_THREAD);
		if (pthread_detach(tid))
			return (ERROR_THREAD);
		usleep(100);
		i++;
	}
	return (0);
}
