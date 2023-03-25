/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avila-ca <avila-ca@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 11:03:42 by avila-ca          #+#    #+#             */
/*   Updated: 2023/03/22 09:24:20 by avila-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	indexer(t_lst *stack_a, t_lst *aux, t_lst *iter, t_lst *tmp)
{
	int	i;

	i = 1;
	while (aux)
	{
		while (iter)
		{
			if ((*tmp).index != 0)
				tmp = iter;
			if ((*aux).num <= (*iter).num && (*iter).index == 0)
			{
				if ((*tmp).num >= (*aux).num && (*aux).index == 0)
					tmp = aux;
				else if ((*tmp).index == 0 && (*tmp).num > (*iter).num)
					tmp = iter;
			}				
			else if ((*aux).num >= (*iter).num && (*iter).index == 0)
				if ((*tmp).num >= (*iter).num)
					tmp = iter;
			iter = (*iter).next;
		}
		(*tmp).index = i++;
		iter = stack_a;
		aux = (*aux).next;
	}
}
