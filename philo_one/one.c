/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <ckakuna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 11:09:09 by ckakuna           #+#    #+#             */
/*   Updated: 2020/09/15 16:07:55 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "one.h"

int		start_threads(t_ptr *ptr)
{
	int i;
	
	i = 0;
	g_index = 0;
	while (i < ptr->times->num_philo)
	{
		if (pthread_create(&ptr->philos[i].live, NULL, thread_live, ptr))
		
		g_index++;
		i++;
	}
	
}

int		main(int ac, char **av)
{
	t_ptr	ptr;
	int		rec;

	if (ac < 5 || ac > 6)
	{
		print_error("Wrong number of arguments !\n", ac);
		print_error("Please enter: ./philo_one [philo] [die] [eat] [sleep]\n", ac);
		print_error("or ./philo_one [philo] [die] [eat] [sleep] [end]\n", ac);
		return (ac);
	}
	rec = init_ptr_param(av, &ptr, ac);
	if (rec == ERROR_VALUE)
		return (print_error("Invalid argument value\n", ERROR_VALUE));
	else if (rec == ERROR_MALLOC)
		return (print_error("Invalid allocated memory\n", ERROR_MALLOC));
	else if (rec == ERROR_MUTEX)
		return (print_error("Invalid mutex\n", ERROR_MUTEX));
	//testing_pars(&ptr);
	rec = start_threads(&ptr);
	if (rec == ERROR_THREAD)
		return (print_error("Invalid thread\n", ERROR_THREAD));
	return (0);
}
