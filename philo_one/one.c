/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <ckakuna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 11:09:09 by ckakuna           #+#    #+#             */
/*   Updated: 2020/09/14 15:02:50 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "one.h"

int		pars_argv(char **av, int ac)
{
	if ((g_philo = (unsigned int)ft_atoi(av[1])) == 0)
		return (1);
	if ((g_die = (unsigned int)ft_atoi(av[2])) == 0)
		return (1);
	if ((g_eat = (unsigned int)ft_atoi(av[3])) == 0)
		return (1);
	if ((g_sleep = (unsigned int)ft_atoi(av[4])) == 0)
		return (1);
	if (ac == 6)
	{
		if ((g_end = (unsigned int)ft_atoi(av[5])) == 0)
			return (1);
	}
	else
		g_end = 0;
	return (0);
}

int		main(int ac, char **av)
{
	g_time = 0;
	g_index = 0;
	if (ac < 5 || ac > 6)
	{
		print_error("Wrong number of arguments !\n");
		print_error("Please enter: ./philo_one [philo] [die] [eat] [sleep]\n");
		print_error("or ./philo_one [philo] [die] [eat] [sleep] [end]\n");
		return (ac);
	}
	if (pars_argv(av, ac) == 1)
		return (print_error("Invalid argument value\n"));
	if (ac == 5)
		if (start_part_1())
			return (print_error("Invalid posix thread\n"));
//	else
//		start_part_2();
	return (0);
}
