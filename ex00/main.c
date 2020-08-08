/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 14:11:56 by hyunjuki          #+#    #+#             */
/*   Updated: 2020/08/08 21:06:51 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void			init_args(char *input, int *output);
extern int		except(int argc, char *argv[]);
extern void		init_map(void);
extern void		make_case(void);
extern void		dfs_map(int cnt);
extern void		prt_arr(int **arr);
extern int		g_result;
extern int		**g_map;
int				g_args[16];

int				main(int argc, char *argv[])
{
	if (except(argc, argv))
		return (1);
	init_args(argv[1], g_args);
	init_map();
	make_case();
	dfs_map(0);
	//free(g_map);
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
