/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 17:17:37 by hyunjuki          #+#    #+#             */
/*   Updated: 2020/08/13 03:50:58 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		g_col[10];
int		g_cross1[19];
int		g_cross2[19];
int		g_sel[10];
int		g_cnt;

void		prt_queen(void)
{
	char	c;
	int		i;

	i = 0;
	while (i < 10)
	{
		c = g_sel[i] + '0';
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
}

void		queen(int cnt)
{
	int		y;

	if (cnt == 10)
	{
		prt_queen();
		g_cnt++;
		return ;
	}
	y = -1;
	while (y < 9)
	{
		y++;
		if (g_col[y] || g_cross1[y + cnt] || g_cross2[cnt - y + 9])
			continue;
		g_col[y] = 1;
		g_cross1[y + cnt] = 1;
		g_cross2[cnt - y + 9] = 1;
		g_sel[cnt] = y;
		queen(cnt + 1);
		g_col[y] = 0;
		g_cross1[y + cnt] = 0;
		g_cross2[cnt - y + 9] = 0;
		g_sel[cnt] = -1;
	}
}

int			ft_ten_queens_puzzle(void)
{
	int		i;

	i = 0;
	while (i < 10)
	{
		g_sel[i] = -1;
		i++;
	}
	queen(0);
	return (g_cnt);
}

