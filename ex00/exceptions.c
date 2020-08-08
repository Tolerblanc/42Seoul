/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exceptions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 15:25:45 by hyunjuki          #+#    #+#             */
/*   Updated: 2020/08/08 18:50:51 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

extern int		ft_strlen(char *str);
int				chk_args(char *str);

int				except(int argc, char *argv[])
{
	if (argc != 2)
	{
		write(1, "Error0 : invalid arguments", 27);
		return (1);
	}
	if (ft_strlen(argv[1]) != 31)
	{
		write(1, "Error1 : invalid arguments", 27);
		return (1);
	}
	if (chk_args(argv[1]))
	{
		write(1, "Error2 : invalid arguments", 27);
		return (1);
	}
	return (0);
}

int				chk_args(char str[])
{
	int			i;

	i = 0;
	while (*(str + i) != '\0')
	{
		if (i % 2 == 0)
		{
			if (!(*(str + i) >= '1' && *(str + i) <= '4'))
			{
				return (1);
			}
		}
		else
		{
			if (*(str + i) != ' ')
				return (1);
		}
		i++;
	}
	return (0);
}
