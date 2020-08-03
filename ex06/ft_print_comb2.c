/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 12:02:03 by hyunjuki          #+#    #+#             */
/*   Updated: 2020/08/03 14:16:54 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void		print_arr(char arr[], int idx)
{
	int		i;

	i = 0;
	while (i < idx)
	{
		write(1, &arr[i], 1);
		i++;
	}
}

void		init(char arr[])
{
	int		i;

	i = 0;
	while (i < 7)
	{
		arr[i] = '0';
		i++;
	}
	arr[2] = ' ';
	arr[5] = ',';
	arr[6] = ' ';
}

void		set_num(char arr[], int num1, int num2)
{
	arr[0] = (num1 / 10) + '0';
	arr[1] = (num1 % 10) + '0';
	arr[3] = (num2 / 10) + '0';
	arr[4] = (num2 % 10) + '0';
}

void		ft_print_comb2(void)
{
	char	arr[7];
	int		i;
	int		j;

	init(arr);
	i = 0;
	while (i < 99)
	{
		j = i + 1;
		while (j <= 99)
		{
			set_num(arr, i, j);
			if (i == 98 && j == 99)
			{
				print_arr(arr, 5);
			}
			else
				print_arr(arr, 7);
			j++;
		}
		i++;
	}
}
