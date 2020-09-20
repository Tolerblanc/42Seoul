/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 15:16:25 by hyunjuki          #+#    #+#             */
/*   Updated: 2020/08/19 01:48:12 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int					ft_strlen(char *str)
{
	int				i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char				*ft_strcpy(char *dest, char *src)
{
	int				i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str		*ret;
	int				i;

	i = 0;
	ret = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (ret == 0)
		return (0);
	while (i < ac)
	{
		ret[i].size = ft_strlen(av[i]);
		ret[i].str = (char *)malloc(ret[i].size + 1);
		ret[i].copy = (char *)malloc(ret[i].size + 1);
		ft_strcpy(ret[i].str, av[i]);
		ft_strcpy(ret[i].copy, av[i]);
		i++;
	}
	ret[i].str = 0;
	return (ret);
}
