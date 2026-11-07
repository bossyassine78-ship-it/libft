/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-hil <yael-hil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 05:19:32 by username          #+#    #+#             */
/*   Updated: 2026/11/04 13:22:28 by yael-hil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_free(char **stock, size_t word)
{
	while (word > 0)
	{
		word--;
		free(stock[word]);
	}
	free(stock);
	return (NULL);
}

static size_t	count_word(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static char	**full_bytes(char **stock, const char *s, const char c)
{
	size_t	word;
	size_t	place;
	size_t	i;
	size_t	len;

	len = count_word(s, c);
	word = 0;
	i = 0;
	place = 0;
	while (word < len)
	{
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{
			i++;
			place++;
		}
		stock[word] = malloc(place + 1);
		if (!stock[word])
			return (ft_free(stock, word));
		place = 0;
		word++;
	}
	return (stock);
}

static char	**full_words(char **stock, const char *s, char c)
{
	size_t	word;
	size_t	place;
	size_t	i;

	word = 0;
	i = 0;
	place = 0;
	stock = full_bytes(stock, s, c);
	if (!stock)
		return (NULL);
	while (word < count_word(s, c))
	{
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{
			stock[word][place] = s[i];
			i++;
			place++;
		}
		stock[word][place] = '\0';
		place = 0;
		word++;
	}
	return (stock);
}

char	**ft_split(char const *s, char c)
{
	char	**stock;
	size_t	total_word;

	if (!s)
		return (NULL);
	total_word = count_word(s, c);
	stock = malloc((total_word + 1) * sizeof(char *));
	if (!stock)
		return (NULL);
	stock[total_word] = NULL;
	return (full_words(stock, s, c));
}
