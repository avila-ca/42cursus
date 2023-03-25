/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avila-ca <avila-ca@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:14:38 by avila-ca          #+#    #+#             */
/*   Updated: 2023/03/22 10:17:33 by avila-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	atoi_push(const char *str)
{
	int		i;
	long	num;
	int		sign;

	sign = 1;
	i = 0;
	num = 0;
	while ((str[i] == 32) || ((9 <= str[i]) && (str[i] <= 13)))
		i++;
	if (str[i] == '+' && ('0' <= str[i + 1] && str[i + 1] <= '9'))
		i++;
	else if (str[i] == '-' && ('0' <= str[i + 1] && str[i + 1] <= '9'))
	{
		sign *= -1;
		i++;
	}
	return (atoi_conversion(str, i, num, sign));
}

int	atoi_conversion(const char *str, int i, long num, int sign)
{
	while ((48 <= str[i]) && (str[i] <= 57))
	{
		num = (str[i] - 48) + (num * 10);
		if (num > 2147483647 && sign == 1)
		{
			write(2, "Error\n", 6);
			exit (EXIT_FAILURE);
		}
		if (num > 2147483648 && sign == -1)
		{
			write(2, "Error\n", 6);
			exit (EXIT_FAILURE);
		}
		i++;
	}
	return (num * sign);
}

int	node_count(t_lst **stack)
{
	int		i;
	t_lst	*iter;

	i = 1;
	iter = *stack;
	while ((*iter).next != NULL)
	{
		iter = (*iter).next;
		i++;
	}
	return (i);
}
