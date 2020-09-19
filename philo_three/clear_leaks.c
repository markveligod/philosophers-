/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_leaks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <ckakuna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 17:28:02 by ckakuna           #+#    #+#             */
/*   Updated: 2020/09/19 15:10:45 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "three.h"

/*
**============================================================================
** Функция для очистки замолоченных структур и созданных семов.
**============================================================================
*/

void	clear_leaks(t_argv *argv)
{
	int i;

	i = 0;
	while (i < argv->num_philo)
		kill(argv->philos[i++].pid, SIGKILL);
	sem_unlink(SEMA_FORK);
	sem_unlink(SEMA_WRITE);
	sem_unlink(SEMA_DEAD);
	sem_unlink(SEMA_HEDEAD);
	i = 0;
	while (i < argv->num_philo)
	{
		sem_unlink(argv->philos[i].sema_name);
		sem_unlink(argv->philos[i].sema_eat);
		free(argv->philos[i].sema_name);
		free(argv->philos[i].sema_eat);
		i++;
	}
	free(argv->philos);
}
