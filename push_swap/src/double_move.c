/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avila-ca <avila-ca@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 10:07:31 by avila-ca          #+#    #+#             */
/*   Updated: 2023/03/22 09:52:11 by avila-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_lst **stack_a, t_lst **stack_b)
{
	rotate(stack_a, NULL, 'a');
	rotate(NULL, stack_b, 'b');
	ft_putstr_fd("rr\n", 1);
}

void	rrr(t_lst **stack_a, t_lst **stack_b)
{
	reverse_rotate(stack_a, NULL, 'a');
	reverse_rotate(NULL, stack_b, 'b');
	ft_putstr_fd("rrr\n", 1);
}

void	make_dob_move(t_lst **stack_a, t_lst **stack_b, int costa, int costb)
{
	while (costa > 0 && costb > 0)
	{
		costa--;
		costb--;
		rr(stack_a, stack_b);
	}
	while (costa < 0 && costb < 0)
	{
		costa++;
		costb++;
		rrr(stack_a, stack_b);
	}
	make_singl_move(stack_a, stack_b, costa, costb);
}

void	make_singl_move(t_lst **stack_a, t_lst **stack_b, int costa, int costb)
{
	if (costb > 0)
	{
		while (costb--)
			rb(stack_b);
	}
	else if (costb < 0)
	{
		while (costb++)
			rrb(stack_b);
	}
	if (costa > 0)
	{
		while (costa--)
			ra(stack_a);
	}
	else if (costa < 0)
	{
		while (costa++)
			rra(stack_a);
	}
}
