/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time_is.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <ckakuna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 15:30:13 by ckakuna           #+#    #+#             */
/*   Updated: 2020/09/19 14:56:55 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../three.h"

unsigned long	ft_time_is(void)
{
	static struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * (unsigned long)1000) + (tv.tv_usec / 1000));
}
