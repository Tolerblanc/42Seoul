/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 16:37:08 by hyunjuki          #+#    #+#             */
/*   Updated: 2020/08/16 21:03:46 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				ft_is_prime(int nb)
{
	int			i;
	int			temp;

	if (nb <= 1)
		return (0);
	i = 2;
	temp = nb / 2;
	while (i <= temp && i <= 65536)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int				ft_find_next_prime(int nb)
{
	int			i;

	i = nb;
	while (ft_is_prime(i) == 0)
		i++;
	return (i);
}
