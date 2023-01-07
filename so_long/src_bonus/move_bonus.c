/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avila-ca <avila-ca@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 15:57:14 by avila-ca          #+#    #+#             */
/*   Updated: 2022/10/01 13:38:41 by avila-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_move(int movement, t_game *game)
{
	game->i = 0;
	game->j = 0;
	if (movement == 0)
	{
		if (ft_check_left(game))
			ft_left_step(game);
	}
	if (movement == 2)
	{
		if (ft_check_right(game))
			ft_right_step(game);
	}
	if (movement == 13)
	{
		if (ft_check_up(game))
			ft_up_step(game);
	}
	if (movement == 1)
	{
		if (ft_check_down(game))
			ft_down_step(game);
	}
	return (0);
}

int	ft_exit(int keycode, t_game *game)
{
	int	x;
	int	i;

	i = 0;
	x = keycode;
	while (game->map[i])
	{
		free(game->map[i++]);
	}
	free(game->map);
	if (x == 53 || game->errors == 1)
	{
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
		free(game->mlx_ptr);
	}
	exit(EXIT_SUCCESS);
	return (0);
}

int	ft_movements(int keycode, t_game *game)
{
	int	x;

	x = keycode;
	if (x == 0)
		ft_move(0, game);
	if (x == 1)
		ft_move(1, game);
	if (x == 2)
		ft_move(2, game);
	if (x == 13)
		ft_move(13, game);
	if (x == 53 || x == 7)
		ft_exit(53, game);
	return (0);
}

int	ft_dead( t_game *game)
{
	mlx_string_put(game->mlx_ptr, game->win_ptr, WIDTH_IMG * game->x_hero,
		HEIGHT_IMG * game->y_hero, 0xFF0000, "GAME");
	mlx_string_put(game->mlx_ptr, game->win_ptr, WIDTH_IMG * game->x_hero,
		50 + HEIGHT_IMG * game->y_hero, 0xFF0000, "OVER");
	return (0);
}

void	ft_print_image_next(t_game *game, int j, int i)
{
	if (game->map[j][i] == '0')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->imgs[0].img_ptr, WIDTH_IMG * i, HEIGHT_IMG * j);
	if (game->map[j][i] == '1')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->imgs[1].img_ptr, WIDTH_IMG * i, HEIGHT_IMG * j);
}
