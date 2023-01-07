/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_argv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avila-ca <avila-ca@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 11:34:16 by avila-ca          #+#    #+#             */
/*   Updated: 2022/11/06 15:07:38 by avila-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_errors_argv(int argc, char *s, int j, size_t i)
{
	char	*aux;

	aux = NULL;
	j = 4;
	aux = malloc(sizeof(char) * 5);
	if (!aux)
		return (0);
	if (argc != 2)
	{
		write(1, "Error\nWrong number of arguments", 31);
		free(aux);
		return (0);
	}
	if (!ft_check_extension(s, j, i, aux))
	{
		write(1, "Error\nInvalid extension", 23);
		free(aux);
		return (0);
	}
	free(aux);
	return (1);
}

void	ft_search_elements(t_game *game, int j, int i)
{
	while (++j < game->height - 1)
	{
		while (++i < game->width)
		{
			if (game->map[j][i] == 'P')
			{
				game->y_hero = j;
				game->x_hero = i;
			}
			if (game->map[j][i] == 'E')
			{
				game->y_door = j;
				game->x_door = i;
			}
		}
		i = 0;
	}
}

int	ft_check_big_map(t_game *game)
{
	if (game->width > 52 || game->height > 28)
	{
		write(1, "Error\nMap too big", 17);
		return (game->errors = 0);
	}
	return (1);
}
