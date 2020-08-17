/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 15:29:39 by hyunjuki          #+#    #+#             */
/*   Updated: 2020/08/17 17:29:42 by hyunjuki         ###   ########.fr       */
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
		if (*(str + i) == '+' || *(str + i) == '-' || *(str + i) == ' ')
			return (0);
		j = 0;
		while (*(str + j) != '\0')
		{
			if (*(str + i) == *(str + j) && i != j)
				return (0);
			j++;
		}
	}
	return (i);
}

unsigned int		intlen(unsigned int n, unsigned int base)
{
	unsigned int	div;
	unsigned int	i;

	i = 0;
	div = n / base;
	while (div != 0)
	{
		div /= base;
		i++;
	}
	return (i);
}

unsigned int		power(unsigned int base, unsigned int pow)
{
	unsigned int	i;
	unsigned int	p;

	if (pow == 0)
		return (1);
	i = 0;
	p = base;
	while (i < pow - 1)
	{
		base *= p;
		i++;
	}
	return (base);
}

void				prt_base(unsigned int n, char *base, unsigned int b_size)
{
	unsigned int	n_size;
	char			c;
	unsigned int	i;

	n_size = intlen(n, b_size);
	while (n_size != 0)
	{
		i = power(b_size, n_size);
		c = base[n / i];
		write(1, &c, 1);
		n %= i;
		n_size--;
	}
	i = power(b_size, n_size);
	c = base[n / i];
	write(1, &c, 1);
}

void				ft_putnbr_base(int nbr, char *base)
{
	unsigned int	size;

	size = ft_strlen(base);
	if (size <= 1)
		return ;
	if (nbr == -2147483648)
	{
		write(1, "-", 1);
		prt_base(2147483648, base, size);
	}
	else if (nbr < 0)
	{
		nbr *= -1;
		write(1, "-", 1);
		prt_base(nbr, base, size);
	}
	else
		prt_base(nbr, base, size);
}
