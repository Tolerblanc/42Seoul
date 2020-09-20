/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 14:37:31 by hyunjuki          #+#    #+#             */
/*   Updated: 2020/08/03 18:41:13 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int			chk_size(int n)
{
	int		i;

	i = 1000000000;
	while (n / i == 0)
	{
		i /= 10;
	}
	return (i);
}

void		print_integer(int n)
{
	int		size;
	int		target;
	char	num;

	target = n;
	size = chk_size(n);
	while (size != 1)
	{
		num = target / size + '0';
		write(1, &num, 1);
		target = target - (target / size) * size;
		size /= 10;
	}
	num = target + '0';
	write(1, &num, 1);
}

void		ft_putnbr(int nb)
{
	char	zero;
	char	minus;

	minus = '-';
	zero = '0';
	if (nb == 0)
	{
		write(1, &zero, 1);
	}
	else if (nb > 0)
	{
		print_integer(nb);
	}
	else
	{
		write(1, &minus, 1);
		nb *= -1;
		print_integer(nb);
	}
}
