/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avila-ca <avila-ca@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:18:09 by avila-ca          #+#    #+#             */
/*   Updated: 2022/01/24 10:32:48 by avila-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		len;
	char	*ptr;

	ptr = (char *)s;
	len = ft_strlen(s);
	while (c >= 256)
		c = c - 256;
	while (len >= 0)
	{
		if (ptr[len] == c)
			return (&(ptr[len]));
	len--;
	}
	return (0);
}
