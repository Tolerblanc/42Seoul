/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 00:01:19 by hyunjuki          #+#    #+#             */
/*   Updated: 2020/08/20 23:05:13 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		g_retidx;
int		g_strcnt;

int				chk_charset(char c, char *str)
{
	while (*str != '\0')
	{
		if (c == *str)
			return (1);
		str++;
	}
	return (0);
}

int				ft_strlen(char *str)
{
	int			i;

	i = 0;
	while (*(str + i))
		i++;
	return (i);
}

int				word_len(char *str, char *charset)
{
	int			i;
	int			cnt;

	i = 0;
	cnt = 0;
	if (*str && !chk_charset(*str, charset))
	{
		i++;
		cnt++;
	}
	while (*(str + i))
	{
		if (chk_charset(*(str + i), charset)
			&& !chk_charset(*(str + i + 1), charset) && *(str + i + 1))
			cnt++;
		i++;
	}
	return (cnt);
}

char			*get_str(char *str, int idx, int *n)
{
	int			i;
	char		*ret;

	if (*n == -1)
	{
		*n = 0;
		while (*(str + *n))
			*n = *n + 1;
	}
	ret = (char *)malloc(sizeof(char) * (idx - *n + 1));
	i = 0;
	while (i < (idx - *n))
	{
		ret[i] = str[*n + i];
		i++;
	}
	ret[i] = '\0';
	*n = idx + 1;
	return (ret);
}

char			**ft_split(char *str, char *charset)
{
	int			i;
	char		**ret;

	i = 0;
	ret = (char **)malloc(sizeof(char *) * (word_len(str, charset) + 1));
	while (*(str + i))
	{
		if ((chk_charset(*(str + i), charset) || !*(str + i + 1)))
		{
			if (g_strcnt == i)
			{
				g_strcnt++;
				i++;
				continue;
			}
			ret[g_retidx++] = get_str(str, i++, &g_strcnt);
			continue;
		}
		i++;
	}
	ret[g_retidx] = 0;
	return (ret);
}
