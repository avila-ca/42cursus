/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avila-ca <avila-ca@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 19:14:38 by avila-ca          #+#    #+#             */
/*   Updated: 2022/02/03 16:49:33 by avila-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = ft_strlen(src);
	if (dstsize > 0)
	{
		while ((src[i]) && (i < dstsize - 1))
		{
		dst[i] = src[i];
		i++;
		}
		dst[i] = '\0';
	}
	return (count);
}
