/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 17:04:43 by hyunjuki          #+#    #+#             */
/*   Updated: 2020/08/02 17:08:32 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void		ft_is_negative(int n)
{
	char	boolean;

	if (n >= 0)
		boolean = 'P';
	else
		boolean = 'N';
	write(1, &boolean, 1);
}
