/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avila-ca <avila-ca@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 09:37:34 by avila-ca          #+#    #+#             */
/*   Updated: 2023/03/01 09:01:46 by avila-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_lst **stack_a)
{
	rotate(stack_a, NULL, 'a');
	ft_putstr_fd("ra\n", 1);
}

void	rb(t_lst **stack_b)
{
	rotate(NULL, stack_b, 'b');
	ft_putstr_fd("rb\n", 1);
}

void	rra(t_lst **stack_a)
{
	reverse_rotate(stack_a, NULL, 'a');
	ft_putstr_fd("rra\n", 1);
}

void	rrb(t_lst **stack_b)
{
	reverse_rotate(NULL, stack_b, 'b');
	ft_putstr_fd("rrb\n", 1);
}
