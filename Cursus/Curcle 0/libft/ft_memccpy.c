/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 14:32:47 by hyunjuki          #+#    #+#             */
/*   Updated: 2020/10/18 17:52:05 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	int				boo;
	unsigned char	*p;

	p = (unsigned char *)src;
	i = 0;
	boo = 0;
	while (i < n && p[i] && !boo)
	{
		boo = ((p)[i] == (unsigned char)c) ? 1 : 0;
		i++;
	}
	if (boo)
	{
		ft_memcpy(dst, p, i);
		return (dst + i);
	}
	else
	{
		ft_memcpy(dst, p, n);
		return (0);
	}
}
