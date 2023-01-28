/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avila-ca <avila-ca@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 10:23:31 by avila-ca          #+#    #+#             */
/*   Updated: 2023/01/17 11:37:59 by avila-ca         ###   ########.fr       */
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
	if(argc < 2)
		return (0);
	if (check_no_num(argc, argv))
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
	indexer(stack_a);
	i = node_count(&stack_a);
	if (i == 2)
		two_nums(&stack_a);
	else if (i == 3)
		three_nums(&stack_a);
	else
		over_three(&stack_a, &stack_b);
	//	printer(&stack_a, &stack_b);
	return (0);
}
// python3 pyviz.py `ruby -e "puts (0..99).to_a.shuffle.join(' ')"`
// python3 pyviz.py `ruby -e "puts (-250..249).to_a.shuffle.join(' ')"`
