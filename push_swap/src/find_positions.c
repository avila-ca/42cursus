/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_positions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avila-ca <avila-ca@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:37:58 by avila-ca          #+#    #+#             */
/*   Updated: 2023/03/22 10:13:26 by avila-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	locate_tpos2(t_lst *tempa, t_lst *tempb, t_lst *min_ind, t_lst *max_ind)
{
	int	min;

	min = INT_MAX;
	while (tempa != NULL)
	{
		if ((*tempb).index < (*min_ind).index)
			(*tempb).tposition = (*min_ind).position;
		else if ((*tempb).index > (*max_ind).index)
			(*tempb).tposition = (*min_ind).position;
		else if (((*tempa).index > (*tempb).index)
			&& ((*tempa).index < min))
		{
			min = (*tempa).index;
			(*tempb).tposition = (*tempa).position;
		}
		tempa = (*tempa).next;
	}
}

void	locate_tpos(t_lst **stack_a, t_lst **stack_b, int a, int b)
{
	t_lst	*tempa;
	t_lst	*tempb;
	t_lst	*min_ind;
	t_lst	*max_ind;

	min_ind = min_index(stack_a);
	max_ind = max_index(stack_a);
	tempa = *stack_a;
	tempb = *stack_b;
	while (tempb)
	{
		locate_tpos2(tempa, tempb, min_ind, max_ind);
		tempa = *stack_a;
		(*tempb).total_node_b = b;
		(*tempb).total_node_a = a;
		tempb = (*tempb).next;
	}
}

t_lst	*min_index(t_lst **stack)
{
	t_lst	*temp;
	t_lst	*min_node;

	temp = *stack;
	min_node = *stack;
	while ((*temp).next != NULL)
	{
		if ((*temp).index < (*temp).next->index
			&& (*temp).index < (*min_node).index)
			min_node = temp;
		else if ((*temp).next->index < (*min_node).index)
			min_node = (*temp).next;
		temp = (*temp).next;
	}
	return (min_node);
}

t_lst	*max_index(t_lst **stack)
{
	t_lst	*temp;
	t_lst	*max_node;

	temp = *stack;
	max_node = *stack;
	while ((*temp).next != NULL)
	{
		if ((*temp).index > (*temp).next->index
			&& (*temp).index > (*max_node).index)
			max_node = temp;
		else if ((*temp).next->index > (*max_node).index)
			max_node = (*temp).next;
		temp = (*temp).next;
	}
	return (max_node);
}

void	find_position(t_lst **stack_a, t_lst **stack_b)
{
	t_lst	*tempa;
	t_lst	*tempb;
	int		a;
	int		b;

	a = 0;
	b = 0;
	tempa = *stack_a;
	if (stack_b)
		tempb = *stack_b;
	while (tempa)
	{
		(*tempa).position = a;
		tempa = (*tempa).next;
		a++;
	}
	while (tempb)
	{
		(*tempb).position = b;
		tempb = (*tempb).next;
		b++;
	}
	locate_tpos(stack_a, stack_b, a, b);
}
