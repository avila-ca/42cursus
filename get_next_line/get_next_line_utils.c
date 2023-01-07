/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avila-ca <avila-ca@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 18:57:21 by avila-ca          #+#    #+#             */
/*   Updated: 2022/04/19 13:45:32 by avila-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

int	check_n(char *store)
{
	int	i;

	i = 0;
	if (!store)
		return (0);
	while (store[i] && store[i] != '\n')
		i++;
	if (store[i] == '\n')
		return (1);
	return (0);
}
