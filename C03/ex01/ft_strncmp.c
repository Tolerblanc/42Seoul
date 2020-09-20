/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 16:40:44 by hyunjuki          #+#    #+#             */
/*   Updated: 2020/08/10 11:06:53 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int					ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && *(s1 + i) != '\0' && *(s2 + i) != '\0')
	{
		if (*(s1 + i) > *(s2 + i) || *(s1 + i) < *(s2 + i))
			return (*(s1 + i) - *(s2 + i));
		i++;
	}
	if (i < n && (*(s1 + i) == '\0' || *(s2 + i) == '\0'))
	{
		if (*(s1 + i) > *(s2 + i) || *(s1 + i) < *(s2 + i))
			return (*(s1 + i) - *(s2 + i));
	}
	return (0);
}
