/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_param.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <ckakuna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 16:53:08 by ckakuna           #+#    #+#             */
/*   Updated: 2020/09/19 11:59:49 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "two.h"

/*
**============================================================================
** Набор функций для парсинга стартовых аргументов.
** + иницилизация семов.
**============================================================================
*/

int		get_philos(t_argv *argv)
{
	int		i;
	char	*index;

	i = 0;
	while (i < argv->num_philo)
	{
		argv->philos[i].index = i;
		argv->philos[i].is_eat = 0;
		argv->philos[i].eat_count = 0;
		argv->philos[i].argv = argv;
		index = ft_itoa(i);
		argv->philos[i].sema_name = ft_strjoin(SEMA_PHILO, index);
		sem_unlink(argv->philos[i].sema_name);
		if ((argv->philos[i].sema = sem_open(argv->philos[i].sema_name,
		O_CREAT | O_EXCL, 0644, 1)) == SEM_FAILED)
			return (ERROR_SEMA);
		argv->philos[i].sema_eat = ft_strjoin(SEMA_PHILOEAT, index);
		sem_unlink(argv->philos[i].sema_eat);
		if ((argv->philos[i].eat_m = sem_open(argv->philos[i].sema_eat,
		O_CREAT | O_EXCL, 0644, 0)) == SEM_FAILED)
			return (ERROR_SEMA);
		free(index);
		i++;
	}
	return (0);
}

int		init_sema(t_argv *argv)
{
	sem_unlink(SEMA_FORK);
	sem_unlink(SEMA_WRITE);
	sem_unlink(SEMA_DEAD);
	if ((argv->forks = sem_open(SEMA_FORK,
	O_CREAT | O_EXCL, 0644, argv->num_philo)) == SEM_FAILED)
		return (ERROR_SEMA);
	if ((argv->who_write = sem_open(SEMA_WRITE,
	O_CREAT | O_EXCL, 0644, 1)) == SEM_FAILED)
		return (ERROR_SEMA);
	if ((argv->who_dead = sem_open(SEMA_DEAD,
	O_CREAT | O_EXCL, 0644, 0)) == SEM_FAILED)
		return (ERROR_SEMA);
	return (0);
}

int		init_param(t_argv *argv, int ac, char **av)
{
	int status;

	argv->num_philo = ft_atoi(av[1]);
	argv->time_to_die = ft_atoi(av[2]);
	argv->time_to_eat = ft_atoi(av[3]);
	argv->time_to_sleep = ft_atoi(av[4]);
	argv->must_eat_end = (ac == 6) ? ft_atoi(av[5]) : 0;
	if (argv->num_philo < 2 || argv->num_philo > 200 || argv->time_to_die < 60
	|| argv->time_to_eat < 60 || argv->time_to_sleep < 60
	|| argv->must_eat_end < 0)
		return (ERROR_VALUE);
	argv->forks = NULL;
	argv->philos = NULL;
	argv->curr_eat = 0;
	if (!(argv->philos = (t_philo *)malloc(sizeof(t_philo) * argv->num_philo)))
		return (ERROR_MALLOC);
	if ((status = get_philos(argv)) != 0)
		return (status);
	if ((status = init_sema(argv)) != 0)
		return (status);
	return (0);
}
