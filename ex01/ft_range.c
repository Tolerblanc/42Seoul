/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 20:26:27 by hyunjuki          #+#    #+#             */
/*   Updated: 2020/08/12 20:30:23 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int	*arr;
	int	i;
	int	j;

	if (min >= max)
		return ((void *)0);
	arr = (int *)malloc(sizeof(int *) * (max - min));
	i = 0;
	j = min;
	while (i < (max - min))
	{
		arr[i] = j;
		i++;
		j++;
	}
	return (arr);
}
