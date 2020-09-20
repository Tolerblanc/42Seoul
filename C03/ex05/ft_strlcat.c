/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 21:39:23 by hyunjuki          #+#    #+#             */
/*   Updated: 2020/08/10 17:08:48 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int		ft_strlen(char *str)
{
	unsigned int	cnt;

	cnt = 0;
	while (*str != '\0')
	{
		cnt++;
		str++;
	}
	return (cnt);
}

unsigned int		ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	d_len;
	unsigned int	s_len;
	unsigned int	i;
	unsigned int	j;

	d_len = ft_strlen(dest);
	s_len = ft_strlen(src);
	i = 0;
	j = d_len;
	while (*(src + i) != '\0' && i + d_len + 1 < size)
	{
		*(dest + j) = *(src + i);
		i++;
		j++;
	}
	*(dest + j) = '\0';
	return (size < d_len ? s_len + size : d_len + s_len);
}
