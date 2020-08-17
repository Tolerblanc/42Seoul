/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 19:49:09 by hyunjuki          #+#    #+#             */
/*   Updated: 2020/08/17 18:07:33 by hyunjuki         ###   ########.fr       */
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
	return (-1);
}

int		basify(char *str, char *base, int size)
{
	int	i;
	int	dec;
	int	len_str;
	int	temp;

	i = 0;
	dec = 0;
	len_str = 0;
	while (chk_base(str[i], base, size) >= 0 && str[i] != '\0')
	{
		i++;
		len_str++;
	}
	i = 0;
	temp = len_str;
	while (i < temp)
	{
		dec += ft_power(size, len_str - 1) * chk_base(str[i], base, size);
		i++;
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
	if (chk_base(*str, base, size))
		return (sign * basify(str, base, size));
	return (0);
}
