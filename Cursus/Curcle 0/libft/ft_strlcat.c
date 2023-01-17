/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 11:11:46 by hyunjuki          #+#    #+#             */
/*   Updated: 2020/10/18 16:31:56 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	d_len;
	size_t	s_len;
	int		i;
	int		j;

	d_len = ft_strlen(dest);
	s_len = ft_strlen(src);
	i = 0;
	j = d_len;
	while (*(src + i) != '\0' && i < (int)(size - d_len - 1))
	{
		*(dest + j) = *(src + i);
		i++;
		j++;
	}
	*(dest + j) = '\0';
	if (size < d_len)
		return (s_len + size);
	else
		return (d_len + s_len);
}
