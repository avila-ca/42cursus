/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_directions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avila-ca <avila-ca@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 16:17:57 by avila-ca          #+#    #+#             */
/*   Updated: 2022/08/05 12:04:20 by avila-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_left(t_game *game, int j, int i)
{
	while (game->width > i && game->height > j)
	{
		while (i <= game->width)
		{
			if (game->map[j][i] == 'P')
			{
				if (game->map[j][i - 1] == '0')
					return (ft_map_update(game, 0, j, i));
				if (game->map[j][i - 1] == '1')
					return (0);
				if (game->map[j][i - 1] == 'C')
				{
					game->col--;
					return (ft_map_update(game, 0, j, i));
				}
				if (game->map[j][i - 1] == 'E')
					ft_image_winner(game, j, i - 1);
			}
			i++;
		}
		i = 0;
		j++;
	}
	return (0);
}

int	ft_check_right(t_game *game, int j, int i)
{
	while (game->width > i && game->height > j)
	{
		while (i <= game->width)
		{
			if (game->map[j][i] == 'P')
			{
				if (game->map[j][i + 1] == '0')
					return (ft_map_update(game, 2, j, i));
				if (game->map[j][i + 1] == '1')
					return (0);
				if (game->map[j][i + 1] == 'C')
				{
					game->col--;
					return (ft_map_update(game, 2, j, i));
				}
				if (game->map[j][i + 1] == 'E')
					ft_image_winner(game, j, i + 1);
			}
			i++;
		}
		i = 0;
		j++;
	}
	return (0);
}

int	ft_check_up(t_game *game, int j, int i)
{
	while (game->width > i && game->height > j)
	{
		while (i <= game->width)
		{
			if (game->map[j][i] == 'P')
			{
				if (game->map[j - 1][i] == '0')
					return (ft_map_update(game, 13, j, i));
				if (game->map[j - 1][i] == '1')
					return (0);
				if (game->map[j - 1][i] == 'C')
				{
					game->col--;
					return (ft_map_update(game, 13, j, i));
				}
				if (game->map[j - 1][i] == 'E')
					ft_image_winner(game, j - 1, i);
			}
			i++;
		}
		i = 0;
		j++;
	}
	return (0);
}

int	ft_check_down(t_game *game, int j, int i)
{
	while (game->width > i && game->height > j)
	{
		while (i <= game->width)
		{
			if (game->map[j][i] == 'P')
			{
				if (game->map[j + 1][i] == '0')
					return (ft_map_update(game, 1, j, i));
				if (game->map[j + 1][i] == '1')
					return (0);
				if (game->map[j + 1][i] == 'C')
				{
					game->col--;
					return (ft_map_update(game, 1, j, i));
				}
				if (game->map[j + 1][i] == 'E')
					ft_image_winner(game, j + 1, i);
			}
			i++;
		}
		i = 0;
		j++;
	}
	return (0);
}
