/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 23:09:55 by hyunjuki          #+#    #+#             */
/*   Updated: 2020/08/04 23:20:49 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_str_is_lowercase(char *str)
{
	int	boolean;

	boolean = 1;
	while (*str != '\0')
	{
		if (!(*str >= 'a' && *str <= 'z'))
		{
			boolean = 0;
		}
		str++;
	}
	return (boolean);
}
