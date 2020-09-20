/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 17:56:23 by hyunjuki          #+#    #+#             */
/*   Updated: 2020/08/03 18:44:37 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void		print(int n, int arr[])
{
	char	c;
	int		i;

	i = 0;
	while (i < n)
	{
		c = arr[i] + '0';
		write(1, &c, 1);
		i++;
	}
	if (arr[0] != (10 - n) || arr[n - 1] != 9)
	{
		c = ',';
		write(1, &c, 1);
		c = ' ';
		write(1, &c, 1);
	}
}

void		pick(int n, int m, int arr[])
{
	int		i;

	if (n == m)
		print(n, arr);
	else
	{
		if (m == 0)
			i = 0;
		else
			i = arr[m - 1] + 1;
		while (i <= 9)
		{
			arr[m] = i;
			pick(n, m + 1, arr);
			i++;
		}
	}
}

void		ft_print_combn(int n)
{
	int		num[10];

	pick(n, 0, num);
}
