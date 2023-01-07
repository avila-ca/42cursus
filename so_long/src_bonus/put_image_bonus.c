/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avila-ca <avila-ca@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 16:32:34 by avila-ca          #+#    #+#             */
/*   Updated: 2022/10/01 13:38:49 by avila-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_print_image(t_game *game, int j, int i)
{
	ft_print_image_next(game, j, i);
	if (game->map[j][i] == 'C')
	{
		game->col++;
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->imgs[3].img_ptr, WIDTH_IMG * i, HEIGHT_IMG * j);
	}
	if (game->map[j][i] == 'E')
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->imgs[5].img_ptr, WIDTH_IMG * i, HEIGHT_IMG * j);
		game->x_door = i;
		game->y_door = j;
	}
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

int	ft_image_winner(t_game *game)
{
	if (game->col == 0)
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->imgs[6].img_ptr, WIDTH_IMG * game->x_hero,
			HEIGHT_IMG * game->y_hero);
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->imgs[0].img_ptr, WIDTH_IMG * game->x_hero,
			HEIGHT_IMG * game->y_hero);
		mlx_string_put(game->mlx_ptr, game->win_ptr, WIDTH_IMG
			* game->x_hero, HEIGHT_IMG * game->y_hero,
			0xFF0000, "CONGRATULATIONS!!");
		mlx_string_put(game->mlx_ptr, game->win_ptr, WIDTH_IMG
			* game->x_hero, 50 + HEIGHT_IMG * game->y_hero,
			0xFF0000, "YOU   WIN!!");
		ft_enemy_kill(game, game->y_hero, game->x_hero);
	}
	return (0);
}

int	ft_xpm_anim_convert(t_game *game)
{
	int		height;
	int		width;

	game->imgs[10].img_ptr = mlx_xpm_file_to_image
		(game->mlx_ptr, "img_bonus/swampie_r1.xpm", &width, &height);
	game->imgs[11].img_ptr = mlx_xpm_file_to_image
		(game->mlx_ptr, "img_bonus/swampie_r2.xpm", &width, &height);
	game->imgs[12].img_ptr = mlx_xpm_file_to_image
		(game->mlx_ptr, "img_bonus/swampie_r3.xpm", &width, &height);
	game->imgs[13].img_ptr = mlx_xpm_file_to_image
		(game->mlx_ptr, "img_bonus/swampie_r4.xpm", &width, &height);
	game->imgs[14].img_ptr = mlx_xpm_file_to_image
		(game->mlx_ptr, "img_bonus/swampie_l1.xpm", &width, &height);
	game->imgs[15].img_ptr = mlx_xpm_file_to_image
		(game->mlx_ptr, "img_bonus/swampie_l2.xpm", &width, &height);
	game->imgs[16].img_ptr = mlx_xpm_file_to_image
		(game->mlx_ptr, "img_bonus/swampie_l3.xpm", &width, &height);
	game->imgs[17].img_ptr = mlx_xpm_file_to_image
		(game->mlx_ptr, "img_bonus/swampie_l4.xpm", &width, &height);
	return (0);
}

void	ft_get_anim_images(t_game *game)
{
	game->imgs[10].data = (int *)mlx_get_data_addr
		(game->imgs[10].img_ptr, &game->imgs[10].bpp,
			&game->imgs[10].size_l, &game->imgs[10].endian);
	game->imgs[11].data = (int *)mlx_get_data_addr
		(game->imgs[11].img_ptr, &game->imgs[11].bpp,
			&game->imgs[11].size_l, &game->imgs[11].endian);
	game->imgs[12].data = (int *)mlx_get_data_addr
		(game->imgs[12].img_ptr, &game->imgs[12].bpp,
			&game->imgs[12].size_l, &game->imgs[12].endian);
	game->imgs[13].data = (int *)mlx_get_data_addr
		(game->imgs[13].img_ptr, &game->imgs[13].bpp,
			&game->imgs[13].size_l, &game->imgs[13].endian);
	game->imgs[14].data = (int *)mlx_get_data_addr
		(game->imgs[14].img_ptr, &game->imgs[14].bpp,
			&game->imgs[14].size_l, &game->imgs[14].endian);
	game->imgs[15].data = (int *)mlx_get_data_addr
		(game->imgs[15].img_ptr, &game->imgs[15].bpp,
			&game->imgs[15].size_l, &game->imgs[15].endian);
	game->imgs[16].data = (int *)mlx_get_data_addr
		(game->imgs[16].img_ptr, &game->imgs[16].bpp,
			&game->imgs[16].size_l, &game->imgs[16].endian);
	game->imgs[17].data = (int *)mlx_get_data_addr
		(game->imgs[17].img_ptr, &game->imgs[17].bpp,
			&game->imgs[17].size_l, &game->imgs[17].endian);
}
