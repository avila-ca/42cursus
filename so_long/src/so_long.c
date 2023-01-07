/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avila-ca <avila-ca@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 13:45:28 by avila-ca          #+#    #+#             */
/*   Updated: 2022/10/07 10:55:02 by avila-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_xpm_convert(t_game *game)
{
	int		height;
	int		width;

	game->imgs[0].img_ptr = mlx_xpm_file_to_image
		(game->mlx_ptr, "img/floor.xpm", &width, &height);
	game->imgs[1].img_ptr = mlx_xpm_file_to_image
		(game->mlx_ptr, "img/wall.xpm", &width, &height);
	game->imgs[2].img_ptr = mlx_xpm_file_to_image
		(game->mlx_ptr, "img/hero_right.xpm", &width, &height);
	game->imgs[3].img_ptr = mlx_xpm_file_to_image
		(game->mlx_ptr, "img/flask.xpm", &width, &height);
	game->imgs[5].img_ptr = mlx_xpm_file_to_image
		(game->mlx_ptr, "img/door_close.xpm", &width, &height);
	game->imgs[6].img_ptr = mlx_xpm_file_to_image
		(game->mlx_ptr, "img/door_open.xpm", &width, &height);
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
	game->imgs[5].data = (int *)mlx_get_data_addr(game->imgs[5].img_ptr,
			&game->imgs[5].bpp, &game->imgs[5].size_l, &game->imgs[5].endian);
	game->imgs[6].data = (int *)mlx_get_data_addr(game->imgs[6].img_ptr,
			&game->imgs[6].bpp, &game->imgs[6].size_l, &game->imgs[6].endian);
}

void	ft_image_in_map(t_game *game, int j, int i)
{
	game->col = 0;
	while (game->width > i && game->height > j && game->map[j][i])
	{
		while (i <= game->width)
		{
			ft_print_image(game, j, i);
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
	game->map = ft_split(game->map_raw, '\n');
	game->dup_map = ft_split(game->map_raw, '\n');
	close(game->fd);
	free(line);
}

int	main(int argc, char **argv)
{
	t_game	game;

	game.counter = 0;
	game.errors = 1;
	if (!ft_errors_argv(argc, argv[1], 0, 0))
		return (0);
	game.fd = open(argv[1], O_RDONLY);
	if (game.fd < 0)
	{
		close(game.fd);
		write(1, "Error\nWrong map name", 20);
		return (0);
	}
	ft_get_map(&game);
	if (!ft_check_errors_map(&game, 0, 0))
		ft_exit(&game, 0);
	game.mlx_ptr = mlx_init();
	game.win_ptr = mlx_new_window (game.mlx_ptr,
			WIDTH_IMG * game.width, HEIGHT_IMG * game.height, "so_long");
	ft_xpm_convert(&game);
	ft_image_in_map(&game, 0, 0);
	mlx_key_hook(game.win_ptr, ft_movements, &game);
	mlx_hook(game.win_ptr, 17, 0, ft_exit, &game);
	mlx_loop(game.mlx_ptr);
	return (0);
}
