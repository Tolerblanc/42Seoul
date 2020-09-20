/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 23:23:51 by hyunjuki          #+#    #+#             */
/*   Updated: 2020/08/05 19:27:30 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_str_is_printable(char *str)
{
	int	boolean;

	boolean = 1;
	while (*str != '\0')
	{
		if (!(*str >= ' ' && *str <= '~'))
		{
			boolean = 0;
		}
		str++;
	}
	return (boolean);
}
