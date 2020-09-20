/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 01:35:03 by hyunjuki          #+#    #+#             */
/*   Updated: 2020/08/21 02:32:15 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int		i;
	int		sorted;
	int		sorted_rev;

	i = 0;
	sorted = 0;
	sorted_rev = 0;
	if (length < 2)
		return (1);
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) <= 0)
			sorted++;
		if (f(tab[i], tab[i + 1]) >= 0)
			sorted_rev++;
		i++;
	}
	return ((sorted == length - 1 || sorted_rev == length - 1) ? 1 : 0);
}
