/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avila-ca <avila-ca@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 10:23:31 by avila-ca          #+#    #+#             */
/*   Updated: 2023/03/22 10:36:05 by avila-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		i;
	t_lst	*stack_a;
	t_lst	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	i = 0;
	if (!check_all(argc, argv))
		return (0);
	while (argv[++i])
	{
		if (!stack_a)
			stack_a = lstnew(atoi_push(argv[i]));
		else
		{
			lst_add_back(stack_a, lstnew(atoi_push(argv[i])));
		}
	}
	indexer(stack_a, stack_a, stack_a, stack_a);
	select_alg(&stack_a, &stack_b, i);
	leaks_free(stack_b);
	leaks_free(stack_a);
	return (0);
}

void	select_alg(t_lst **stack_a, t_lst **stack_b, int i)
{
	i = node_count(stack_a);
	if (i == 2)
		two_nums(stack_a);
	else if (i == 3)
		three_nums(stack_a);
	else
		over_three(stack_a, stack_b);
}

int	check_all(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	else if (check_no_num(argc, argv))
		return (0);
	else
		return (1);
}

void	leaks_free(t_lst *stack)
{
	t_lst	*temp;

	while (stack)
	{
		temp = (*stack).next;
		free(stack);
		stack = temp;
	}
	stack = NULL;
}
