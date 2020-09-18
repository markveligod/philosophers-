/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <ckakuna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 16:46:30 by ckakuna           #+#    #+#             */
/*   Updated: 2020/09/18 20:31:06 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "one.h"

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
	t_argv	argv;
	int		status;

	status = 0;
	g_dead = 0;
	if (ac < 5 || ac > 6)
		return (print_error("Wrong number of arguments !\n", ac));
	if ((status = init_param(&argv, ac, av)) != 0)
		return (print_error("Invalid init param\n", status));
	if ((status = start_threads(&argv)) != 0)
		return (print_error("Invalid start threads\n", status));
	pthread_mutex_lock(&argv.who_dead);
	pthread_mutex_unlock(&argv.who_dead);
	clear_leaks(&argv);
	return (status);
}
