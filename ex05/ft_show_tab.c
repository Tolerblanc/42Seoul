/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 15:46:09 by hyunjuki          #+#    #+#             */
/*   Updated: 2020/08/17 15:51:41 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

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

void        ft_prtstr(char *str)
{
    while (*str)
    {
        write(1, str, 1);
        str++;
    }
    write(1, "\n", 1);
}

void        ft_show_tab(struct s_stock_str *par)
{
    int     i;

    i = 0;
    while (par[i].str)
    {
        ft_prtstr(par[i].str);
        ft_putnbr(par[i].size);
        ft_prtstr(par[i].copy);
        i++;
    }
}