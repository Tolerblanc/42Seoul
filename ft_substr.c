/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 15:11:12 by hyunjuki          #+#    #+#             */
/*   Updated: 2020/10/14 16:03:42 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*ret;
	unsigned int	i;

	i = 0;
	ret = (char *)malloc(len + 1);
	if (ret == 0)
		return ((void *)0);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	while (len-- && *s)
		ret[i++] = *(s + start++);
	ret[i] = '\0';
	return (ret);
}
