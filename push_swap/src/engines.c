/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engines.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avila-ca <avila-ca@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:53:13 by avila-ca          #+#    #+#             */
/*   Updated: 2023/01/07 12:08:31 by avila-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	two_nums(t_lst **stack_a)
{
	if ((*stack_a)->num < (*stack_a)->next->num)
		return ;
	else
		swap(stack_a, NULL, 'a');
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
		swap(stack_a, NULL, 'a');
		rotate(stack_a, NULL, 'a');
	}
	else if ((*stack_a)->next->num > (*stack_a)->next->next->num
			&& (*stack_a)->next->num > (*stack_a)->num
			&& (*stack_a)->num > (*stack_a)->next->next->num) 
	{
		rotate(stack_a, NULL, 'a');
		rotate(stack_a, NULL, 'a');
	}
	else if ((*stack_a)->num > (*stack_a)->next->num
			&& (*stack_a)->num > (*stack_a)->next->next->num)
	{
		rotate(stack_a, NULL, 'a');
		two_nums(stack_a);
	}
	else if ((*stack_a)->num > (*stack_a)->next->num)
		two_nums(stack_a);
}

void	sorting(t_lst **stack_a, t_lst **stack_b)
{
	t_lst	*tempa;
	t_lst	*tempb;

	tempa = *stack_a;
	tempb = *stack_b;
	while (tempb)
	{
		init_values(stack_a, stack_b);
		printer(stack_a, stack_b);
		if ((*tempb).cost_b == 0 || (*tempb).cost_b == 1)
		{
			if ((*tempb).tposition == 0 && (*tempb).position == 0 && (*tempb).cost_a == 0)
			{
				push(stack_a, stack_b, 'a');
				tempa = *stack_a;
				if (tempb)
					tempb = *stack_b;
			}
			else if ((*tempb).cost_a >= 0 && (*tempb).position == 0)
			{
				while ((*tempb).cost_a--)
					rotate(stack_a, NULL, 'a');
				push(stack_a, stack_b, 'a');
				tempa = *stack_a;
				if (tempb != NULL)
					tempb = *stack_b;
			}
			else if ((*tempb).cost_a < 0 && (*tempb).position == 0)
			{
				while ((*tempb).cost_a++ != 0)
					reverse_rotate(stack_a, NULL, 'a');
				push(stack_a, stack_b, 'a');
				tempa = *stack_a;
				if (tempb)
					tempb = *stack_b;
			}
		}
	}	
//	while (!is_sorted(stack_a))
//		reverse_rotate(stack_a, NULL, 'a');
}

void	printer(t_lst **stack_a, t_lst **stack_b)
{
	printf("	Stack A	\n");
		while((*stack_a) != NULL)
		{
			printf("	%d [%d] (%d)\n", (*stack_a)->num, (*stack_a)->index, (*stack_a)->position);
			stack_a = &(*stack_a)->next;
		}
		while ((*stack_b) != NULL)
		{
			printf("				stack B\n 				%d (%d) [%d] <<%d<< costb = %d costa =%d\n", (*stack_b)->num, (*stack_b)->position, (*stack_b)->index, (*stack_b)->tposition, (*stack_b)->cost_b, (*stack_b)->cost_a);
		
			stack_b = &(*stack_b)->next;
		}
}
void	over_three(t_lst **stack_a, t_lst **stack_b)
{
	t_lst	*tempa;
	t_lst	*tempb;
	int 	i;
	
	i = 3;
	tempa = *stack_a;
	tempb = *stack_b;
	while ((*tempa).next->next->next != NULL)
	{
		push(&tempa, &tempb, 'b');
		(*tempb).total_node = ++i;
	}
	*stack_b = tempb;
	*stack_a = tempa;
	three_nums(stack_a);
	//printer(stack_a, stack_b);
	sorting(stack_a, stack_b);	
	//printer(stack_a, stack_b);
}

void	init_values(t_lst **stack_a, t_lst **stack_b)
{
	t_lst	*tempa;
	t_lst	*tempb;
	
	find_position(stack_a, stack_b);
	tempa = *stack_a;
	tempb = *stack_b;
	locate_tpos(stack_a, stack_b);
	calcule_costs(stack_a, stack_b);
}
