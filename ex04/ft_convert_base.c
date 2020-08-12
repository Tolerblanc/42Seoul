/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 22:06:46 by hyunjuki          #+#    #+#             */
/*   Updated: 2020/08/13 05:32:02 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (*(str + i) != '\0')
	{
		i++;
		if (*(str + i) == '+' || *(str + i) == '-')
			return (-1);
		j = 0;
		while (*(str + j) != '\0')
		{
			if (*(str + i) == *(str + j) && i != j)
				return (-1);
			j++;
		}
	}
	return (i);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int	from_len;
	int	to_len;
	int	sign;

	from_len = ft_strlen(base_from);
	to_len = ft_strlen(base_to);
	if (from_len == -1 || to_len == -1)
		return ((void *)0);
	while ()
	
}