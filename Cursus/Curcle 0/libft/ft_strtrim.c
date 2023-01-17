/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 16:18:31 by hyunjuki          #+#    #+#             */
/*   Updated: 2020/10/18 18:27:40 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ainstr(const char c, const char *s)
{
	while (*s)
	{
		if (c == *s++)
			return (1);
	}
	return (0);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	size_t		front;
	size_t		back;
	size_t		len;
	char		*ret;

	if (!set || !s1)
		return ((char *)s1);
	front = 0;
	back = ft_strlen(s1) - 1;
	while (ainstr(s1[front], set) && front <= ft_strlen(s1))
		front++;
	while (ainstr(s1[back], set) && back != 0)
		back--;
	len = back > front ? back - front + 1 : 0;
	if (len <= 1)
		return (ft_strdup(""));
	if (!(ret = ft_calloc(sizeof(char), len + 1)))
		return (NULL);
	ft_strlcpy(ret, s1 + front, len + 1);
	return (ret);
}
