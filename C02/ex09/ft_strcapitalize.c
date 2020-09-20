/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 12:25:31 by hyunjuki          #+#    #+#             */
/*   Updated: 2020/08/05 13:24:37 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			chk_first(char *str, int idx)
{
	int		i;

	i = idx - 1;
	if (i < 0)
		return (1);
	else if (*(str + i) >= 'A' && *(str + i) <= 'Z')
		return (0);
	else if (*(str + i) >= 'a' && *(str + i) <= 'z')
		return (0);
	else if (*(str + i) >= '0' && *(str + i) <= '9')
		return (0);
	return (1);
}

void		ft_toupper(char *str, int idx)
{
	if (*(str + idx) >= 'a' && *(str + idx) <= 'z')
		*(str + idx) -= 32;
}

void		ft_tolower(char *str, int idx)
{
	if (*(str + idx) >= 'A' && *(str + idx) <= 'Z')
		*(str + idx) += 32;
}

char		*ft_strcapitalize(char *str)
{
	int		i;

	i = 0;
	while (*(str + i) != '\0')
	{
		if (chk_first(str, i))
			ft_toupper(str, i);
		else
			ft_tolower(str, i);
		i++;
	}
	return (str);
}
