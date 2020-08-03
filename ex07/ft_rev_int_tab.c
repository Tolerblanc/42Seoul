/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 21:21:42 by hyunjuki          #+#    #+#             */
/*   Updated: 2020/08/03 21:42:05 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	arr[size];
	int	i;

	i = 0;
	while (i < size)
	{
		arr[i] = *(tab + i);
		i++;
	}
	i = 0;
	while (i < size)
	{
		*(tab + i) = arr[size - i - 1];
		i++;
	}
}
