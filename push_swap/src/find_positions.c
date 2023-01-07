/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_positions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avila-ca <avila-ca@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:37:58 by avila-ca          #+#    #+#             */
/*   Updated: 2023/01/07 12:05:21 by avila-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	locate_tpos(t_lst **stack_a, t_lst **stack_b)
{
	t_lst	*tempa;
	t_lst	*tempb;
	
	tempa = *stack_a;
	tempb = *stack_b;
	while (tempb)
	{
		while ((*tempa).next != NULL)
		{
			if ((*tempb).index > (*tempa).index
				&& (*tempb).index < (*tempa).next->index)
				(*tempb).tposition = (*tempa).next->position;
			else if ((*tempb).index > max_index(stack_a)->index)
				(*tempb).tposition = max_index(stack_a)->position + 1;
			else if ((*tempb).index < min_index(stack_a)->index)
				(*tempb).tposition = min_index(stack_a)->position;
			tempa = (*tempa).next;
		}
		if ((*tempb).tposition == -1)
			(*tempb).tposition = 0;
		tempa = *stack_a;
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
		if ((*temp).index < (*temp).next->index && (*temp).index < (*min_node).index)
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
		if ((*temp).index > (*temp).next->index && (*temp).index > (*max_node).index)
			max_node = temp;
		else if ((*temp).next->index > (*max_node).index)
			max_node = (*temp).next;
		temp = (*temp).next;
		
	}
	return (max_node);
}

void	indexer(t_lst *stack_a)
{
	t_lst	*aux;
	t_lst	*iter;
	t_lst	*tmp;
	int		i;

	aux = stack_a;
	iter = stack_a;
	tmp = stack_a;
	i = 1;
	while (aux)
	{
		while (iter)
		{
			if ((*iter).index == 0)
			{
				if ((*aux).num <= (*iter).num)
				{
					if ((*tmp).num >= (*aux).num && (*aux).index == 0)
						tmp = aux;
					else if ((*tmp).index != 0)
						tmp = iter;
					else if ((*tmp).index == 0 && (*tmp).num > (*iter).num)
						tmp = iter;
				}
				else if ((*aux).num >= (*iter).num)
				{
					if ((*tmp).num >= (*iter).num)
						tmp = iter;
					else if ((*tmp).index != 0)
						tmp = iter;
				}
			}
				iter = (*iter).next;
		}
		(*tmp).index = i;
		i++;
		iter = stack_a;
		aux = (*aux).next;
	}
}

void	find_position(t_lst **stack_a, t_lst **stack_b)
{
	t_lst	*tempa;
	t_lst	*tempb;
	int i;

	i = 0;
	tempa = *stack_a;
	tempb = *stack_b;
	while (tempa)
	{
		(*tempa).position = i;
		tempa = (*tempa).next;
		i++;
	}
	i = 0;
	while (tempb)
	{
		(*tempb).position = i;
		tempb = (*tempb).next;
		i++;
	}
}
