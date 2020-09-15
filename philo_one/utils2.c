/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <ckakuna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 13:05:04 by ckakuna           #+#    #+#             */
/*   Updated: 2020/09/15 16:07:22 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "one.h"

unsigned long		get_time(void)
{
	struct timeval tv;

	if (gettimeofday(&tv, NULL))
		return (0);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

char				*check_state(t_state status)
{
	if (status == TAKE_FORK)
		return (" has taken a fork\n");
	else if (status == THINKING)
		return (" is thinking\n");
	else if (status == EATING)
		return (" is eating\n");
	else if (status == TAKE_FORK)
		return (" has taken a fork\n");
	else if (status == SLEEPING)
		return (" is sleeping\n");
	else if (status == DIED)
		return (" died\n");
	return (NULL);
}

void				print_do(t_philo *philo, t_state status)
{
	char *stat;
	char *time;
	char *index;
	
	stat = check_state(status);
	time = ft_itoa(get_time() - philo->start);
	index = ft_itoa(philo->index);
	write(STDOUT_FILENO, YELLOW, ft_strlen(YELLOW));
	write(STDOUT_FILENO, time, ft_strlen(time));
	write(STDOUT_FILENO, "ms ", 3);
	write(STDOUT_FILENO, RESET, ft_strlen(RESET));
	write(STDOUT_FILENO, index, ft_strlen(index));
	write(STDOUT_FILENO, " ", 1);
	write(STDOUT_FILENO, GREEN, ft_strlen(GREEN));
	write(STDOUT_FILENO, stat, ft_strlen(stat));
	write(STDOUT_FILENO, RESET, ft_strlen(RESET));
	free(time);
	free(index);
}
