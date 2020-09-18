/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <ckakuna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 14:55:27 by ckakuna           #+#    #+#             */
/*   Updated: 2020/09/18 14:58:35 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../one.h"

char	*ft_strdup(const char *str)
{
	int		size;
	char	*new;

	size = ft_strlen((char *)str);
	if (!(new = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	new[size] = '\0';
	while (--size >= 0)
		new[size] = str[size];
	return (new);
}
