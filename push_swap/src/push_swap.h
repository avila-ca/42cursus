/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avila-ca <avila-ca@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:40:55 by avila-ca          #+#    #+#             */
/*   Updated: 2023/01/07 12:01:10 by avila-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include <fcntl.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
#include <limits.h>

typedef struct s_lst
{
	int		num;
	int		index;
	int		position;
	int		tposition;
	int		cost_a;
	int		cost_b;
	int		total_node;
	struct s_lst	*next;
}	t_lst;

int		atoi_push(const char *str);
t_lst	*lstnew(int num);
t_lst	*lst_last(t_lst *lst);
void	lst_add_back(t_lst *lst, t_lst *new);
int		check_no_num(int argc, char **argv);
void	indexer(t_lst *stack_a);
void	lst_add_front(t_lst *lst, t_lst *new);
void	swap(t_lst **stack_a, t_lst **stack_b, char move);
void	rotate(t_lst **stack_a, t_lst **stack_b, char move);
void	reverse_rotate(t_lst **stack_a, t_lst **stack_b, char move);
void	push(t_lst **stack_a, t_lst **stack_b, char move);
int		node_count(t_lst **stack);
void	two_nums(t_lst **stack_a);
void	three_nums(t_lst **stack_a);
void	over_three(t_lst **stack_a, t_lst **stack_b);
void	find_position(t_lst **stack_a, t_lst **stack_b);
t_lst	*max_index(t_lst **stack);
t_lst	*min_index(t_lst **stack);
void	calcule_costs(t_lst **stack_a, t_lst **stack_b);
int		check_end(t_lst **stack_a);
void	sorting(t_lst **stack_a, t_lst **stack_b);
int		is_sorted(t_lst **stack_a);
void	init_values(t_lst **stack_a, t_lst **stack_b);
void	init_values(t_lst **stack_a, t_lst **stack_b);
void	printer(t_lst **stack_a, t_lst **stack_b);
void	locate_tpos(t_lst **stack_a, t_lst **stack_b);

#endif
