///* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avila-ca <avila-ca@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 12:36:41 by avila-ca          #+#    #+#             */
/*   Updated: 2022/12/12 11:35:51 by avila-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_lst **stack_a, t_lst **stack_b, char move)
{
	t_lst	*aux3;
	t_lst	*aux2;
	t_lst	*aux1;
	t_lst	*stack;

	if (move == 'a')
		stack = *stack_a;
	else
		stack = *stack_b;
	aux3 = stack;
	aux2 = stack;
	aux1 = stack;
	aux3 = (*aux3).next->next;
	stack = (*aux2).next;
	(*stack).next = aux1;
	(*stack).next->next = aux3;
	if (move == 'a')
	{
		*stack_a = stack;
		ft_putstr_fd("sa\n", 1);
	}
	else
	{
		*stack_b = stack;
		ft_putstr_fd("sb\n", 1);
	}
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
	{
		*stack_a = stack;
		ft_putstr_fd("ra\n", 1);
	}
	else
	{
		*stack_b = stack;
		ft_putstr_fd("rb\n", 1);
	}
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
	{
		*stack_a = stack;
		ft_putstr_fd("rra\n", 1);
	}
	else
	{
		*stack_b = stack;
		ft_putstr_fd("rrb\n", 1);
	}
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
