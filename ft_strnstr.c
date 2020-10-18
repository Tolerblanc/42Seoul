/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 11:44:16 by hyunjuki          #+#    #+#             */
/*   Updated: 2020/10/18 18:13:22 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	chkstr(const char *str, const char *target, size_t curr,
	size_t limit)
{
	size_t	i;

	i = 0;
	while (str[curr + i] && target[i] && curr + i < limit)
	{
		if (str[curr + i] != target[i])
			return (0);
		i++;
	}
	return ((target[i] || curr + i >= limit) ? 0 : 1);
}

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len && haystack[i])
	{
		if (chkstr(haystack, needle, i, len))
			return ((char *)(haystack + i));
		i++;
	}
	return (NULL);
}
