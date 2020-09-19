/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <ckakuna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 15:20:20 by ckakuna           #+#    #+#             */
/*   Updated: 2020/09/19 14:55:35 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "three.h"

/*
**============================================================================
** Набор функций для создания процесса.
**============================================================================
*/

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
			sem_wait(argv->philos[i++].eat_m);
		count++;
	}
	ft_print_mess(&argv->philos[0], END);
	sem_post(argv->who_dead);
	return (NULL);
}

void	*check_live(void *param)
{
	t_philo		*philo;

	philo = (t_philo*)param;
	while (1)
	{
		sem_wait(philo->sema);
		if (!philo->is_eat && ft_time_is() > philo->limit)
		{
			ft_print_mess(philo, DIED);
			sem_post(philo->sema);
			sem_post(philo->argv->who_dead);
			return (NULL);
		}
		sem_post(philo->sema);
		usleep(1000);
	}
	return (NULL);
}

int		threads_live(t_philo *philo)
{
	pthread_t	tid;

	philo->last_eat = ft_time_is();
	philo->limit = philo->last_eat + philo->argv->time_to_die;
	if (pthread_create(&tid, NULL, &check_live, philo))
		return (EXIT_FAILURE);
	if (pthread_detach(tid))
		return (EXIT_FAILURE);
	while (1)
	{
		ft_take_forks(philo);
		ft_eat(philo);
		ft_sleep(philo);
		ft_print_mess(philo, THINKING);
	}
	return (EXIT_SUCCESS);
}

int		start_threads(t_argv *argv)
{
	pthread_t	tid;

	if (argv->must_eat_end > 0)
	{
		if (pthread_create(&tid, NULL, &check_eat_end, argv) != 0)
			return (ERROR_THREAD);
		pthread_detach(tid);
	}
	return (0);
}

int		start_process(t_argv *argv)
{
	int		i;
	int		status;

	argv->start_time = ft_time_is();
	i = 0;
	while (i < argv->num_philo)
	{
		argv->philos[i].pid = fork();
		if (argv->philos[i].pid < 0)
			return (ERROR_PID);
		else if (argv->philos[i].pid == 0)
		{
			status = threads_live(&argv->philos[i]);
			exit(status);
		}
		else
			usleep(100);
		i++;
	}
	return (0);
}
