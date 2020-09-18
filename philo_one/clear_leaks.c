/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_leaks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <ckakuna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 17:28:02 by ckakuna           #+#    #+#             */
/*   Updated: 2020/09/18 17:39:15 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "one.h"

void	clear_leaks(t_argv *argv)
{
	int i;

	i = 0;
	while (i < argv->num_philo)
	{
		pthread_mutex_destroy(&argv->forks[i]);
		pthread_mutex_destroy(&argv->philos[i].mutex);
		pthread_mutex_destroy(&argv->philos[i].eat_m);
		i++;
	}
	free(argv->forks);
	free(argv->philos);
	pthread_mutex_destroy(&argv->who_write);
	pthread_mutex_destroy(&argv->who_dead);
}
