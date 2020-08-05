/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 13:54:54 by hyunjuki          #+#    #+#             */
/*   Updated: 2020/08/05 16:03:42 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int			is_printable(char str)
{
	if (str >= ' ' && str <= '~')
		return (1);
	else
		return (0);
}

void		prt_hex(char arr[], int idx)
{
	write(1, "\\", 1);
	while (idx >= 0)
	{
		write(1, &arr[idx], 1);
		idx--;
	}
}

void		get_hex(char str)
{
	char	hex[42];
	int		idx;
	int		ascii;
	int		mod;

	ascii = str;
	idx = 0;
	while (ascii != 0)
	{
		mod = ascii % 16;
		if (mod < 10)
			hex[idx] = mod + '0';
		else
			hex[idx] = mod - 10 + 'a';
		ascii /= 16;
		idx++;
	}
	if (idx == 1)
		hex[idx++] = '0';
	hex[idx] = '\0';
	prt_hex(hex, idx - 1);
}

void		ft_putstr_non_printable(char *str)
{
	int		i;

	i = 0;
	while (*(str + i) != '\0')
	{
		if (is_printable(*(str + i)))
			write(1, str + i, 1);
		else
			get_hex(*(str + i));
		i++;
	}
}
