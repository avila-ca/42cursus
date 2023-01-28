/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engines.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avila-ca <avila-ca@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:53:13 by avila-ca          #+#    #+#             */
/*   Updated: 2023/01/28 13:05:52 by avila-ca         ###   ########.fr       */
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
		rotate(stack_a, NULL, 'a', 0);
	}
	else if ((*stack_a)->next->num > (*stack_a)->next->next->num
			&& (*stack_a)->next->num > (*stack_a)->num
			&& (*stack_a)->num > (*stack_a)->next->next->num) 
	{
		rotate(stack_a, NULL, 'a', 0);
		rotate(stack_a, NULL, 'a', 0);
	}
	else if ((*stack_a)->num > (*stack_a)->next->num
			&& (*stack_a)->num > (*stack_a)->next->next->num)
	{
		rotate(stack_a, NULL, 'a', 0);
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
	while ((*stack_b) != NULL)
	{
		init_values(stack_a, stack_b);
		printer(stack_a, stack_b);	
		if ((*tempb).total_node_a > 20)
		{
			write(1,"dentro",6); 
			sort_mid(stack_a, stack_b);
		}
		else
			sort_first(stack_a, stack_b);
		if((*tempb).next)
			tempb = (*tempb).next;
	}
	tempa = *stack_a;
	tempb = *stack_b;
	if (!is_sorted(stack_a))
	{
		if ((*stack_a)->total_node_a / 2 < min_index(stack_a)->position)
		{	
			while (!is_sorted(stack_a))
				reverse_rotate(stack_a, NULL, 'a', 0);
		}
		else
		{
			while (!is_sorted(stack_a))
				rotate(stack_a, NULL, 'a', 0);
		}
	}
}

void	printer(t_lst **stack_a, t_lst **stack_b)
{
	printf("	Stack A	 = %d\n", (*stack_a)->total_node_a);
		while((*stack_a) != NULL)
		{
			printf("	 [%d] (%d)\n", (*stack_a)->index, (*stack_a)->position);
			stack_a = &(*stack_a)->next;
		}
	printf("				Stack B = %d\n",(*stack_b)->total_node_b);
		while ((*stack_b) != NULL)
		{
			printf("				[%d] <<%d<< costb = %d costa =%d TOTAL = %d\n", (*stack_b)->index, (*stack_b)->tposition, (*stack_b)->cost_b, (*stack_b)->cost_a, (*stack_b)->total_cost);
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
		//printer(stack_a, stack_b);
		sorting(stack_a, stack_b);	
	//	printer(stack_a, stack_b);
	}
}

void	init_values(t_lst **stack_a, t_lst **stack_b)
{
//	t_lst	*tempa;
//	t_lst	*tempb;
	
	find_position(stack_a, stack_b);
//	tempa = *stack_a;
//	tempb = *stack_b;
//	locate_tpos(stack_a, stack_b);
	calcule_costs(stack_a, stack_b);
}
