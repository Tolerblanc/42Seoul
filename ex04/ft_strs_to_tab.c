/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 15:16:25 by hyunjuki          #+#    #+#             */
/*   Updated: 2020/08/17 15:44:23 by hyunjuki         ###   ########.fr       */
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

char				*ft_strcpy(char *str, int size)
{
	char			*res;
	int				i;

	res = (char *)malloc(sizeof(char) * (size + 1));
	if (res == 0)
		return (0);
	i = 0;
	while (str[i])
	{
		res[i] = str[i];
		i++;
	}
	res[i]= 0;
	return (res);
}

t_stock_str			*get_tab(t_stock_str *ret, char *av)
{
	ret -> str = av;
	ret -> size = ft_strlen(av);
	ret -> copy = ft_strcpy(av, ret -> size);
	if (ret -> copy == 0)
		return (0);
	return (ret);
}

void				free_tab(t_stock_str *tab, int size)
{
	int				i;

	i = 0;
	while (i < size)
	{
		free(tab[i].copy);
		i++;
	}
	free(tab);
}

struct s_stock_str  *ft_strs_to_tab(int ac, char **av)
{
	t_stock_str		*ret;
	t_stock_str		*temp;
	int				i;

	i = 0;
	ret = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (ret == 0)
		return (0);
	while (i < ac)
	{
		temp = get_tab(ret + i, *(av + i));
		if (temp == 0)
		{
			free_tab(ret, i);
			return (0);
		}
		i++;
	}
	return (ret);
}

