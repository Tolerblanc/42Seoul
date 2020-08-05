/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 21:39:23 by hyunjuki          #+#    #+#             */
/*   Updated: 2020/08/05 21:51:24 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(char *str)
{
	int	cnt;

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
	int				i;
	int				j;

	d_len = (unsigned int)ft_strlen(dest);
	s_len = (unsigned int)ft_strlen(src);
	i = 0;
	j = d_len;
	while (*(src + i) != '\0' && i < (int)(size - d_len - 1))
	{
		*(dest + j) = *(src + i);
		i++;
		j++;
	}
	*(dest + j) = '\0';
	if (size < d_len)
		return (s_len + size);
	else
		return (d_len + s_len);
}
