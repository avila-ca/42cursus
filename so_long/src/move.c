/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avila-ca <avila-ca@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 15:57:14 by avila-ca          #+#    #+#             */
/*   Updated: 2022/11/28 10:44:44 by avila-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_move(int movement, t_game *game)
{
	game->i = 0;
	game->j = 0;
	if (movement == 0)
	{
		if (ft_check_left(game, game->j, game->i))
			ft_left_step(game);
	}
	if (movement == 2)
	{
		if (ft_check_right(game, game->j, game->i))
			ft_right_step(game);
	}
	if (movement == 13)
	{
		if (ft_check_up(game, game->j, game->i))
			ft_up_step(game);
	}
	if (movement == 1)
	{
		if (ft_check_down(game, game->j, game->i))
			ft_down_step(game);
	}
	return (0);
}

int	ft_exit(t_game *game, int x)
{
	int	i;

	i = 0;
	while (game->map[i])
		free(game->map[i++]);
	free(game->map);
	if (game->errors != 0 || x == 53)
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
		ft_exit(game, 53);
	return (0);
}
