/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avila-ca <avila-ca@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 17:22:30 by avila-ca          #+#    #+#             */
/*   Updated: 2022/02/11 20:25:27 by avila-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	size_t	len;

	if (!s1 || !s2)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2);
	if (len == 0)
		return (ft_calloc(1, 1));
	dest = (char *) ft_calloc(len + 1, sizeof(char));
	if (!dest)
		return (0);
	ft_memmove (&dest[0], s1, ft_strlen(s1));
	ft_memmove (&dest[ft_strlen(s1)], s2, ft_strlen(s2));
	return (dest);
}
