/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 14:11:56 by hyunjuki          #+#    #+#             */
/*   Updated: 2020/08/08 19:11:58 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void			init_args(char *input, int *output);
extern int		except(int argc, char *argv[]);
extern int		chk_arr(int arr[][4],int chk[]);

int				g_args[16];

int				main(int argc, char *argv[])
{
	if (except(argc, argv))
		return (1);
	init_args(argv[1], g_args);

	return (0);
}

void			init_args(char *input, int *output)
{
	int			i;

	i = 0;
	while (*(input + i) != '\0')
	{
		if (i % 2 == 0)
			*(output + (int)(i / 2)) = *(input + i) - '0';
		i++;
	}
}