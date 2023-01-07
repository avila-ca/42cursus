/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avila-ca <avila-ca@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:25:49 by avila-ca          #+#    #+#             */
/*   Updated: 2022/02/15 17:54:24 by avila-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_words(char const *s, char c)
{
	int	words;
	int	i;

	i = 0;
	words = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			words++;
		i++;
	}
	return (words);
}

char	**ft_make_array(int words)
{
	char	**arr;

	arr = (char **)ft_calloc(sizeof(char *), words + 1);
	if (!arr)
		return (0);
	return (arr);
}

int	len_word(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

char	**ft_words_in_array(char **arr, char *s, char c, int words)
{
	int	i;
	int	filas;

	i = 0;
	filas = 0;
	while (words > 0)
	{
		while (s[i] == c)
			i++;
		arr[filas] = ft_substr(s, i, len_word(&s[i], c));
		words--;
		filas++;
		i = len_word(&s[i], c) + i;
		i++;
	}
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		words;

	if (!s)
		return (0);
	words = ft_count_words(s, c);
	arr = ft_make_array(words);
	if (!arr)
		return (0);
	arr = ft_words_in_array(arr, (char *)s, c, words);
	return (arr);
}
