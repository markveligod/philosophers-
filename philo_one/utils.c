/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <ckakuna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 11:11:43 by ckakuna           #+#    #+#             */
/*   Updated: 2020/09/15 11:56:43 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "one.h"

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (i);
	while (str[i])
		i++;
	return (i);
}

int		ft_atoi(char *str)
{
	int			i;
	int			sing;
	long int	res;

	i = 0;
	sing = 1;
	res = 0;
	if (!str)
		return (0);
	while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
		i++;
	if (str[i] == '-' || str[i] == '+')
		sing = ((str[i++] == '-') ? -1 : 1);
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (res * sing);
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

int		check_size(int n)
{
	int		count;
	long	res;

	res = n;
	count = 1;
	if (res < 0)
	{
		count++;
		res *= (-1);
	}
	while (res >= 10)
	{
		count++;
		res /= 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*array;
	long	res;
	int		i;

	i = 0;
	if (!(array = (char*)malloc(sizeof(char) * check_size(n) + 1)))
		return (NULL);
	if (n < 0)
		array[0] = '-';
	res = n;
	if (res < 0)
		res *= (-1);
	array[check_size(n) - i++] = '\0';
	while (res >= 10)
	{
		array[check_size(n) - i++] = (res % 10) + '0';
		res /= 10;
	}
	array[check_size(n) - i++] = (res % 10) + '0';
	return (array);
}
