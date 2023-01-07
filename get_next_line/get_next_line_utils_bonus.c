/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avila-ca <avila-ca@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 18:36:49 by avila-ca          #+#    #+#             */
/*   Updated: 2022/04/19 13:44:46 by avila-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	{
		return (1);
	}
	return (0);
}

char	*storing(char *s, char *store, int i)
{
	int	j;

	j = 0;
	while (store[++i])
	{
		s[j] = store[i];
		j++;
	}
	s[j] = '\0';
	return (s);
}
