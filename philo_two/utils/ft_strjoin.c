/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <ckakuna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 09:56:22 by ckakuna           #+#    #+#             */
/*   Updated: 2020/09/19 09:57:02 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../two.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*array;

	if (s1 && s2)
	{
		if (!(array = (char *)malloc(sizeof(char) * (ft_strlen(s1)
		+ ft_strlen(s2) + 1))))
			return (NULL);
		i = 0;
		j = -1;
		while (s1[++j])
			array[i++] = s1[j];
		j = -1;
		while (s2[++j])
			array[i++] = s2[j];
		array[i] = '\0';
		return (array);
	}
	return (NULL);
}
