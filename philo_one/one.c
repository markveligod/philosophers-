/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <ckakuna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 11:09:09 by ckakuna           #+#    #+#             */
/*   Updated: 2020/09/15 12:07:35 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "one.h"

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
		return (print_error("Invalid argument value\n", ERROR_MALLOC));
	return (0);
}
