/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_mess.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <ckakuna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 15:41:50 by ckakuna           #+#    #+#             */
/*   Updated: 2020/09/19 16:21:08 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../three.h"

char	*get_status(t_state status)
{
	if (status == TAKE_FORK)
		return ("has taken a fork]\n");
	else if (status == THINKING)
		return ("is thinking]\n");
	else if (status == EATING)
		return ("is eating]\n");
	else if (status == SLEEPING)
		return ("is sleeping]\n");
	else if (status == DIED)
		return ("died]\n");
	else if (status == END)
		return ("Stop eating spaghetti !!!]\n");
	return (NULL);
}

void	print_time(unsigned long start_time)
{
	char *curr_time;

	curr_time = ft_itoa(ft_time_is() - start_time);
	write(STDOUT_FILENO, YELLOW, ft_strlen(YELLOW));
	write(STDOUT_FILENO, "[", 1);
	write(STDOUT_FILENO, curr_time, ft_strlen(curr_time));
	write(STDOUT_FILENO, "ms] ", 4);
	write(STDOUT_FILENO, RESET, ft_strlen(RESET));
	free(curr_time);
}

void	print_status(t_state status)
{
	char *stats;

	if (status != DIED && status != END)
		write(STDOUT_FILENO, GREEN, ft_strlen(GREEN));
	else
		write(STDOUT_FILENO, RED, ft_strlen(RED));
	write(STDOUT_FILENO, " [", 2);
	stats = get_status(status);
	write(STDOUT_FILENO, stats, ft_strlen(stats));
	write(STDOUT_FILENO, RESET, ft_strlen(RESET));
}

void	ft_print_mess(t_philo *philo, t_state status)
{
	char		*index;

	sem_wait(philo->argv->who_write);
	sem_wait(philo->argv->omg_he_dead);
	print_time(philo->argv->start_time);
	index = ft_itoa(philo->index + 1);
	if (status != END)
		write(STDOUT_FILENO, index, ft_strlen(index));
	else
		write(STDOUT_FILENO, " ", 1);
	free(index);
	print_status(status);
	if (status != DIED && status != END)
		sem_post(philo->argv->omg_he_dead);
	sem_post(philo->argv->who_write);
}
