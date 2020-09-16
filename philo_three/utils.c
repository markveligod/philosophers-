/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <ckakuna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 17:02:18 by ckakuna           #+#    #+#             */
/*   Updated: 2020/09/16 14:10:45 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "three.h"

unsigned long		get_time_is(void)
{
	struct timeval tv;

	if (gettimeofday(&tv, NULL))
		return (0);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

char				*ft_itoa(unsigned long n)
{
	unsigned int	size;
	unsigned int	i;
	char			*tab;

	size = ft_len(n);
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

char		*ft_strjoin(char const *s1, char const *s2)
{
	size_t		i;
	size_t		j;
	char		*str;

	if (s1 == NULL)
		return (ft_strdup(s2));
	else if (s2 == NULL)
		return (ft_strdup(s1));
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	j = 0;
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	if (*s1)
		free((void *)s1);
	return (str);
}

size_t		ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int			ft_atoi(const char *str)
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
