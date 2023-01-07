/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avila-ca <avila-ca@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:30:49 by avila-ca          #+#    #+#             */
/*   Updated: 2022/01/25 16:01:00 by avila-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	count;

	j = 0;
	count = 0;
	i = 0;
	j = ft_strlen(needle);
	count = j;
	if (needle[0] == '\0')
		return ((char *)haystack);
	i = 0;
	while ((haystack[i] != '\0') && (i <= len - count)
		&& (len > 0) && !(len < count))
	{
		j = 0;
		while ((haystack[i + j] == needle[j]) && (haystack [i + j] != '\0')
			&& (j < count))
			j++;
		if (j == count)
			return (&((char *)haystack)[i]);
		i++;
	}
	return (0);
}
