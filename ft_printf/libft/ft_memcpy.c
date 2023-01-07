/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avila-ca <avila-ca@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 18:02:39 by avila-ca          #+#    #+#             */
/*   Updated: 2022/01/24 11:36:20 by avila-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*pdest;
	const char	*psrc;

	i = 0;
	pdest = dest;
	psrc = src;
	if (!(dest) && !(src))
		return (0);
	while ((i < n))
	{
		*pdest++ = *psrc++;
		i++;
	}
	return (dest);
}
