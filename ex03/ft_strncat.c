/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 20:38:23 by hyunjuki          #+#    #+#             */
/*   Updated: 2020/08/05 20:43:43 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char				*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (*(dest + i) != '\0')
		i++;
	while (*src != '\0' && j < nb)
	{
		*(dest + i) = *src;
		src++;
		i++;
		j++;
	}
	*(dest + i) = '\0';
}
