/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_case.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chelee <chelee@42seoul.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 15:55:51 by chelee            #+#    #+#             */
/*   Updated: 2020/08/08 15:55:53 by chelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int         g_select[4];
int         g_arr[4];
int         g_case[24][4];
int         g_index;

void        init(void)
{
	int     i;

	g_index = 0;
	i = 0;
	while (i < 4)
	{
		g_select[i] = 0;
		g_arr[i] = 0;
		i++;
	}
}

void        write_case(void)
{
	int     i;

	i = 0;
	while (i < 4)
	{
		if (g_select[i] == 1)
		{
			g_case[g_index][i] = g_arr[i];
		}
		i++;
	}
	g_index++;
}

void        push_arr(int value)
{
	int     i = 0;
	while (i < 4)
	{
		if (g_arr[i] == 0)
		{
			g_arr[i] = value;
			return ;
		}
		else
		{
			i++;
		}
	}
}

void        pop_arr(void)
{
	int     i = 3;
	while (i >= 0)
	{
		if (g_arr[i] != 0)
		{
			g_arr[i] = 0;
			return ;
		}
		else
		{
			i--;
		}
	}
}

void        dfs(int cnt)
{
	int     i;

	if (cnt == 4)
	{
		write_case();
		return;
	}
	i = 0;
	while (i < 4)
	{
		if (g_select[i] == 1)
		{
			i++;
			continue;
		}
		g_select[i] = 1;
		push_arr(i + 1);
		dfs(cnt + 1);
		pop_arr();
		g_select[i] = 0;
		i++;
	}
}

void        make_case(void)
{
	init();
	dfs(0);
}