/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avila-ca <avila-ca@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:47:43 by avila-ca          #+#    #+#             */
/*   Updated: 2023/03/22 10:56:06 by avila-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_arr(int *arr_num, int error)
{
	if (arr_num != NULL)
	{
		free(arr_num);
		arr_num = NULL;
	}
	if (error)
	{
		write(2, "Error\n", 6);
		exit(-1);
	}
}

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
				free_arr(arr_num, 1);
			j++;
		}
	}
}

int	check_no_num2(char **argv, int *arr_num, int i, int num)
{
	while (argv[++num])
	{
		if (ft_strlen(argv[num]) > 12 || !ft_strlen(argv[num]))
			free_arr(arr_num, 1);
		while (argv[num][i])
		{
			if (((argv[num][i] == '-' || argv[num][i] == '+') && i == 0)
				&& (argv[num][i + 1] >= '0' && argv[num][i + 1] <= '9'))
				i++;
			else if (argv[num][i] >= '0' && argv[num][i] <= '9')
				i++;
			else
				free_arr(arr_num, 1);
		}
		arr_num[num] = atoi_push(argv[num]);
		i = 0;
	}
	return (0);
}

int	check_no_num(int argc, char **argv)
{
	int	i;
	int	num;
	int	*arr_num;

	num = 0;
	arr_num = NULL;
	arr_num = malloc(sizeof(int *) * argc);
	if (!arr_num)
		return (0);
	i = 0;
	check_no_num2(argv, arr_num, i, num);
	check_dup(arr_num, argc);
	free_arr(arr_num, 0);
	return (0);
}
