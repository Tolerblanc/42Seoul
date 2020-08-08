/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_arr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelee <chelee@42seoul.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 14:12:18 by chelee            #+#    #+#             */
/*   Updated: 2020/08/08 18:19:36 by chelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

extern int		g_case[24][4];
extern void		make_case(void);

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

void			push_map(int value)
{
	int			i;

	i = 0;
	while (i < 4)
	{
		if (g_map[i] == (void *)0)
		{
			g_map[i] = g_case[value];
			return ;
		}
		else
		{
			i++;
		}
	}
}

void			pop_map(void)
{
	int			i;

	i = 3;
	while (i >= 0)
	{
		if (g_map[i] != (void *)0)
		{
			g_map[i] = (void *)0;
			return ;
		}
		else
		{
			i--;
		}
	}
}

int				test_func(int row)
{
	int			dup[4];
	int			value;

	for (int i = 0; i<4; i++)
	{
		dup[0] = 0;
		dup[1] = 0;
		dup[2] = 0;
		dup[3] = 0;
		for(int j=0; j<row; j++)
		{
			value = g_map[j][i];
			value -= 1;
			if (dup[value] == 1)
				return (1);
			dup[value] = 1;
		}
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
		push_map(i);
		dfs_map(cnt + 1);
		pop_map();
		g_map_select[i] = 0;
		i++;
	}
}

int				main(void)
{
	init_map();
	make_case();
	/*
	for (int i=0; i<24; i++)
	{
		for (int j=0; j<4; j++)
		{
			printf("%d ", g_case[i][j]);
		}
		printf("\n");
	}*/
	dfs_map(0);
	free(g_map);
	printf("%d", g_cnt);
}
