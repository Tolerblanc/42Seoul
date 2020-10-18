/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 11:44:16 by hyunjuki          #+#    #+#             */
/*   Updated: 2020/10/18 16:00:35 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	chkstr(const char *str, const char *target)
{
	while (*str && *target)
	{
		if (*str++ != *target++)
			return (0);
	}
	return (*target ? 0 : 1);
}

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len && haystack[i])
	{
		if (chkstr(haystack + i, needle))
			return ((char *)(haystack + i));
		i++;
	}
	return ((void *)0);
}
