/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avila-ca <avila-ca@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 15:29:37 by avila-ca          #+#    #+#             */
/*   Updated: 2022/10/01 13:31:50 by avila-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_print_enemies(t_game *game, int j, int i)
{
	if (game->map[j][i] == 'S')
	{
		game->num_enemy++;
		mlx_put_image_to_window
			(game->mlx_ptr, game->win_ptr,
			game->imgs[11].img_ptr, WIDTH_IMG * i, HEIGHT_IMG * j);
		game->arr_enemies_x[game->num_enemy] = i;
		game->arr_enemies_y[game->num_enemy] = j;
	}
}

int	ft_enemy_render(t_game *game)
{
	if (game->timing_frames == 4000)
	{
		enemy_frame_4(game);
		game->timing_frames = 0;
		if (++game->counter_enemy > game->num_enemy)
			game->counter_enemy = 0;
	}
	if (game->timing_frames == 3000)
	{
		enemy_frame_1(game);
		game->timing_frames++;
	}
	if (game->timing_frames == 2000)
	{
		enemy_frame_2(game);
		game->timing_frames++;
	}
	if (game->timing_frames == 1000)
	{
		enemy_frame_3(game);
		game->timing_frames++;
	}
	else
		game->timing_frames++;
	return (0);
}

void	ft_enemy_kill(t_game *game, int j, int i)
{
	i = 0;
	j = 0;
	ft_dead(game);
	mlx_loop_hook(game->mlx_ptr, NULL, NULL);
	ft_exit(53, game);
	sleep(5);
}

void	ft_enemy_patrol(t_game *game)
{
	if (game->arr_enemies_x[game->counter_enemy] < game->x_hero)
	{
		if (game->map[game->arr_enemies_y[game->counter_enemy]]
			[game->arr_enemies_x[game->counter_enemy] + 1] == 'P')
			ft_enemy_kill(game, game->y_hero, game->x_hero);
		else if (game->map[game->arr_enemies_y[game->counter_enemy]]
			[game->arr_enemies_x[game->counter_enemy] + 1] == '0')
		{
			game->map[game->arr_enemies_y[game->counter_enemy]]
			[game->arr_enemies_x[game->counter_enemy] + 1] = 'S';
			game->map[game->arr_enemies_y[game->counter_enemy]]
			[game->arr_enemies_x[game->counter_enemy]] = '0';
			ft_enemy_right(game);
		}
	}
	else if (game->arr_enemies_x[game->counter_enemy] > game->x_hero)
		enemy_patrol_next(game);
}

void	enemy_patrol_next(t_game *game)
{
	if (game->map[game->arr_enemies_y[game->counter_enemy]]
		[game->arr_enemies_x[game->counter_enemy] - 1] == 'P')
		ft_enemy_kill(game, game->y_hero, game->x_hero);
	else if (game->map[game->arr_enemies_y[game->counter_enemy]]
		[game->arr_enemies_x[game->counter_enemy] - 1] == '0')
	{
		game->map[game->arr_enemies_y[game->counter_enemy]]
		[game->arr_enemies_x[game->counter_enemy] - 1] = 'S';
		game->map[game->arr_enemies_y[game->counter_enemy]]
		[game->arr_enemies_x[game->counter_enemy]] = '0';
		ft_enemy_left(game);
	}	
}
