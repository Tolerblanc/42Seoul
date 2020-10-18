/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 14:04:30 by hyunjuki          #+#    #+#             */
/*   Updated: 2020/10/18 16:54:08 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	word_count(char *s, char c)
{
	size_t		i;
	size_t		ret;

	i = 0;
	ret = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			while (s[i] != c && s[i])
				i++;
			ret++;
		}
		else
			i++;
	}
	return (ret);
}

static size_t	wordlen(char *s, int idx, char c)
{
	size_t		i;

	i = 0;
	while (s[i + idx] && s[i + idx] != c)
		i++;
	return (i);
}

void			getstr(char *s, char c, size_t word, char **ret)
{
	size_t		i;
	size_t		len;
	size_t		curr;

	i = 0;
	curr = 0;
	while (s[curr] == c)
		curr++;
	while (s[curr] && i < word)
	{
		len = wordlen(s, curr, c);
		if ((ret[i] = (char *)malloc(len + 1)) == NULL)
			return ;
		ft_strlcpy(ret[i], &s[curr], len + 1);
		curr = curr + len;
		while (s[curr] && s[curr] == c)
			curr++;
		i++;
	}
}

char			**ft_split(char const *s, char c)
{
	char		**ret;
	size_t		i;
	size_t		word;

	if (!s)
		return (NULL);
	word = word_count((char *)s, c);
	if ((ret = (char **)malloc(sizeof(char *) * word + 1)) == NULL)
		return (NULL);
	i = 0;
	ret[word] = NULL;
	getstr((char *)s, c, word, ret);
	return (ret);
}
