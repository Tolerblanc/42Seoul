/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 20:33:14 by hyunjuki          #+#    #+#             */
/*   Updated: 2020/08/12 20:43:18 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_ultimate_range(int **range, int min, int max)
{
	int	i;

	if (min >= max)
	{
		range = 0;
		return (0);
	}
	*range = (int *)malloc(sizeof(int) * (max - min));
	if (*range == (void *)0)
		return (-1);
	i = 0;
	while (i < (max - min))
	{
		(*range)[i] = min + i;
		i++;
	}
	return (max - min);
}
