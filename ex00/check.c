/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 17:21:08 by hyunjuki          #+#    #+#             */
/*   Updated: 2020/08/08 19:11:56 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		chk_col(int arr[][4], int chk[]);
int		chk_row(int arr[][4], int chk[]);
int		chk_front_line(int arr[], int n);
int		chk_back_line(int arr[], int n);

int		chk_arr(int arr[][4], int chk[])
{
	if (chk_col(arr, chk) || chk_row(arr, chk))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

int		chk_col(int arr[][4], int chk[])
{
	int	i;
	int	j;
	int	line[4];

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			line[j] = arr[j][i];
			j++;
		}
		if (chk_front_linear(line, chk[i]) || chk_back_linear(line, chk[i + 4]))
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int		chk_row(int arr[][4], int chk[])
{
	int	i;
	int	j;
	int	l[4];

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			l[j] = arr[i][j];
			j++;
		}
		if (chk_front_line(l, chk[i + 8]) || chk_back_line(l, chk[i + 12]))
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int		chk_front_line(int arr[], int n)
{
	int	i;
	int	cur;
	int	cnt;

	i = 1;
	cur = arr[0];
	cnt = 1;
	while (i < 4)
	{
		if (arr[i] > cur)
		{
			cnt++;
			cur = arr[i];
		}
		i++;
	}
	return (cnt != n ? 1 : 0);
}

int		chk_back_line(int arr[], int n)
{
	int	i;
	int	cur;
	int	cnt;

	i = 2;
	cur = arr[3];
	cnt = 1;
	while (i >= 0)
	{
		if (arr[i] > cur)
		{
			cnt++;
			cur = arr[i];
		}
		i--;
	}
	return (cnt != n ? 1 : 0);
}
