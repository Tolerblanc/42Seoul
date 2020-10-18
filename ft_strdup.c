/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 12:34:04 by hyunjuki          #+#    #+#             */
/*   Updated: 2020/10/14 12:59:51 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s1)
{
	size_t	i;
	char	*ret;

	i = ft_strlen(s1);
	ret = (char *)malloc(sizeof(char) * i);
	if (ret == 0)
		return (ret);
	while (*s1)
		*ret++ = *s1++;
	*ret = '\0';
	return (ret);
}
