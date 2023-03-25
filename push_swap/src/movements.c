/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avila-ca <avila-ca@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 12:17:54 by avila-ca          #+#    #+#             */
/*   Updated: 2023/03/22 10:14:45 by avila-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_lst **stack_a)
{
	t_lst	*aux3;
	t_lst	*aux2;
	t_lst	*aux1;
	t_lst	*stack;

		stack = *stack_a;
	aux3 = stack;
	aux2 = stack;
	aux1 = stack;
	aux3 = (*aux3).next->next;
	stack = (*aux2).next;
	(*stack).next = aux1;
	(*stack).next->next = aux3;
	*stack_a = stack;
	ft_putstr_fd("sa\n", 1);
}

void	rotate(t_lst **stack_a, t_lst **stack_b, char move)
{
	t_lst	*first;
	t_lst	*stack;

	if (move == 'a')
		stack = *stack_a;
	else
		stack = *stack_b;
	first = stack;
	stack = (*stack).next;
	(*first).next = NULL;
	lst_add_back(stack, first);
	if (move == 'a')
		*stack_a = stack;
	else if (move == 'b')
		*stack_b = stack;
}

void	reverse_rotate(t_lst **stack_a, t_lst **stack_b, char move)
{
	t_lst	*iter;
	t_lst	*last;
	t_lst	*stack;

	if (move == 'a')
		stack = *stack_a;
	else
		stack = *stack_b;
	iter = stack;
	while ((*iter).next->next != NULL)
		iter = (*iter).next;
	last = (*iter).next;
	(*last).next = stack;
	stack = last;
	(*iter).next = NULL;
	if (move == 'a')
		*stack_a = stack;
	else if (move == 'b')
		*stack_b = stack;
}

void	push(t_lst **stack_a, t_lst **stack_b, char move)
{
	t_lst	*temp;

	if (move == 'a')
	{
		temp = *stack_b;
		*stack_b = (*stack_b)->next;
		(*temp).next = *stack_a;
		*stack_a = temp;
		ft_putstr_fd("pa\n", 1);
	}
	else
	{
		temp = *stack_a;
		*stack_a = (*stack_a)->next;
		(*temp).next = *stack_b;
		*stack_b = temp;
		ft_putstr_fd("pb\n", 1);
	}
}
