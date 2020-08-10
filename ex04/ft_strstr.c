/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 20:48:32 by hyunjuki          #+#    #+#             */
/*   Updated: 2020/08/10 13:57:56 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char		*chk_str(char *str, char *target, int idx, int target_length)
{
	int		i;

	i = 0;
	while (i < target_length && *(str + i) != '\0')
	{
		if (*(str + idx + i) != *(target + i))
			return (0);
		i++;
	}
	return (i < target_length ? 0 : str + idx);
}

char		*ft_strstr(char *str, char *to_find)
{
	char	*ret;
	int		length;
	int		i;

	if (*to_find == '\0')
		return (str);
	i = 0;
	length = 0;
	ret = 0;
	while (*(to_find + length) != '\0')
		length++;
	while (*(str + i) != '\0')
	{
		if (*(str + i) == *to_find)
			ret = chk_str(str, to_find, i, length);
		i++;
	}
	return (ret);
}
