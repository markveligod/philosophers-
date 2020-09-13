/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <ckakuna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 11:09:09 by ckakuna           #+#    #+#             */
/*   Updated: 2020/09/13 17:44:27 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "one.h"

int		init_global(t_global *global)
{
	if (!(global = (t_global *)malloc(sizeof(t_global))))
		return (1);
	if (!(global->argv = (t_argv *)malloc(sizeof(t_argv))))
		return (1);
}

void	philo_start(t_global *global, int index)
{
	t_philo philo;

	philo.status = 1;
	while (philo.status == 1)
	{
		philo.is_die = global->argv->die;
		pthread_mutex_lock(&global->argv->forks[index]);
		print_do();
	}
}

int		start(t_global *global)
{
	pthread_t	tid[global->argv->philo];
	int			i;

	i = 0;
	if (!(global->argv->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * (global->argv->philo + 1))))
		return (1);
	while (++i < global->argv->philo)
		if (pthread_mutex_init(&global->argv->forks[i], NULL))
			return (1);
	i = -1;
	while (++i < global->argv->philo)
		pthread_create(&tid[i], NULL, philo_start, global, i + 1);
	i = -1;
	while (++i < global->argv->philo)
		pthread_join(&tid[i], NULL);
	return (0);
}

int		main(int ac, char **av)
{
	t_global global;

	g_time = 0;
	if (ac < 5 || ac > 6)
	{
		print_error("Wrong number of arguments !\n");
		print_error("Please enter: ./philo_one [philo] [die] [eat] [sleep]\n");
		print_error("or ./philo_one [philo] [die] [eat] [sleep] [end]\n");
		return (ac);
	}
	if ((init_global(&global)) == 1)
		return (print_error("Memory allocation failed\n"));
	if (pars_argv(&global, av, ac) == 1)
		return (print_error("Invalid argument value\n"));
	if (ac == 5)
	{
		start(&global);
	}
	return (0);
}
