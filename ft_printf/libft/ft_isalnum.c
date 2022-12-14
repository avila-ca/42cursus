/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avila-ca <avila-ca@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 15:55:47 by avila-ca          #+#    #+#             */
/*   Updated: 2022/02/15 18:09:18 by avila-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	return (((('0' <= c)) && (c <= '9'))
		|| (('A' <= c) && (c <= 'Z'))
		|| (('a' <= c) && (c <= 'z')));
}
