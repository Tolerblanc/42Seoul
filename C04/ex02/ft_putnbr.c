/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 14:31:02 by hyunjuki          #+#    #+#             */
/*   Updated: 2020/08/10 14:59:55 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int			intlen(int n)
{
	int		i;

	i = 1000000000;
	while (n / i == 0)
	{
		i /= 10;
	}
	return (i);
}

void		prt_integer(int n)
{
	int		len;
	char	c;

	len = intlen(n);
	while (len != 1)
	{
		c = n / len + '0';
		write(1, &c, 1);
		n %= len;
		len /= 10;
	}
	c = n + '0';
	write(1, &c, 1);
}

void		ft_putnbr(int nb)
{
	if (nb == 0)
		write(1, "0", 1);
	else if (nb == -2147483648)
	{
		write(1, "-", 1);
		prt_integer(214748364);
		write(1, "8", 1);
	}
	else if (nb < 0)
	{
		write(1, "-", 1);
		prt_integer(nb * -1);
	}
	else
		prt_integer(nb);
}
