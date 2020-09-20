/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 02:01:05 by hyunjuki          #+#    #+#             */
/*   Updated: 2020/08/21 01:20:05 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "func.h"

int				chk_op(char *str)
{
	if (!*(str + 1))
	{
		if (*str == '+')
			return (1);
		if (*str == '-')
			return (2);
		if (*str == '*')
			return (3);
		if (*str == '/')
			return (4);
		if (*str == '%')
			return (5);
	}
	write(1, "0", 1);
	return (0);
}

void			prt_result(int a, int b, int op, int (*f)(int, int))
{
	int			res;

	if (op == 3 && b == 0)
	{
		write(1, "Stop : division by zero\n", 24);
		return ;
	}
	if (op == 4 && b == 0)
	{
		write(1, "Stop : modulo by zero\n", 22);
		return ;
	}
	res = f(a, b);
	ft_putnbr(res);
	write(1, "\n", 1);
}

int				main(int argc, char **argv)
{
	int			(*f[5])(int, int);
	int			x;
	int			y;
	int			op;

	if (argc != 4)
		return (1);
	op = chk_op(argv[2]);
	if (!op)
		return (1);
	f[0] = add;
	f[1] = sub;
	f[2] = mul;
	f[3] = div;
	f[4] = mod;
	x = ft_atoi(argv[1]);
	y = ft_atoi(argv[3]);
	prt_result(x, y, op - 1, f[op - 1]);
}
