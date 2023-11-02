/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkhachab <nkhachab@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 23:41:07 by nkhachab          #+#    #+#             */
/*   Updated: 2022/11/03 23:03:21 by nkhachab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_count_words(char *str, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == c && str[i])
			i++;
		if (str[i])
			count++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (count);
}

static char	*ft_alloc_word(char *str, char c)
{
	char	*word;
	int		word_len;
	int		i;

	word_len = 0;
	while (str[word_len] && str[word_len] != c)
		word_len++;
	word = malloc(sizeof(char) * (word_len + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != c)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(const char *s, char c)
{
	char	**output;
	int		j;
	int		i;

	if (!s)
		return (NULL);
	output = malloc(sizeof(char *) * (ft_count_words((char *)s, c) + 1));
	if (!output)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			output[j] = ft_alloc_word((char *)&s[i], c);
			j++;
		}
		while (s[i] && s[i] != c)
			i++;
	}
	output[j] = NULL;
	return (output);
}
