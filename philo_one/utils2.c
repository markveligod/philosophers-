/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <ckakuna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 17:02:30 by ckakuna           #+#    #+#             */
/*   Updated: 2020/09/15 17:37:11 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "one.h"

char	*ft_strdup(const char *s1)
{
	unsigned int i;
	unsigned int j;
	char *str;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
		i++;
	str = (char *)malloc((1 + i) * sizeof(char));
	if (str == NULL)
		return (NULL);
	while (j < i)
	{
		str[j] = s1[j];
		j++;
	}
	str[j] = '\0';
	return (str);
}

int		ft_len(unsigned long nb)
{
	unsigned long len;

	len = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

char	*get_status(t_state status)
{
	if (status == TAKE_FORK)
		return (ft_strdup(" has taken a fork\n"));
	else if (status == THINKING)
		return (ft_strdup(" is thinking\n"));
	else if (status == EATING)
		return (ft_strdup(" is eating\n"));
	//else if (status == TAKE_FORK)
	//    return (" has taken a fork");
	else if (status == SLEEPING)
		return (ft_strdup(" is sleeping\n"));
	else if (status == DIED)
		return (ft_strdup(" died\n"));
	return (NULL);
}

void	print_do(t_philo *philo, t_state status)
{
	char *stats;
	char *temp;
	char *time;
	char *index;

	time = ft_itoa(get_time_is() - philo->start);
	index = ft_itoa(philo->index + 1);
	stats = get_status(status);
	temp = ft_strdup("");
	temp = ft_strjoin(temp, YELLOW);
	temp = ft_strjoin(temp, "[");
	temp = ft_strjoin(temp, time);
	temp = ft_strjoin(temp, "ms] ");
	temp = ft_strjoin(temp, RESET);
	temp = ft_strjoin(temp, index);
	temp = ft_strjoin(temp, " ");
	temp = (status == DIED) ? ft_strjoin(temp, RED) : ft_strjoin(temp, GREEN);
	temp = ft_strjoin(temp, stats);
	temp = ft_strjoin(temp, RESET);
	write(STDOUT_FILENO, temp, ft_strlen(temp));
	free(time);
	free(index);
	free(temp);
	free(stats);
}
