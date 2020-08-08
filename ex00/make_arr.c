/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_arr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 14:12:18 by chelee            #+#    #+#             */
/*   Updated: 2020/08/08 19:54:21 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

extern int		g_case[24][4];
extern int		g_args[16];
extern void		make_case(void);
extern void		push_map(int **map, int arr_case[24][4], int value);
extern void		pop_map(int **map);
extern int		chk_arr(int **arr, int chk[]);
extern void		prt_arr(int **arr);

int				**g_map;
int				g_map_select[24];
int				g_cnt;
int				g_result;

void			init_map(void)
{
	int			i;

	g_map = malloc(sizeof(int *) * 4);
	i = 0;
	g_cnt = 0;
	while (i < 4)
	{
		g_map[i] = malloc(sizeof(int *));
		g_map[i] = (void *)0;
		i++;
	}
	i = 0;
	while (i < 24)
	{
		g_map_select[i] = 0;
		i++;
	}
}

int				test_func(int row)
{
	int			i;
	int			j;
	int			dup[4];
	int			value;

	i = 0;
	while (i < 4)
	{
		j = 0;
		dup[0] = 0;
		dup[1] = 0;
		dup[2] = 0;
		dup[3] = 0;
		while (j < row)
		{
			value = g_map[j][i];
			value -= 1;
			if (dup[value] == 1)
				return (1);
			dup[value] = 1;
			j++;
		}
		i++;
	}
	return (0);
}

void			dfs_map(int cnt)
{
	int			i;
	int			result;

	if (g_result == 0)
		return ;
	if (cnt > 1)
	{
		result = test_func(cnt);
		if (result)
			return ;
	}
	if (cnt == 4)
	{
		g_cnt++;
		g_result = chk_arr(g_map, g_args);
		if (g_result == 1)
		{
			prt_arr(g_map);
		}
		return ;
	}
	i = 0;
	while (i < 24)
	{
		if (g_map_select[i] == 1)
		{
			i++;
			continue ;
		}
		g_map_select[i] = 1;
		push_map(g_map, g_case, i);
		dfs_map(cnt + 1);
		if (g_result == 1)
			return ;
		pop_map(g_map);
		g_map_select[i] = 0;
		i++;
	}
}
