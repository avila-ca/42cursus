/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avila-ca <avila-ca@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:28:51 by avila-ca          #+#    #+#             */
/*   Updated: 2023/01/04 11:21:03 by avila-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calcule_costs(t_lst **stack_a, t_lst **stack_b)
{
	t_lst	*tempa;
	t_lst	*tempb;
	int 	cost;

	cost = 0;
	tempa = *stack_a;
	tempb = *stack_b;
	while (tempb)
	{
		if (node_count(stack_b) > 4)
		{
			if ((*tempb).position <= node_count(stack_b) / 2)
			{
				(*tempb).cost_b = (*tempb).position;
				if ((*tempb).tposition > node_count(stack_a) / 2)
					(*tempb).cost_a =  (*tempb).tposition - node_count(stack_a);
				else
					(*tempb).cost_a = (*tempb).tposition;
			}
			else if ((*tempb).position > node_count(stack_b) / 2)
			{
				(*tempb).cost_b = (*tempb).position - node_count(stack_b);
				if ((*tempb).tposition > node_count(stack_a) / 2)
					(*tempb).cost_a = (*tempb).tposition - node_count(stack_a);
				else
					(*tempb).cost_a = (*tempb).tposition;

			}
		}
		else
		{
			if ((*tempb).position < 2)
			{
				(*tempb).cost_b = (*tempb).position;
				if ((*tempb).tposition > node_count(stack_a) / 2)
					(*tempb).cost_a =  (*tempb).tposition - node_count(stack_a);
				else
					(*tempb).cost_a = (*tempb).tposition;
			}
			else if ((*tempb).position >= 2)
			{
				(*tempb).cost_b = (*tempb).position - node_count(stack_b);
				if ((*tempb).tposition > node_count(stack_a) / 2)
					(*tempb).cost_a = (*tempb).tposition - node_count(stack_a);
				else
					(*tempb).cost_a = (*tempb).tposition;
			}

		}
		tempb = (*tempb).next;
	}
	tempb = *stack_b;
}				

