/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avila-ca <avila-ca@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 09:07:45 by avila-ca          #+#    #+#             */
/*   Updated: 2023/01/28 11:17:02 by avila-ca         ###   ########.fr       */
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
		
void	sort_mid(t_lst **stack_a, t_lst **stack_b)
{
	t_lst	*tempa;
	t_lst	*tempb;

	tempa = *stack_a;
	tempb = *stack_b;
	if((*tempb).cost_a > 6 && (*tempb).cost_b > 6)
	{
		while ((*tempb).cost_a-- && (*tempb).cost_b--)
		{
			rotate(stack_a, NULL, 'a', 2);
			rotate(NULL, stack_b, 'b', 2);
			tempa = *stack_a;
			tempb = *stack_b;
		}
	}
	else if ((*tempb).cost_a < -5 && (*tempb).cost_b < -5)
	{
		while ((*tempb).cost_a++ && (*tempb).cost_b++)
		{
			reverse_rotate(stack_a, NULL, 'a', 2);
			reverse_rotate(NULL, stack_b, 'b', 2);
			tempa = *stack_a;
			tempb = *stack_b;
		}
	}
	else if ((*tempb).cost_a > 0 && (*tempb).cost_b < 0)
	{
		if(((*tempb).total_node_a / 2 - (*tempb).cost_a < 4) && ((*tempb).total_node_b / 2 - (-1 * (*tempb).cost_b) < 4))
		{
			(*tempb).cost_b = -1 * (*tempb).cost_b;
			while ((*tempb).cost_a-- && (*tempb).cost_b--)
			{
				rotate(stack_a, NULL, 'a', 2);
				rotate(NULL, stack_b, 'b', 2);
				tempa = *stack_a;
				tempb = *stack_b;
			}
		}
	}
	else if ((*tempb).cost_a < 0 && (*tempb).cost_b > 0)
	{
		if(((*tempb).total_node_a / 2 - (-1 * (*tempb).cost_a) < 4) && ((*tempb).total_node_b / 2 - (*tempb).cost_b < 4))
		{
			(*tempb).cost_a = -1 * (*tempb).cost_a;
			while ((*tempb).cost_a-- && (*tempb).cost_b--)
			{
				rotate(stack_a, NULL, 'a', 2);
				rotate(NULL, stack_b, 'b', 2);
				tempa = *stack_a;
				tempb = *stack_b;
			}
		}
	}
}

void	sort_first(t_lst **stack_a, t_lst **stack_b)
{
	t_lst	*tempa;
	t_lst	*tempb;

	tempa = *stack_a;
	if((*stack_b) != NULL)
	{
	tempb = *stack_b;
	if ((*tempb).total_cost == 0)
	{
		push(stack_a, stack_b, 'a');
		tempa = *stack_a;
		if (tempb != NULL)
			tempb = *stack_b;
	}
	else if ((*tempb).cost_a > 0 && (*tempb).cost_b == 0)
	{
		while ((*tempb).cost_a--)
			rotate(stack_a, NULL, 'a', 0);
		push(stack_a, stack_b, 'a');
		tempa = *stack_a;
		if (tempb != NULL)
			tempb = *stack_b;
	}
	else if ((*tempb).cost_a < 0 && (*tempb).cost_b == 0)
	{
		while ((*tempb).cost_a++)
			reverse_rotate(stack_a, NULL, 'a', 0);
		push(stack_a, stack_b, 'a');
		tempa = *stack_a;
		if (tempb != NULL)
			tempb = *stack_b;
	}
	else if ((*tempb).cost_b > 0 && (*tempb).cost_a == 0)
	{
		while ((*tempb).cost_b--)
			rotate(NULL, stack_b, 'a', 0);
		push(stack_a, stack_b, 'a');
		tempa = *stack_a;
		if (tempb != NULL)
			tempb = *stack_b;
	}
	else if ((*tempb).cost_b < 0 && (*tempb).cost_a == 0)
	{
		while ((*tempb).cost_b++)
			reverse_rotate(NULL, stack_b, 'a', 0);
		push(stack_a, stack_b, 'a');
		tempa = *stack_a;
		if (tempb != NULL)
			tempb = *stack_b;
	}
}
}

