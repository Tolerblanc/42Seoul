/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 20:43:56 by hyunjuki          #+#    #+#             */
/*   Updated: 2020/08/13 04:11:58 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int			ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (*(str + i) != '\0')
		i++;
	return (i);
}

int			ft_strsize(int size, char **strs, char *sep)
{
	int		ret;
	int		i;

	ret = ft_strlen(sep);
	i = 0;
	while (i < size)
	{
		ret += ft_strlen(strs[i]);
		i++;
	}
	return (ret);
}

int			make_str(char *ret, char *str)
{
	int		size;

	size = ft_strlen(ret);
	while (*str != '\0')
	{
		*(ret + size) = *str;
		str++;
		size++;
	}
	return (size);
}

char		*ft_strjoin(int size, char **strs, char *sep)
{
	char	*ret;
	int		s;
	int		i;
	int		j;
	int		k;

	if (size == 0)
	{
		ret = (char *)malloc(sizeof(char));
		*ret = "";
		return (ret);
	}
	s = ft_strsize(size, strs, sep);
	ret = (char *)malloc(sizeof(char) * (++s));
	i = 0;
	while (i < size)
	{
		j = make_str(ret, strs[i]);
		if (i != size - 1)
			j = make_str(ret, sep);
		else
			ret[j] = '\0';
		i++;
	}
	return (ret);
}
