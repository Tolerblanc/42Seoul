/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 11:46:08 by hyunjuki          #+#    #+#             */
/*   Updated: 2020/08/03 18:40:01 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void				print_all(char arr[])
{
	int				i;

	i = 0;
	if (arr[0] == '7' && arr[1] == '8' && arr[2] == '9')
	{
		write(1, &arr[0], 1);
		write(1, &arr[1], 1);
		write(1, &arr[2], 1);
		return ;
	}
	if (arr[0] < arr[1] && arr[1] < arr[2])
	{
		while (i < 5)
		{
			write(1, &arr[i], 1);
			i++;
		}
	}
}

void				ft_print_comb(void)
{
	char			n[5];

	n[0] = '0';
	n[3] = ',';
	n[4] = ' ';
	while (n[0] <= '7')
	{
		n[1] = n[0] + 1;
		while (n[1] <= '8')
		{
			n[2] = n[1] + 1;
			while (n[2] <= '9')
			{
				print_all(n);
				n[2]++;
			}
			n[1]++;
		}
		n[0]++;
	}
}
