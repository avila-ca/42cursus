/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avila-ca <avila-ca@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:47:43 by avila-ca          #+#    #+#             */
/*   Updated: 2023/01/11 11:23:11 by avila-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_dup(int *arr_num, int argc)
{
	int	i;
	int	j;

	i = 0;
	while (++i < argc)
	{
		j = 1;
		while (j < argc)
		{
			if (arr_num[i] == arr_num[j] && j != i)
			{
				write(2, "Error\n", 6);
				exit(-1);
			}
			j++;
		}
	}
}

int	check_no_num(int argc, char **argv)
{
	int	i;
	int num;
	int *arr_num;
	
	arr_num = malloc(sizeof(int *) * argc);
	num = 0;
	i = 0;
	while (argv[++num])
	{
		if (ft_strlen(argv[num]) > 12)
		{
			write(2, "Error\n", 6);
			return (1);
		}
		while (argv[num][i])
		{
//			if (('!' < argv[num][i] && argv[num][i] < '+') || argv[num][i] == ',' || argv[num][i] == '.' || argv[num][i] == '/' || (58 < argv[num][i] && argv[num][i] < 127) || (argv[num][i] == '-' && (argv[num][i + 1] < '0' || argv[num][i + 1] > '9')) || (argv[num][i] == '+' && (argv[num][i + 1] < '0' || argv[num][i + 1] > '9')))
		//	if (argv[num][i] != '-' || !(argv[num][i] >= '0' && argv[num][i] <= '9') || argv[num][i] != ' ')
			if ((argv[num][i] == '-' && (argv[num][i + 1] >= '0' && argv[num][i + 1] <= '9')) || (argv[num][i] >= '0' && argv[num][i] <= '9'))
				i++;
			else
			{
					write(2, "Error\n", 6);
					return (1);
			}
		}
		arr_num[num] = atoi_push(argv[num]);
		i = 0;
	}
check_dup(arr_num, argc);
return (0);
}

int	check_end(t_lst **stack_a)
{
	t_lst	*tempa;

	tempa = *stack_a;
	while(tempa)
	{
		if ((*tempa).next != NULL)
		{
			if ((*tempa).next->index - (*tempa).index != 1)
				return (0);
		}
		else
			break ;
		tempa = (*tempa).next;
	}
	return (1);
}
