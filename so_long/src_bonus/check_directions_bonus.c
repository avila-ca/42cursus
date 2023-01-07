/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_directions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avila-ca <avila-ca@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 16:17:57 by avila-ca          #+#    #+#             */
/*   Updated: 2022/11/09 14:08:39 by avila-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_check_left(t_game *game)
{
	if (game->map[game->y_hero][game->x_hero - 1] == '0')
		return (ft_map_update(game, 0, game->y_hero, game->x_hero));
	if (game->map[game->y_hero][game->x_hero - 1] == '1')
		return (0);
	if (game->map[game->y_hero][game->x_hero - 1] == 'C')
	{
		game->col--;
		ft_open_door(game);
		return (ft_map_update(game, 0, game->y_hero, game->x_hero));
	}
	if (game->map[game->y_hero][game->x_hero - 1] == 'S')
		ft_enemy_kill(game, game->y_hero, game->x_hero);
	if (game->map[game->y_hero][game->x_hero - 1] == 'E')
		ft_image_winner(game);
	return (0);
}

int	ft_check_right(t_game *game)
{
	if (game->map[game->y_hero][game->x_hero + 1] == '0')
		return (ft_map_update(game, 2, game->y_hero, game->x_hero));
	if (game->map[game->y_hero][game->x_hero + 1] == '1')
		return (0);
	if (game->map[game->y_hero][game->x_hero + 1] == 'C')
	{
		game->col--;
		ft_open_door(game);
		return (ft_map_update(game, 2, game->y_hero, game->x_hero));
	}
	if (game->map[game->y_hero][game->x_hero + 1] == 'S')
		ft_enemy_kill(game, game->y_hero, game->x_hero);
	if (game->map[game->y_hero][game->x_hero + 1] == 'E')
		ft_image_winner(game);
	return (0);
}

int	ft_check_up(t_game *game)
{
	if (game->map[game->y_hero - 1][game->x_hero] == '0')
		return (ft_map_update(game, 13, game->y_hero, game->x_hero));
	if (game->map[game->y_hero - 1][game->x_hero] == '1')
		return (0);
	if (game->map[game->y_hero - 1][game->x_hero] == 'C')
	{
		game->col--;
		ft_open_door(game);
		return (ft_map_update(game, 13, game->y_hero, game->x_hero));
	}
	if (game->map[game->y_hero - 1][game->x_hero] == 'S')
		ft_enemy_kill(game, game->y_hero, game->x_hero);
	if (game->map[game->y_hero - 1][game->x_hero] == 'E')
		ft_image_winner(game);
	return (0);
}

int	ft_check_down(t_game *game)
{
	if (game->map[game->y_hero + 1][game->x_hero] == '0')
		return (ft_map_update(game, 1, game->y_hero, game->x_hero));
	if (game->map[game->y_hero + 1][game->x_hero] == '1')
		return (0);
	if (game->map[game->y_hero + 1][game->x_hero] == 'C')
	{
		game->col--;
		ft_open_door(game);
		return (ft_map_update(game, 1, game->y_hero, game->x_hero));
	}
	if (game->map[game->y_hero + 1][game->x_hero] == 'S')
		ft_enemy_kill(game, game->y_hero, game->x_hero);
	if (game->map[game->y_hero + 1][game->x_hero] == 'E')
		ft_image_winner(game);
	return (0);
}

void	ft_open_door(t_game *game)
{
	if (game->col == 0)
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->imgs[6].img_ptr, WIDTH_IMG * game->x_door,
			HEIGHT_IMG * game->y_door);
	}
}
