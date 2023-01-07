/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avila-ca <avila-ca@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 11:23:32 by avila-ca          #+#    #+#             */
/*   Updated: 2022/01/28 19:09:35 by avila-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	idst;
	size_t	isrc;
	size_t	lendst;
	size_t	lensrc;

	lendst = ft_strlen(dst);
	lensrc = ft_strlen (src);
	idst = lendst;
	isrc = 0;
	if (dstsize < 1)
		return (lensrc + dstsize);
	while (src[isrc] != '\0' && idst < dstsize -1)
	{
		dst[idst] = src[isrc];
		isrc++;
		idst++;
	}
	dst[idst] = '\0';
	if (dstsize < lendst)
		return (dstsize + lensrc);
	return (lensrc + lendst);
}
