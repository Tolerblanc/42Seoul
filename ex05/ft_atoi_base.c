/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 19:49:09 by hyunjuki          #+#    #+#             */
/*   Updated: 2020/08/10 19:49:09 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned int		ft_strlen(char *str)
{
	unsigned int	i;
	unsigned int	j;

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

int		is_space(char str)
{
	if (str == '\t' || str == '\n' || str == '\v' ||
			str == '\f' || str == '\r' || str == ' ')
		return (1);
	return (0);
}

int		is_sign(char str)
{
	if (str == '+')
		return (1);
	if (str == '-')
		return (2);
	return (0);
}

int		is_num(char str)
{
	if (str >= '0' && str <= '9')
		return (1);
	return (0);
}

int		get_integer(char *str)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (is_num(*(str + i)))
	{
		res = res * 10 + (*(str + i) - '0');
		i++;
	}
	return (res);
}

int		ft_atoi(char *str)
{
	int	sign;

	sign = 1;
	while (*str != '\0')
	{
		if (is_space(*str) || is_sign(*str))
			sign = is_sign(*str) == 2 ? sign * -1 : sign;
		else if (is_num(*str))
		{
			return (sign * get_integer(str));
		}
		str++;
	}
	return (0);
}
