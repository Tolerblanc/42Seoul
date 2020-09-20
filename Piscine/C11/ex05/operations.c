/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 01:54:51 by hyunjuki          #+#    #+#             */
/*   Updated: 2020/08/19 02:20:53 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		add(int a, int b)
{
	return (a + b);
}

int		sub(int a, int b)
{
	return (a - b);
}

int		mul(int a, int b)
{
	return (a * b);
}

int		div(int a, int b)
{
	if (!b)
		return (0);
	return (a / b);
}

int		mod(int a, int b)
{
	if (!b)
		return (-1);
	return (a % b);
}
