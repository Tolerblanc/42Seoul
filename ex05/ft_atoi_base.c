/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 19:49:09 by hyunjuki          #+#    #+#             */
/*   Updated: 2020/08/12 16:00:09 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		get_integer(char *str)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (*(str + i) >= '0' && *(str + i) <= '9')
	{
		res = res * 10 + (*(str + i) - '0');
		i++;
	}
	return (res);
}

int		ft_strlen(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (*(str + i) != '\0')
	{
		i++;
		if (*(str + i) == '+' || *(str + i) == '-')
			return (-1);
		j = 0;
		while (*(str + j) != '\0')
		{
			if (*(str + i) == *(str + j) && i != j)
				return (-1);
			j++;
		}
	}
	return (i);
}

int		basify(char *str, char *base, int size)
{
	int	dec;
	int res;
	int	i;

	i = 1;
	dec = 0;
	res = 0;
	while (!(*str >= '0' && *str <= '9'))
	{
		dec = dec * 10 + (*str - '0');
		str++;
	}
	while (dec != 0)
	{
		if (dec % size == 0)
			i *= 10;
		else
			res = res + i * (base[dec % size] - '0');
		dec /= i;
		i *= 10;
	}
	return (res);
}

int		ft_atoi_base(char *str, char *base)
{
	int	sign;
	int	size;

	size = ft_strlen(base);
	if (size < 2)
		return (0);
	sign = 1;
	while (*str != '\0')
	{
		if ((*str == '\t' || *str == '\n' || *str == '\v' ||
			*str == '\f' || *str == '\r' || *str == ' ') ||
			(*str == '+' || *str == '-'))
			sign = *str == '-' ? sign * -1 : sign;
		else if (*str >= '0' && *str <= '9')
			return (sign * basify(str, base, size));
		str++;
	}
	return (0);
}
