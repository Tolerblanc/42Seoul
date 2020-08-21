/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 02:41:30 by hyunjuki          #+#    #+#             */
/*   Updated: 2020/08/19 03:03:38 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		ft_swap(char **a, char **b)
{
	char	*temp;

	temp = *b;
	*b = *a;
	*a = temp;
}

void		ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int		i;
	int		j;
	int		len;

	len = 0;
	while (tab[len])
		len++;
	i = 0;
	while (i < len - 1)
	{
		j = 0;
		while (j < len - 1 - i)
		{
			if (cmp(tab[j], tab[j + 1]) > 0)
				ft_swap(&tab[j], &tab[j + 1]);
			j++;
		}
		i++;
	}
}
