/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 14:39:34 by hyunjuki          #+#    #+#             */
/*   Updated: 2020/08/02 14:43:22 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print_roof_tile(int idx, int x)
{
	if (idx == 0 | idx == x - 1)
		ft_putchar('o');
	else
		ft_putchar('-');
}

void	print_body(int idx, int x)
{
	if (idx == 0 || idx == x - 1)
		ft_putchar('|');
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
			if (idx_y == 0 || idx_y == y - 1)
				print_roof_tile(idx_x, x);
			else
				print_body(idx_x, x);
			idx_x++;
		}
		ft_putchar('\n');
		idx_x = 0;
		idx_y++;
	}
}
