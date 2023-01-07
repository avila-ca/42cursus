/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_frames.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avila-ca <avila-ca@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 12:48:50 by avila-ca          #+#    #+#             */
/*   Updated: 2022/10/01 12:44:27 by avila-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	enemy_frame_1(t_game *game)
{
	if (game->left_enemy == 0)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->imgs[11].img_ptr, WIDTH_IMG
			* game->arr_enemies_x[game->counter_enemy],
			HEIGHT_IMG * game->arr_enemies_y[game->counter_enemy]);
	else
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->imgs[15].img_ptr, WIDTH_IMG
			* game->arr_enemies_x[game->counter_enemy],
			HEIGHT_IMG * game->arr_enemies_y[game->counter_enemy]);
}

void	enemy_frame_2(t_game *game)
{
	if (game->left_enemy == 0)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->imgs[12].img_ptr, WIDTH_IMG
			* game->arr_enemies_x[game->counter_enemy],
			HEIGHT_IMG * game->arr_enemies_y[game->counter_enemy]);
	else
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->imgs[16].img_ptr, WIDTH_IMG
			* game->arr_enemies_x[game->counter_enemy],
			HEIGHT_IMG * game->arr_enemies_y[game->counter_enemy]);
}

void	enemy_frame_3(t_game *game)
{
	if (game->left_enemy == 0)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->imgs[13].img_ptr, WIDTH_IMG
			* game->arr_enemies_x[game->counter_enemy],
			HEIGHT_IMG * game->arr_enemies_y[game->counter_enemy]);
	else
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->imgs[17].img_ptr, WIDTH_IMG
			* game->arr_enemies_x[game->counter_enemy],
			HEIGHT_IMG * game->arr_enemies_y[game->counter_enemy]);
}

void	enemy_frame_4(t_game *game)
{
	if (game->left_enemy == 0)
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->imgs[10].img_ptr, WIDTH_IMG
			* game->arr_enemies_x[game->counter_enemy],
			HEIGHT_IMG * game->arr_enemies_y[game->counter_enemy]);
		ft_enemy_patrol(game);
	}
	else
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->imgs[14].img_ptr, WIDTH_IMG
			* game->arr_enemies_x[game->counter_enemy],
			HEIGHT_IMG * game->arr_enemies_y[game->counter_enemy]);
		ft_enemy_patrol(game);
	}
}
