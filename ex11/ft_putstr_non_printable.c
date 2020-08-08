/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 13:54:54 by hyunjuki          #+#    #+#             */
/*   Updated: 2020/08/08 12:56:53 by hyunjuki         ###   ########.fr       */
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

char		dec2hex(int	n)
{
	if(n < 10)
		return (n + '0');
	else
		return (n - 10 + 'a');
}

void		get_hex(char str)
{
	char	ascii;

	write(1,"\\",1);
	ascii = dec2hex(str / 16 % 16);
	write(1,&ascii,1);
	ascii = dec2hex(str / 16);
	write(1,&ascii,1);
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
