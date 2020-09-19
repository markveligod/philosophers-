/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <ckakuna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 14:56:40 by ckakuna           #+#    #+#             */
/*   Updated: 2020/09/19 10:54:09 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../two.h"

int					ft_check_size(unsigned long nb)
{
	unsigned long count;

	count = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb = nb / 10;
		count++;
	}
	return (count);
}

char				*ft_itoa(unsigned long n)
{
	unsigned int	size;
	unsigned int	i;
	char			*tab;

	size = ft_check_size(n);
	i = 0;
	if (n == 0)
		return (ft_strdup("0"));
	if (!(tab = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (++i <= size)
	{
		tab[size - i] = (n % 10) + '0';
		n = n / 10;
	}
	tab[size] = '\0';
	return ((char *)tab);
}
