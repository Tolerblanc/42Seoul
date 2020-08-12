/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 19:49:09 by hyunjuki          #+#    #+#             */
/*   Updated: 2020/08/13 05:32:03 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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

int		ft_power(int nb, int power)
{
	int	n;
	int	i;

	if (power < 0)
		return (0);
	n = 1;
	i = 0;
	while (i < power)
	{
		n *= nb;
		i++;
	}
	return (n);
}

int		chk_base(char c, char *base, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (0);
}

int		basify(char *str, char *base, int size)
{
	int	dec;
	int	len_str;

	dec = 0;
	len_str = ft_strlen(str);
	while (*str != '\0')
	{
		dec += ft_power(size, len_str - 1) * chk_base(*str, base, size);
		str++;
		len_str--;
	}
	return (dec);
}

int		ft_atoi_base(char *str, char *base)
{
	int	sign;
	int	size;

	size = ft_strlen(base);
	if (size < 2)
		return (0);
	sign = 1;
	while ((*str == '\t' || *str == '\n' || *str == '\v' ||
			*str == '\f' || *str == '\r' || *str == ' '))
		str++;
	while ((*str == '+' || *str == '-'))
	{
		sign = *str == '-' ? sign * -1 : sign;
		str++;
	}
	while (*str != '\0')
	{
		if (chk_base(*str, base, size))
			return (sign * basify(str, base, size));
		str++;
	}
	return (0);
}
