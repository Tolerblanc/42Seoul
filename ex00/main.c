/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 14:11:56 by hyunjuki          #+#    #+#             */
/*   Updated: 2020/08/08 21:27:31 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void			init_args(char *input, int *output);
void			free_allo(void);
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
	if (g_result != 0)
		write(1, "Error : There is no such case :(\n", 33);
	return (0);
}

void			free_allo(void)
{
	free(g_map[0]);
	free(g_map[1]);
	free(g_map[2]);
	free(g_map[3]);
	free(g_map);
	return ;
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
