/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avila-ca <avila-ca@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 09:07:45 by avila-ca          #+#    #+#             */
/*   Updated: 2023/01/07 09:27:34 by avila-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_lst **stack_a)
{
	t_lst	*aux;
	t_lst	*aux2;

	aux = *stack_a;
	aux2 = *stack_a;
	while ((*aux).next != NULL)
	{
		aux = (*aux).next;
		if ((*aux2).index < (*aux).index)
			aux2 = (*aux2).next;
		else
			return (0);
	}
	return (1);
}
		

