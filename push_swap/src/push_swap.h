/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avila-ca <avila-ca@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:40:55 by avila-ca          #+#    #+#             */
/*   Updated: 2023/03/22 10:35:01 by avila-ca         ###   ########.fr       */
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
# include <limits.h>

typedef struct s_lst
{
	int				num;
	int				index;
	int				position;
	int				tposition;
	int				cost_a;
	int				cost_b;
	int				total_cost;
	int				total_node_b;
	int				total_node_a;
	struct s_lst	*next;
}	t_lst;

int		atoi_push(const char *str);
int		atoi_conversion(const char *str, int i, long num, int sign);
int		check_all(int argc, char **argv);
void	fill_stack(t_lst *stack_a, char **argv, int i);
t_lst	*lstnew(int num);
t_lst	*lst_last(t_lst *lst);
void	lst_add_back(t_lst *lst, t_lst *new);
int		check_no_num(int argc, char **argv);
void	indexer(t_lst *stack_a,	t_lst *aux, t_lst *iter, t_lst *tmp);
void	lst_add_front(t_lst *lst, t_lst *new);
void	swap(t_lst **stack_a);
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
void	calcule_costs(t_lst **stack_b);
int		check_end(t_lst **stack_a);
void	sorting(t_lst **stack_a, t_lst **stack_b);
int		is_sorted(t_lst **stack_a);
void	init_values(t_lst **stack_a, t_lst **stack_b);
void	printer(t_lst **stack_a, t_lst **stack_b);
void	locate_tpos(t_lst **stack_a, t_lst **stack_b, int a, int b);
void	ra(t_lst **stack_a);
void	rb(t_lst **stack_b);
void	rra(t_lst **stack_a);
void	rrb(t_lst **stack_b);
void	rr(t_lst **stack_a, t_lst **stack_b);
void	rrr(t_lst **stack_a, t_lst **stack_b);
void	cheapest(t_lst **stack_a, t_lst **stack_b);
void	make_dob_move(t_lst **stack_a, t_lst **stack_b, int costa, int costb);
void	make_singl_move(t_lst **stack_a, t_lst **stack_b, int costa, int costb);
void	leaks_free(t_lst *stack);
void	select_alg(t_lst **stack_a, t_lst **stack_b, int i);
void	init_alg(t_lst **stack_a, t_lst **stack_b, int i);

#endif
