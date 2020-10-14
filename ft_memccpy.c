/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 14:32:47 by hyunjuki          #+#    #+#             */
/*   Updated: 2020/10/14 14:37:45 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*p1;
	unsigned char	*p2;
	unsigned char	s;

	p1 = (unsigned char *)dst;
	p2 = (unsigned char *)src;
	s = (unsigned char)c;
	while (n--)
	{
		if (c == *p2)
			return ((void *)p1);
		*p1++ = *p2++;
	}
	return ((void *)0);
}
