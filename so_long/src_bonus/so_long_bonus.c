/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avila-ca <avila-ca@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 13:45:28 by avila-ca          #+#    #+#             */
/*   Updated: 2022/10/06 09:54:27 by avila-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_xpm_convert(t_game *game)
{
	int		height;
	int		width;

	ft_xpm_anim_convert(game);
	game->imgs[0].img_ptr = mlx_xpm_file_to_image
		(game->mlx_ptr, "img_bonus/floor.xpm", &width, &height);
	game->imgs[1].img_ptr = mlx_xpm_file_to_image
		(game->mlx_ptr, "img_bonus/wall.xpm", &width, &height);
	game->imgs[2].img_ptr = mlx_xpm_file_to_image
		(game->mlx_ptr, "img_bonus/hero_right.xpm", &width, &height);
	game->imgs[3].img_ptr = mlx_xpm_file_to_image
		(game->mlx_ptr, "img_bonus/flask.xpm", &width, &height);
	game->imgs[4].img_ptr = mlx_xpm_file_to_image
		(game->mlx_ptr, "img_bonus/hero_left.xpm", &width, &height);
	game->imgs[5].img_ptr = mlx_xpm_file_to_image
		(game->mlx_ptr, "img_bonus/door_close.xpm", &width, &height);
	game->imgs[6].img_ptr = mlx_xpm_file_to_image
		(game->mlx_ptr, "img_bonus/door_open.xpm", &width, &height);
	game->imgs[7].img_ptr = mlx_xpm_file_to_image
		(game->mlx_ptr, "img_bonus/black_rectangle.xpm", &width, &height);
	game->imgs[8].img_ptr = mlx_xpm_file_to_image
		(game->mlx_ptr, "img_bonus/hero_up.xpm", &width, &height);
	game->imgs[9].img_ptr = mlx_xpm_file_to_image
		(game->mlx_ptr, "img_bonus/hero_down.xpm", &width, &height);
	return (0);
}

void	ft_get_images(t_game *game)
{
	game->imgs[0].data = (int *)mlx_get_data_addr(game->imgs[0].img_ptr,
			&game->imgs[0].bpp, &game->imgs[0].size_l, &game->imgs[0].endian);
	game->imgs[1].data = (int *)mlx_get_data_addr(game->imgs[1].img_ptr,
			&game->imgs[1].bpp, &game->imgs[1].size_l, &game->imgs[1].endian);
	game->imgs[2].data = (int *)mlx_get_data_addr(game->imgs[2].img_ptr,
			&game->imgs[2].bpp, &game->imgs[2].size_l, &game->imgs[2].endian);
	game->imgs[3].data = (int *)mlx_get_data_addr(game->imgs[3].img_ptr,
			&game->imgs[3].bpp, &game->imgs[3].size_l, &game->imgs[3].endian);
	game->imgs[4].data = (int *)mlx_get_data_addr(game->imgs[4].img_ptr,
			&game->imgs[4].bpp, &game->imgs[4].size_l, &game->imgs[4].endian);
	game->imgs[5].data = (int *)mlx_get_data_addr(game->imgs[5].img_ptr,
			&game->imgs[5].bpp, &game->imgs[5].size_l, &game->imgs[5].endian);
	game->imgs[6].data = (int *)mlx_get_data_addr(game->imgs[6].img_ptr,
			&game->imgs[6].bpp, &game->imgs[6].size_l, &game->imgs[6].endian);
	game->imgs[7].data = (int *)mlx_get_data_addr(game->imgs[7].img_ptr,
			&game->imgs[7].bpp, &game->imgs[7].size_l, &game->imgs[7].endian);
	game->imgs[8].data = (int *)mlx_get_data_addr(game->imgs[8].img_ptr,
			&game->imgs[8].bpp, &game->imgs[8].size_l, &game->imgs[8].endian);
	game->imgs[9].data = (int *)mlx_get_data_addr(game->imgs[9].img_ptr,
			&game->imgs[9].bpp, &game->imgs[9].size_l, &game->imgs[9].endian);
	ft_get_anim_images(game);
}

void	ft_image_in_map(t_game *game, int j, int i)
{
	game->num_enemy = -1;
	game->col = 0;
	game->counter_enemy = 0;
	game->timing_frames = 0;
	game->left_enemy = 0;
	while (game->width > i && game->height > j && game->map[j][i])
	{
		while (i <= game->width)
		{
			ft_print_image(game, j, i);
			ft_print_enemies(game, j, i);
			i++;
		}
		i = 0;
		j++;
	}
}

void	ft_get_map(t_game *game)
{
	char	*line;

	game->height = 0;
	game->map_raw = NULL;
	line = "ok";
	while (line != NULL)
	{
		line = get_next_line(game->fd);
		if (line)
		{
			game->map_raw = joiner(game->map_raw, line);
			game->height++;
			free(line);
		}
	}
	game->dup_map = ft_split(game->map_raw, '\n');
	game->map = ft_split(game->map_raw, '\n');
	close(game->fd);
	free(line);
	free(game->map_raw);
}

int	main(int argc, char **argv)
{
	t_game	game;

	game.counter = 0;
	game.errors = 1;
	game.fd = open(argv[1], O_RDONLY);
	if (game.fd < 0 || !ft_errors_argv(argc, argv[1], 0, 0))
	{
		close(game.fd);
		write(1, "Error\nWrong map name", 20);
		return (0);
	}
	ft_get_map(&game);
	if (!ft_check_errors_map(&game, 0, 0))
		ft_exit(1, &game);
	game.mlx_ptr = mlx_init();
	game.win_ptr = mlx_new_window (game.mlx_ptr,
			WIDTH_IMG * game.width, (HEIGHT_IMG * game.height) + 20, "so_long");
	ft_xpm_convert(&game);
	ft_image_in_map(&game, 0, 0);
	mlx_key_hook(game.win_ptr, ft_movements, &game);
	mlx_hook(game.win_ptr, 17, 0, ft_exit, &game);
	mlx_loop_hook(game.mlx_ptr, ft_enemy_render, &game);
	mlx_loop(game.mlx_ptr);
	return (0);
}
