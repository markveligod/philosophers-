/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <ckakuna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 14:56:09 by ckakuna           #+#    #+#             */
/*   Updated: 2020/09/18 14:56:22 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../one.h"

int					ft_atoi(const char *str)
{
	int		i;
	int		sing;
	long	res;

	i = 0;
	res = 0;
	sing = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;
	if (str[i] == '-' || str[i] == '+')
		sing = ((str[i++] == '-') ? -1 : 1);
	while ((str[i] >= '0' && str[i] <= '9') && str[i] != '\0')
		res = (res * 10) + (str[i++] - '0');
	return (res * sing);
}
