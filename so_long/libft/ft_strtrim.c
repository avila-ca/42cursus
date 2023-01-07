/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avila-ca <avila-ca@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 16:04:45 by avila-ca          #+#    #+#             */
/*   Updated: 2022/02/03 16:56:15 by avila-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int	i;
	int	len;

	i = 0;
	if (!s1)
		return (0);
	len = ft_strlen(s1);
	while (s1[i] && ft_strchr (set, s1[i]))
		i++;
	while (ft_strrchr (set, s1[len]) && len)
		len --;
	return (ft_substr (s1, i, (len - i) + 1));
}	
