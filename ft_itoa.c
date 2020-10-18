/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 11:46:13 by hyunjuki          #+#    #+#             */
/*   Updated: 2020/10/18 12:28:26 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	intlen(int n)
{
	int		len;

	len = n < 0 ? 2 : 1;
	while (n / 10)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static int	abs_power(int n, int p)
{
	int ret;

	if (p == 0)
		return (1);
	p = p < 0 ? -p : p;
	ret = 1;
	while (p)
	{
		ret *= n;
		p--;
	}
	return (ret);
}

char		*ft_itoa(int n)
{
	int		size;
	int		temp;
	int		i;
	char	*s;

	size = intlen(n);
	if ((s = (char *)malloc(size + 1)) == NULL)
		return (NULL);
	temp = n < 0 ? abs_power(10, size - 2) : abs_power(10, size - 1);
	i = 0;
	if (n < 0)
	{
		s[i++] = '-';
		n *= -1;
	}
	s[size] = '\0';
	while (temp)
	{
		s[i] = n / temp + '0';
		n %= temp;
		temp /= 10;
		i++;
	}
	return (s);
}
