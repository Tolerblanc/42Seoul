/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 16:15:57 by hyunjuki          #+#    #+#             */
/*   Updated: 2020/08/12 16:17:09 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_factorial(int nb)
{
	int	ret;
	int	i;

	if (nb < 0)
		return (0);
	ret = 1;
	i = 1;
	while (i <= nb)
	{
		ret *= i;
		i++;
	}
	return (ret);
}
