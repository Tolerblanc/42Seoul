/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_arr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelee <chelee@42seoul.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 14:12:18 by chelee            #+#    #+#             */
/*   Updated: 2020/08/08 18:26:17 by chelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

extern int		g_case[24][4];
extern void		make_case(void);
extern void		push_map(int **map, int arr_case[24][4], int value);
extern void		pop_map(int **map);

int				**g_map;
int				g_map_select[24];
int				g_cnt;

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

void			show(void)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			if (g_map[i][j] < 1 || g_map[i][j] > 4)
			{
				printf("error: %d", g_map[i][j]);
				return ;
			}
			j++;
		}
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
	j = 0;
	while (i < 4)
	{
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

	if (cnt == 4)
	{
		g_cnt++;
		/* test */
		return ;
	}
	if (cnt > 1)
	{
		result = test_func(cnt);
		if (result)
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
		pop_map(g_map);
		g_map_select[i] = 0;
		i++;
	}
}