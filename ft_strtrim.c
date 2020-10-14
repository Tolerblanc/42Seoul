/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 16:18:31 by hyunjuki          #+#    #+#             */
/*   Updated: 2020/10/14 16:45:33 by hyunjuki         ###   ########.fr       */
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
	char		*ret;
	int			i;

	front = 0;
	back = ft_strlen(s1) - 1;
	while (ainstr(*(s1 + front), set))
		front++;
	while (ainstr(*(s1 + back), set))
		back--;
	ret = (char *)malloc(back - front + 2);
	if (ret == 0)
		return (ft_strdup(""));
	ft_strlcpy(ret, s1 + front, sizeof(ret));
	return (ret);
}
