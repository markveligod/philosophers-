/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <ckakuna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 16:46:30 by ckakuna           #+#    #+#             */
/*   Updated: 2020/09/16 15:14:27 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "three.h"

int		check_waitpid(void)
{
	int		status;
	t_ptr	*ptr;

	status = 0;
	ptr = get_ptr();
	waitpid(ptr->pid, &status, 0);
	if (status == 256)
		return (0);
	return (1);
}

int     start_threads(void)
{
	t_ptr	*ptr;
	int		i;

	ptr = get_ptr();
	i = 0;
	ptr->pid = fork();
	if (ptr->pid == 0)
	{
		while (i < ptr->times->num_ph)
		{
			pthread_create(&ptr->philos[i].live, NULL, threads_live, &ptr->philos[i]);
			pthread_detach(ptr->philos[i].live);
			pthread_create(&ptr->philos[i].check, NULL, threads_check, &ptr->philos[i]);
			pthread_detach(ptr->philos[i].check);
			i++;
		}
		while (1)
		{
			if (!ptr->alive)
				exit(EXIT_FAILURE);
			if (!ptr->num_philo)
				break ;
			usleep(200);
		}
		exit(EXIT_SUCCESS);
	}
	return (check_waitpid());
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

int		main(int ac, char **av)
{
	t_ptr	*ptr;
	int		rec;

	if (ac < 5 || ac > 6)
		return (print_error("Wrong number of arguments !\n", ac));
	if (!(ptr = init_param(av)))
		return (print_error("Invalid argument value !\n", ERROR_VALUE));
	rec = start_threads();
	free_ptr(ptr);
	if (rec == 0)
		return (0);
	write(STDOUT_FILENO, RED, ft_strlen(RED));
	write(STDOUT_FILENO, "They all have eaten enough\n", ft_strlen("They all have eaten enough\n"));
	write(STDOUT_FILENO, RESET, ft_strlen(RESET));
	return (1);
}
