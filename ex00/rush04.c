/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 15:31:07 by hyunjuki          #+#    #+#             */
/*   Updated: 2020/08/01 16:33:44 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print_roof(int idx, int x)
{
	if (idx == 0)
		ft_putchar('A');
	else if (idx == x - 1)
		ft_putchar('C');
	else
		ft_putchar('B');
}

void	print_tile(int idx, int x)
{
	if (idx == 0)
		ft_putchar('C');
	else if (idx == x - 1)
		ft_putchar('A');
	else
		ft_putchar('B');
}

void	print_body(int idx, int x)
{
	if (idx == 0 || idx == x - 1)
		ft_putchar('B');
	else
		ft_putchar(' ');
}

void	rush(int x, int y)
{
	int idx_x;
	int idx_y;

	idx_x = 0;
	idx_y = 0;
	while (idx_y < y)
	{
		while (idx_x < x)
		{
			if (idx_y == 0)
				print_roof(idx_x, x);
			else if (idx_y == y - 1)
				print_tile(idx_x, x);
			else
				print_body(idx_x, x);
			idx_x++;
		}
		ft_putchar('\n');
		idx_x = 0;
		idx_y++;
	}
}
