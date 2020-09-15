/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <ckakuna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 16:46:30 by ckakuna           #+#    #+#             */
/*   Updated: 2020/09/15 17:46:39 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "one.h"

void	free_ptr(t_ptr *ptr)
{
	int i;

	i = -1;
	while (++i < ptr->times->num_ph)
		pthread_mutex_destroy(&ptr->mutex->forks[i]);
	free(ptr->philos);
	free(ptr->times);
	free(ptr->mutex->forks);
	free(ptr->mutex->die_eat);
	free(ptr->mutex);
}

int     start_threads(void)
{
	t_ptr	*ptr;
	int		i;

	ptr = get_ptr();
	i = 0;
	while (i < ptr->times->num_ph)
	{
		if (pthread_create(&ptr->philos[i].live, NULL, threads_live, &ptr->philos[i]))
			return (0);
		if (pthread_detach(ptr->philos[i].live))
			return (0);
		if (pthread_create(&ptr->philos[i].check, NULL, threads_check, &ptr->philos[i]))
			return (0);
		if (pthread_detach(ptr->philos[i].check))
			return (0);
		i++;
	}
	return (1);
}

int		print_error(char *str, int err)
{
	char *s;

	s = ft_itoa(err);
	write(STDOUT_FILENO, RED"Error: "RESET, ft_strlen(RED"Error: "RESET));
	write(STDOUT_FILENO, YELLOW, ft_strlen(YELLOW));
	write(STDOUT_FILENO, "Code: ", ft_strlen("Code: "));
	write(STDOUT_FILENO, s, ft_strlen(s));
	write(STDOUT_FILENO, " ", 1);
	write(STDOUT_FILENO, str, ft_strlen(str));
	write(STDOUT_FILENO, RESET, ft_strlen(RESET));
	free(s);
	return (err);
}

int		check_alive(t_ptr *ptr)
{
	while (1)
	{
		if (!ptr->alive)
			return (1);
		if (!ptr->num_philo)
			break ;
		usleep(200);
	}
	return (0);
}

int		main(int ac, char **av)
{
	t_ptr *ptr;

	if (ac < 5 || ac > 6)
		return (print_error("Wrong number of arguments !\n", ac));
	if (!(ptr = init_param(av)))
		return (print_error("Invalid argument value !\n", ERROR_VALUE));
	if (!start_threads())
		return (print_error("Invalid thread\n", ERROR_THREAD));
	if (check_alive(ptr))
		return (0);
	free_ptr(ptr);
	write(STDOUT_FILENO, RED, ft_strlen(RED));
	write(STDOUT_FILENO, "They all have eaten enough\n", ft_strlen("They all have eaten enough\n"));
	write(STDOUT_FILENO, RESET, ft_strlen(RESET));
	return (1);
}
