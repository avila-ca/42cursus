/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avila-ca <avila-ca@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 13:13:15 by avila-ca          #+#    #+#             */
/*   Updated: 2022/10/07 09:46:55 by avila-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_movement_counter(t_game *game)
{
	game->i = 0;
	game->j = 0;
	game->movements = ft_itoa(++game->counter);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->imgs[7].img_ptr, WIDTH_IMG * (game->width - 6),
		HEIGHT_IMG * game->height);
	mlx_string_put(game->mlx_ptr, game->win_ptr,
		WIDTH_IMG * (game->width - 6), (HEIGHT_IMG * game->height) + 15,
		0xFFFFFF, "Movement:");
	mlx_string_put(game->mlx_ptr, game->win_ptr,
		WIDTH_IMG * (game->width - 4.6), (HEIGHT_IMG * game->height) + 15,
		0xFFFFFF, game->movements);
	free(game->movements);
}

void	ft_left_step(t_game *game)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->imgs[4].img_ptr, WIDTH_IMG * (--game->x_hero),
		HEIGHT_IMG * (game->y_hero));
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->imgs[0].img_ptr, WIDTH_IMG * (game->x_hero + 1),
		HEIGHT_IMG * (game->y_hero));
	ft_movement_counter(game);
}

void	ft_right_step(t_game *game)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->imgs[2].img_ptr, WIDTH_IMG * (++game->x_hero),
		HEIGHT_IMG * (game->y_hero));
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->imgs[0].img_ptr, WIDTH_IMG * (game->x_hero - 1),
		HEIGHT_IMG * (game->y_hero));
	ft_movement_counter(game);
}

void	ft_up_step(t_game *game)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->imgs[8].img_ptr, WIDTH_IMG * (game->x_hero),
		HEIGHT_IMG * (--game->y_hero));
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->imgs[0].img_ptr, WIDTH_IMG * (game->x_hero),
		HEIGHT_IMG * (game->y_hero + 1));
	ft_movement_counter(game);
}

void	ft_down_step(t_game *game)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->imgs[9].img_ptr, WIDTH_IMG * (game->x_hero),
		HEIGHT_IMG * (++game->y_hero));
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->imgs[0].img_ptr, WIDTH_IMG * (game->x_hero),
		HEIGHT_IMG * (game->y_hero - 1));
	ft_movement_counter(game);
}
