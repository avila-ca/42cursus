/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avila-ca <avila-ca@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:28:51 by avila-ca          #+#    #+#             */
/*   Updated: 2023/03/22 09:50:57 by avila-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calculate_costs2(t_lst *tempb)
{
	if ((*tempb).position <= (*tempb).total_node_b / 2)
			(*tempb).cost_b = (*tempb).position;
	else
		(*tempb).cost_b = (*tempb).position - (*tempb).total_node_b;
	if ((*tempb).tposition > (*tempb).total_node_a / 2)
	{
		(*tempb).cost_a = (*tempb).tposition - (*tempb).total_node_a;
		if ((*tempb).cost_b >= 0)
			(*tempb).total_cost = (-1 * (*tempb).cost_a) + (*tempb).cost_b;
		else
			(*tempb).total_cost = -1 * ((*tempb).cost_a + (*tempb).cost_b);
	}
	else
	{
		(*tempb).cost_a = (*tempb).tposition;
		if ((*tempb).cost_b >= 0)
			(*tempb).total_cost = (*tempb).cost_a + (*tempb).cost_b;
		else
			(*tempb).total_cost = (*tempb).cost_a + (-1 * (*tempb).cost_b);
	}
}

void	calcule_costs(t_lst **stack_b)
{
	t_lst	*tempb;

	tempb = *stack_b;
	while (tempb)
	{
		calculate_costs2(tempb);
		tempb = (*tempb).next;
	}
	tempb = *stack_b;
}				

void	cheapest(t_lst **stack_a, t_lst **stack_b)
{
	t_lst	*tempb;
	int		costa;
	int		costb;
	int		total;

	costa = 0;
	costb = 0;
	total = INT_MAX;
	tempb = *stack_b;
	while (tempb)
	{
		if ((*tempb).total_cost < total)
		{
			total = (*tempb).total_cost;
			costa = (*tempb).cost_a;
			costb = (*tempb).cost_b;
		}
		tempb = (*tempb).next;
	}
	make_dob_move(stack_a, stack_b, costa, costb);
}
