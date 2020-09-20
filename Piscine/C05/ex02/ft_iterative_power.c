/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 16:21:52 by hyunjuki          #+#    #+#             */
/*   Updated: 2020/08/12 16:22:44 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_power(int nb, int power)
{
	int	n;
	int	i;

	if (power < 0)
		return (0);
	n = 1;
	i = 0;
	while (i < power)
	{
		n *= nb;
		i++;
	}
	return (n);
}
