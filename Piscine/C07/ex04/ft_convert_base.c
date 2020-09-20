/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 22:06:46 by hyunjuki          #+#    #+#             */
/*   Updated: 2020/08/20 22:43:31 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

extern int		get_base_number(char c, char *base);
extern void		compact(char *arr, int interval);
extern void		init_arr(char *arr, int size);
extern int		ft_strlen(char *str);

int				chk_base(char *base)
{
	int i;
	int j;

	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-'
				|| base[i] == '\n' || base[i] == '\v'
				|| base[i] == '\t' || base[i] == '\f'
				|| base[i] == '\r' || base[i] == ' ')
			return (0);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int				get_base_idx(char c, char *base)
{
	int i;

	if (c == '\t' || c == '\n'
			|| c == '\v' || c == '\f'
			|| c == '\r' || c == ' ')
		return (1);
	if (c == '-')
		return (-1);
	if (c == '+')
		return (-2);
	i = 0;
	while (base[i] != '\0')
	{
		if (c == base[i++])
			return (2);
	}
	return (0);
}

int				base_to_int(char *str, char *base, int length)
{
	int index;
	int count;
	int res;

	index = 0;
	while (get_base_idx(str[index], base) == 1)
		index++;
	count = 1;
	while (get_base_idx(str[index], base) < 0)
	{
		if (get_base_idx(str[index], base) == -1)
			count *= -1;
		index++;
	}
	if (get_base_idx(str[index], base) != 2)
		return (0);
	res = get_base_number(str[index++], base);
	length = ft_strlen(base);
	while (get_base_idx(str[index], base) == 2)
		res = res * length + get_base_number(str[index++], base);
	return (res * count);
}

char			*int_to_base(int nbr, char *base, int len)
{
	char	*res;
	int		i;

	res = (char *)malloc(sizeof(char) * 34);
	i = 0;
	while (i < 34)
		res[i++] = 0;
	if (nbr < 0)
	{
		res[0] = '-';
		nbr = nbr * (-1);
	}
	i = 33;
	while (nbr / len)
	{
		res[i] = base[nbr % len];
		nbr /= len;
		i--;
	}
	res[i] = base[nbr % len];
	compact(res, i);
	return (res);
}

char			*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int			len_from;
	int			len_to;
	int			temp;

	len_from = ft_strlen(base_from);
	len_to = ft_strlen(base_to);
	if (!chk_base(base_from) || !chk_base(base_to))
		return (0);
	temp = base_to_int(nbr, base_from, len_from);
	return (int_to_base(temp, base_to, len_to));
}
