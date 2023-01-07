/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avila-ca <avila-ca@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:20:54 by avila-ca          #+#    #+#             */
/*   Updated: 2022/01/27 16:27:29 by avila-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s;

	s = (char *)malloc (sizeof(char) * ft_strlen(s1) + 1);
	if (!s)
		return (0);
	ft_strlcpy (s, s1, ft_strlen(s1) + 1);
	return (s);
}
