/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <ckakuna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 11:11:46 by ckakuna           #+#    #+#             */
/*   Updated: 2020/09/13 12:48:06 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "one.h"

int		pars_argv(t_global *global, char **av, int ac)
{
	if ((global->argv->philo = (unsigned int)ft_atoi(av[1])) == 0)
		return (1);
	if ((global->argv->die = (unsigned int)ft_atoi(av[2])) == 0)
		return (1);
	if ((global->argv->eat = (unsigned int)ft_atoi(av[3])) == 0)
		return (1);
	if ((global->argv->sleep = (unsigned int)ft_atoi(av[4])) == 0)
		return (1);
	if (ac == 6)
	{
		if ((global->argv->end = (unsigned int)ft_atoi(av[5])) == 0)
			return (1);
	}
	else
		global->argv->end = 0;
	return (0);
}