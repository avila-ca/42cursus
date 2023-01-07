/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_move_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avila-ca <avila-ca@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 09:44:05 by avila-ca          #+#    #+#             */
/*   Updated: 2022/10/03 11:06:50 by avila-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_enemy_right(t_game *game)
{
	game->left_enemy = 0;
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->imgs[0].img_ptr, WIDTH_IMG
		* game->arr_enemies_x[game->counter_enemy],
		HEIGHT_IMG * game->arr_enemies_y[game->counter_enemy]);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->imgs[10].img_ptr, WIDTH_IMG
		* ++game->arr_enemies_x[game->counter_enemy],
		HEIGHT_IMG * game->arr_enemies_y[game->counter_enemy]);
}

void	ft_enemy_left(t_game *game)
{
	game->left_enemy = 1;
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->imgs[0].img_ptr, WIDTH_IMG
		* game->arr_enemies_x[game->counter_enemy],
		HEIGHT_IMG * game->arr_enemies_y[game->counter_enemy]);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->imgs[14].img_ptr, WIDTH_IMG
		* --game->arr_enemies_x[game->counter_enemy],
		HEIGHT_IMG * game->arr_enemies_y[game->counter_enemy]);
}
