/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: severi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 23:09:39 by severi            #+#    #+#             */
/*   Updated: 2021/12/06 16:27:43 by severi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(char const *s, char c)
{
	size_t	words;
	size_t	i;
	size_t	begin;

	begin = 0;
	i = 0;
	words = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && begin == 0)
		{
			words++;
			begin = 1;
		}
		else if (s[i] == c)
			begin = 0;
		i++;
	}
	return (words);
}

static size_t	ft_word_len(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0' && s[len] != c)
	{
		len++;
	}
	return (len);
}

static void	free_array(char **spl_s)
{
	size_t	i;

	i = 0;
	while (spl_s[i])
	{
		ft_strdel(&spl_s[i]);
		i++;
	}
}

static int	ft_fill_array(const char *s, char c, char **spl_s, size_t words)
{
	size_t	i;
	size_t	word_len;
	int		j;

	j = 0;
	i = 0;
	word_len = 0;
	while (words > 0)
	{
		while (s[i] == c)
			i++;
		word_len = ft_word_len(s + i, c);
		spl_s[j] = ft_strsub(s, (unsigned int) i, word_len);
		if (spl_s[j++] == NULL)
		{
			free_array(spl_s);
			return (-1);
		}
		i += word_len;
		words--;
	}
	spl_s[j] = NULL;
	return (j);
}

char	**ft_strsplit(const char *s, char c)
{
	char	**spl_s;
	size_t	words;

	if (s == NULL)
		return (NULL);
	words = ft_count_words(s, c);
	spl_s = (char **)malloc(sizeof(spl_s) * (words + 1));
	if (spl_s == NULL)
		return (NULL);
	if (ft_fill_array(s, c, spl_s, words) == -1)
		return (NULL);
	return (spl_s);
}
