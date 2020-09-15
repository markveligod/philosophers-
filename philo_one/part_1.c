/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <ckakuna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 11:11:46 by ckakuna           #+#    #+#             */
/*   Updated: 2020/09/14 17:50:34 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "one.h"

void	print_do(char *str, int index)
{
	char *is_time;
	char *name;
	struct timeval tv;

	//is_time = ft_itoa((g_last_time.tv_sec - g_start_time.tv_sec) * 1000 +
	//		(g_last_time.tv_usec - g_start_time.tv_usec) / 1000);
	gettimeofday(&tv, NULL);
	is_time = ft_itoa(tv.tv_usec / 1000 + tv.tv_sec * 1000);
	name = ft_itoa(index);
	write(STDOUT_FILENO, is_time, ft_strlen(is_time));
	write(STDOUT_FILENO, " ", 1);
	write(STDOUT_FILENO, name, ft_strlen(name));
	write(STDOUT_FILENO, " ", 1);
	write(STDOUT_FILENO, str, ft_strlen(str));
	write(STDOUT_FILENO, "\n", 1);
}

int		check_forks(int index)
{
	int i;

	pthread_mutex_lock(&g_waits);
	i = 1;
	while (i <= g_philo)
	{
		if (g_forks[i] == 0)
			if (i + 1 <= g_philo && g_forks[i + 1] == 0)
			{
				g_forks[i] = index;
				g_forks[i + 1] = index;
				pthread_mutex_unlock(&g_waits);
				return (1);
			}
		i++;
	}
	pthread_mutex_unlock(&g_waits);
	return (0);
}

void	reset_forks(int index)
{
	int i;

	pthread_mutex_lock(&g_waits);
	i = 1;
	while (g_forks[i] && g_forks[i] != index)
		i++;
	g_forks[i] = 0;
	g_forks[i + 1] = 0;
	pthread_mutex_unlock(&g_waits);
	return ;
}

void	*philo_start(void *param)
{
	int is_die;
	int index;

	g_status = 1;
	index = ++g_index;
	is_die = g_die;
	while (g_status == 1)
	{
		if (check_forks(index))
		{
			pthread_mutex_lock(&g_waits);
			gettimeofday(&g_last_time, NULL);
			if (is_die < 10 || g_status == 0)
				break ;
			print_do("has taken a fork", index);
			print_do("has taken a fork", index);
			print_do("is eating", index);
			pthread_mutex_unlock(&g_waits);
			usleep(g_eat);
			reset_forks(index);
			pthread_mutex_lock(&g_waits);
			is_die = g_die;
			gettimeofday(&g_last_time, NULL);
			if (is_die < 10 || g_status == 0)
				break ;
			print_do("is sleeping", index);
			pthread_mutex_unlock(&g_waits);
			usleep(g_sleep);
			pthread_mutex_lock(&g_waits);
			is_die -= g_sleep;
			gettimeofday(&g_last_time, NULL);
			if (is_die < 10 || g_status == 0)
				break ;
			print_do("is thinking", index);
			pthread_mutex_unlock(&g_waits);
		}
		else
		{
			
		}
	}
	if (g_status == 1)
	{
		print_do("died", index);
		g_status = 0;
	}
	pthread_mutex_unlock(&g_waits);
	return (NULL);
}

int		start_part_1(void)
{
	pthread_t		tid[g_philo];
	long long int	i;

	gettimeofday(&g_start_time, NULL);
	if (!(g_forks = (int *)malloc(sizeof(int) * (g_philo + 1))))
		return (1);
	i = 0;
	while (++i <= g_philo)
		g_forks[i] = 0;
	if (pthread_mutex_init(&g_waits, NULL))
		return (1);
	i = -1;
	while (++i < g_philo)
		if (pthread_create(&(tid[i]), NULL, philo_start, NULL))
			return (1);
	i = -1;
	while (++i < g_philo)
		pthread_join(tid[i], NULL);
	return (0);
}
