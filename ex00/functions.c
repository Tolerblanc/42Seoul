/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 15:25:48 by hyunjuki          #+#    #+#             */
/*   Updated: 2020/08/08 18:20:06 by chelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_strlen(char *str)
{
	int		len;

	len = 0;
	while (*str != '\0')
	{
		len++;
		str++;
	}
	return (len);
}

void		push_arr(int *arr, int value)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		if (arr[i] == 0)
		{
			arr[i] = value;
			return ;
		}
		else
		{
			i++;
		}
	}
}

void		pop_arr(int *arr)
{
	int		i;

	i = 3;
	while (i >= 0)
	{
		if (arr[i] != 0)
		{
			arr[i] = 0;
			return ;
		}
		else
		{
			i--;
		}
	}
}

void		push_map(int **map, int **arr_case, int value)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		if (map[i] == (void *)0)
		{
			map[i] = arr_case[value];
			return ;
		}
		else
		{
			i++;
		}
	}
}

void		pop_map(int **map)
{
	int		i;

	i = 3;
	while (i >= 0)
	{
		if (map[i] != (void *)0)
		{
			map[i] = (void *)0;
			return ;
		}
		else
		{
			i--;
		}
	}
}
