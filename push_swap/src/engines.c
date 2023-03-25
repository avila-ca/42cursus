/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engines.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avila-ca <avila-ca@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:53:13 by avila-ca          #+#    #+#             */
/*   Updated: 2023/03/22 09:58:16 by avila-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	two_nums(t_lst **stack_a)
{
	if ((*stack_a)->num < (*stack_a)->next->num)
		return ;
	else
		swap(stack_a);
}

void	three_nums(t_lst **stack_a)
{
	if ((*stack_a)->num < (*stack_a)->next->num
		&& (*stack_a)->next->num < (*stack_a)->next->next->num)
		return ;
	else if ((*stack_a)->next->num > (*stack_a)->next->next->num
		&& (*stack_a)->next->num > (*stack_a)->num
		&& (*stack_a)->num < (*stack_a)->next->next->num)
	{
		swap(stack_a);
		ra(stack_a);
	}
	else if ((*stack_a)->next->num > (*stack_a)->next->next->num
		&& (*stack_a)->next->num > (*stack_a)->num
		&& (*stack_a)->num > (*stack_a)->next->next->num)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if ((*stack_a)->num > (*stack_a)->next->num
		&& (*stack_a)->num > (*stack_a)->next->next->num)
	{
		ra(stack_a);
		two_nums(stack_a);
	}
	else if ((*stack_a)->num > (*stack_a)->next->num)
		two_nums(stack_a);
}

void	sorting(t_lst **stack_a, t_lst **stack_b)
{
	int	min_ind;

	while ((*stack_b) != NULL )
	{
		init_values(stack_a, stack_b);
		cheapest(stack_a, stack_b);
		push(stack_a, stack_b, 'a');
	}
	init_values(stack_a, stack_b);
	if (!is_sorted(stack_a))
	{
		if (min_index(stack_a)->position > ((*stack_a)->total_node_a + 1) / 2)
		{
			min_ind = min_index(stack_a)->position
				- ((*stack_a)->total_node_a + 1);
			while (min_ind++)
				rra(stack_a);
		}
		else
		{
			min_ind = min_index(stack_a)->position;
			while (min_ind--)
				ra(stack_a);
		}
	}
}

void	over_three(t_lst **stack_a, t_lst **stack_b)
{
	t_lst	*tempa;
	t_lst	*tempb;
	int		i;

	i = 3;
	tempa = *stack_a;
	tempb = *stack_b;
	if (!is_sorted(stack_a))
	{	
		while ((*tempa).next->next->next != NULL)
		{
			push(&tempa, &tempb, 'b');
			(*tempb).total_node_b = ++i;
		}
		*stack_b = tempb;
		*stack_a = tempa;
		three_nums(stack_a);
		sorting(stack_a, stack_b);
	}
}

void	init_values(t_lst **stack_a, t_lst **stack_b)
{
	find_position(stack_a, stack_b);
	calcule_costs(stack_b);
}
