/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avila-ca <avila-ca@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 17:04:11 by avila-ca          #+#    #+#             */
/*   Updated: 2022/10/13 08:33:16 by avila-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "mlx.h"
# include "get_next_line.h"
# include "libft.h"
# include <fcntl.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# define BUFFER_SIZE 1
# define WIDTH_IMG 50
# define HEIGHT_IMG 50

typedef struct s_img
{
	void	*img_ptr;
	int		*data;
	int		size_l;
	int		bpp;
	int		endian;
}	t_img;

typedef struct s_game {
	void		*mlx_ptr;
	void		*win_ptr;
	char		**map;
	char		**dup_map;
	char		*map_raw;
	t_img		imgs[7];
	int			j;
	int			i;
	int			fd;
	int			width;
	int			height;
	int			col;
	int			x_hero;
	int			y_hero;
	int			x_door;
	int			y_door;
	int			counter;
	int			errors;
	int			virus;
	int			path_col;
}	t_game;

int		main(int argc, char **argv);
void	ft_get_map(t_game *game);
int		ft_errors_argv(int argc, char *s, int j, size_t i);
int		ft_check_items(t_game *game, int j, int i);
int		ft_check_walls(t_game *game, int j, int i);
int		ft_check_size( t_game *game);
int		ft_check_extension(char *s, int j, size_t i, char *aux);
int		ft_check_errors_map(t_game *game, int j, int i);
int		ft_check_big_map(t_game *game);
void	ft_left_step(t_game *game);
void	ft_right_step(t_game *game);
void	ft_up_step(t_game *game);
void	ft_down_step(t_game *game);
int		ft_movements(int keycode, t_game *game);
int		ft_exit(t_game *game, int exit);
int		ft_move(int movement, t_game *game);
int		ft_check_down(t_game *game, int j, int i);
int		ft_check_up(t_game *game, int j, int i);
int		ft_check_right(t_game *game, int j, int i);
int		ft_check_left(t_game *game, int j, int i);
void	ft_image_winner(t_game *game, int j, int i);
void	ft_get_images(t_game *game);
void	ft_xpm_convert(t_game *game);
void	ft_image_in_map(t_game *game, int j, int i);
void	ft_print_image(t_game *game, int j, int i);
int		ft_map_update(t_game *game, int direction, int j, int i);
void	ft_search_elements(t_game *game, int j, int i);
int		ft_check_path(t_game *game, int j, int i);
int		ft_virus_west(t_game *game, int j, int i);
int		ft_virus_est(t_game *game, int j, int i);
int		ft_virus_south(t_game *game, int j, int i);
int		ft_virus_north(t_game *game, int j, int i);
void	ft_vir_north(t_game *game, int j, int i);
void	ft_vir_south(t_game *game, int j, int i);
void	ft_vir_est(t_game *game, int j, int i);
void	ft_vir_west(t_game *game, int j, int i);

#endif
