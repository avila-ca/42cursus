/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avila-ca <avila-ca@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 16:32:34 by avila-ca          #+#    #+#             */
/*   Updated: 2022/10/06 10:59:45 by avila-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_print_image(t_game *game, int j, int i)
{
	if (game->map[j][i] == '0')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->imgs[0].img_ptr, WIDTH_IMG * i, HEIGHT_IMG * j);
	if (game->map[j][i] == '1')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->imgs[1].img_ptr, WIDTH_IMG * i, HEIGHT_IMG * j);
	if (game->map[j][i] == 'C')
	{
		game->col++;
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->imgs[3].img_ptr, WIDTH_IMG * i, HEIGHT_IMG * j);
	}
	if (game->map[j][i] == 'E')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->imgs[5].img_ptr, WIDTH_IMG * i, HEIGHT_IMG * j);
	if (game->map[j][i] == 'P')
	{
		game->y_hero = j;
		game->x_hero = i;
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->imgs[2].img_ptr, WIDTH_IMG * i, HEIGHT_IMG * j);
	}
}

int	ft_map_update(t_game *game, int direction, int j, int i)
{
	if (direction == 0)
	{
		game->map[j][--i] = 'P';
		game->map[j][++i] = '0';
		return (1);
	}
	if (direction == 2)
	{
		game->map[j][++i] = 'P';
		game->map[j][--i] = '0';
		return (1);
	}
	if (direction == 13)
	{
		game->map[--j][i] = 'P';
		game->map[++j][i] = '0';
		return (1);
	}
	if (direction == 1)
	{
		game->map[++j][i] = 'P';
		game->map[--j][i] = '0';
		return (1);
	}
	return (0);
}

void	ft_image_winner(t_game *game, int j, int i)
{
	if (game->col == 0)
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->imgs[6].img_ptr, WIDTH_IMG * i, HEIGHT_IMG * j);
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->imgs[0].img_ptr, WIDTH_IMG * game->x_hero,
			HEIGHT_IMG * game->y_hero);
		ft_exit(game, 53);
	}
}
