/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <ckakuna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 11:09:09 by ckakuna           #+#    #+#             */
/*   Updated: 2020/09/13 13:26:29 by ckakuna          ###   ########.fr       */
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

int		main(int ac, char **av)
{
	t_global global;

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
	/*test parsing
	printf("Philo: %d\nDie: %d\nEat: %d\nSleep: %d\nEnd: %d\n", global.argv->philo, global.argv->die, global.argv->eat, global.argv->sleep, global.argv->end);
	*/
	
	return (0);
}
