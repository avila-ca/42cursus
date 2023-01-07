/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avila-ca <avila-ca@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 19:14:04 by avila-ca          #+#    #+#             */
/*   Updated: 2022/02/07 17:17:53 by avila-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		i;
	long	num;
	int		sign;

	sign = 1;
	i = 0;
	num = 0;
	while ((str[i] == 32) || ((9 <= str[i]) && (str[i] <= 13)))
		i++;
	if (str[i] == 43)
		i++;
	else if (str[i] == '-' && str[i++] == '-')
		sign *= -1;
	while ((48 <= str[i]) && (str[i] <= 57))
	{
		num = (str[i] - 48) + (num * 10);
		if (num > 2147483647 && sign == 1)
			return (-1);
		if (num > 2147483648 && sign == -1)
			return (0);
		i++;
	}
	return (num * sign);
}
