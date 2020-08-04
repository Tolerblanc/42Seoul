/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_nummeric.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 22:49:26 by hyunjuki          #+#    #+#             */
/*   Updated: 2020/08/04 23:05:51 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_str_is_numeric(char *str)
{
	int	boolean;

	boolean = 1;
	while (*str != '\0')
	{
		if (!(*str >= '0' && *str <= '9'))
		{
			boolean = 0;
		}
		str++;
	}
	return (boolean);
}
