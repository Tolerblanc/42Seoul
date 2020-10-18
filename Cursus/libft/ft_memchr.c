/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 14:51:50 by hyunjuki          #+#    #+#             */
/*   Updated: 2020/10/14 14:56:28 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*p;
	unsigned char	s;

	p = (unsigned char *)s;
	s = (unsigned char)c;
	while (n--)
	{
		if (*p++ == s)
			return ((void *)p);
	}
	return ((void *)0);
}
