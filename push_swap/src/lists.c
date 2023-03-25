/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avila-ca <avila-ca@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:41:34 by avila-ca          #+#    #+#             */
/*   Updated: 2023/03/22 10:14:17 by avila-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lst	*lstnew(int num)
{
	t_lst	*new;

	new = malloc (sizeof(t_lst));
	if (!new)
		return (NULL);
	new->num = num;
	new->index = 0;
	new->position = 0;
	new->tposition = -1;
	new->cost_a = 0;
	new->cost_b = 0;
	new->next = NULL;
	return (new);
}

t_lst	*lst_last(t_lst *lst)
{
	if (!lst)
		return (0);
	while ((*lst).next != NULL)
		lst = (*lst).next;
	return (lst);
}

void	lst_add_back(t_lst *lst, t_lst *new)
{
	t_lst	*temp;

	if (!lst)
		lst = new;
	else
	{
		temp = NULL;
		temp = lst_last(lst);
		temp->next = new;
		new->next = NULL;
	}
}

t_lst	*lst_first(t_lst *lst)
{
	t_lst	*first;

	first = lst;
	if (lst->next == NULL)
		return (lst);
	lst = lst->next;
	return (first);
}

void	lst_add_front(t_lst *head, t_lst *new)
{	
	if (head)
	{
		new->next = head;
		head = new;
	}
}
