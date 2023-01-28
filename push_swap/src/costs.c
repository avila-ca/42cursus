/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avila-ca <avila-ca@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:28:51 by avila-ca          #+#    #+#             */
/*   Updated: 2023/01/28 11:24:19 by avila-ca         ###   ########.fr       */
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
		if ((*tempb).position <= (*tempb).total_node_b / 2)
			(*tempb).cost_b = (*tempb).position;
		else
			(*tempb).cost_b = (*tempb).position - (*tempb).total_node_b;
		if ((*tempb).tposition > (*tempa).total_node_a / 2)
		{
			(*tempb).cost_a =  (*tempb).tposition - (*tempa).total_node_a;
			(*tempb).total_cost = (-1 * (*tempb).cost_a) + (*tempb).cost_b;
		}
		else
		{
			(*tempb).cost_a = (*tempb).tposition;
			(*tempb).total_cost = (*tempb).cost_a + (*tempb).cost_b;
		}
		tempb = (*tempb).next;
	}
	tempb = *stack_b;
}				

