/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avila-ca <avila-ca@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 17:32:23 by avila-ca          #+#    #+#             */
/*   Updated: 2022/02/15 18:28:20 by avila-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;

	if (!s)
		return (0);
	if (start >= (unsigned int)ft_strlen(s))
		return ((char *)ft_calloc(1, 1));
	if (len > (size_t) ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	dest = (char *) ft_calloc(sizeof(char), 1 * len + 1);
	if (dest == NULL)
		return (NULL);
	dest = ft_memmove(dest, &s[start], len);
	return (dest);
}
