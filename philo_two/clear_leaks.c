/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_leaks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <ckakuna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 17:28:02 by ckakuna           #+#    #+#             */
/*   Updated: 2020/09/19 12:13:31 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "two.h"

/*
**============================================================================
** Функция для очистки замолоченных структур и созданных мьютексов.
**============================================================================
*/

void	clear_leaks(t_argv *argv)
{
	int i;

	i = 0;
	sem_unlink(SEMA_FORK);
	sem_unlink(SEMA_WRITE);
	sem_unlink(SEMA_DEAD);
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
