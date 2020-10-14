/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 14:41:00 by hyunjuki          #+#    #+#             */
/*   Updated: 2020/10/14 14:48:08 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *p1;
	unsigned char *p2;

	p1 = (unsigned char *)dst;
	p2 = (unsigned char *)src;
	if (p1 < p2)
	{
		while (len--)
			*p1++ = *p2++;
	}
	else
	{
		p1 += len;
		p2 += len;
		while (len--)
			*--p1 = *--p2;
	}
	return (dst);
}
