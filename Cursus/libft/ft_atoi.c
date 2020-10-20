/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 13:03:30 by hyunjuki          #+#    #+#             */
/*   Updated: 2020/10/18 16:16:47 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	isspace(const char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\r'
	|| c == '\v' || c == '\f');
}

int			ft_atoi(const char *str)
{
	int ret;
	int sign;

	ret = 0;
	while (*str && isspace(*str))
		str++;
	if (*str == '-')
		sign = -1;
	else if (*str == '+')
		sign = 1;
	else if (ft_isdigit(*str))
	{
		ret = *str - '0';
		sign = 1;
	}
	else
		return (0);
	str++;
	while (*str && ft_isdigit(*str))
		ret = ret * 10 + (*str++ - '0');
	return (ret * sign);
}
