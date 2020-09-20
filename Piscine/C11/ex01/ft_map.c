/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 22:45:42 by hyunjuki          #+#    #+#             */
/*   Updated: 2020/08/20 16:22:57 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_map(int *tab, int length, int (*f)(int))
{
	int		*res;
	int		i;

	res = (int *)malloc(sizeof(int) * length);
	i = -1;
	while (i++ < length)
		res[i] = f(tab[i]);
	return (res);
}
