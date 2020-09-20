/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 20:16:31 by hyunjuki          #+#    #+#             */
/*   Updated: 2020/08/12 20:39:09 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char		*ft_strdup(char *src)
{
	int		len;
	int		i;
	char	*str;

	while (*(src + len) != '\0')
		len++;
	str = (char *)malloc(sizeof(char) * len + 1);
	i = 0;
	while (*(src + i) != '\0')
	{
		*(str + i) = *(src + i);
		i++;
	}
	*(str + i) = '\0';
	return (str);
}
