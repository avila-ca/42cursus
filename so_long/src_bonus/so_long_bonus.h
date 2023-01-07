/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avila-ca <avila-ca@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 12:57:52 by avila-ca          #+#    #+#             */
/*   Updated: 2022/10/13 09:24:29 by avila-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
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
	int		width;
	int		height;
}	t_img;

typedef struct s_game {
	void		*mlx_ptr;
	void		*win_ptr;
	char		**map;
	char		**dup_map;
	char		*map_raw;
	char		**groups;
	t_img		imgs[18];
	int			j;
	int			i;
	int			fd;
	int			width;
	int			height;
	int			col;
	int			x_hero;
	int			y_hero;
	int			i_width;
	int			i_height;
	int			counter;
	int			num_enemy;
	int			arr_enemies_x[6];
	int			arr_enemies_y[6];
	int			x_door;
	int			y_door;
	int			timing_frames;
	int			counter_enemy;
	int			enemies_xy[6][6][6];
	int			left_enemy;
	int			errors;
	int			virus;
	int			path_col;
	char		*movements;
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
void	ft_check_enemies(t_game *game, int j, int i);
void	ft_left_step(t_game *game);
void	ft_right_step(t_game *game);
void	ft_up_step(t_game *game);
void	ft_down_step(t_game *game);
int		ft_movements(int keycode, t_game *game);
int		ft_exit(int keycode, t_game *game);
int		ft_move(int movement, t_game *game);
int		ft_check_down(t_game *game);
int		ft_check_up(t_game *game);
int		ft_check_right(t_game *game);
int		ft_check_left(t_game *game);
int		ft_image_winner(t_game *game);
void	ft_get_images(t_game *game);
int		ft_xpm_convert(t_game *game);
void	ft_image_in_map(t_game *game, int j, int i);
void	ft_print_image(t_game *game, int j, int i);
void	ft_print_image_next(t_game *game, int j, int i);
int		ft_map_update(t_game *game, int direction, int j, int i);
int		ft_xpm_anim_convert(t_game *game);
void	ft_get_anim_images(t_game *game);
void	ft_print_enemies(t_game *game, int j, int i);
int		ft_enemy_render(t_game *game);
void	ft_open_door(t_game *game);
void	ft_enemy_kill(t_game *game, int j, int i);
void	enemy_frame_1(t_game *game);
void	enemy_frame_2(t_game *game);
void	enemy_frame_3(t_game *game);
void	enemy_frame_4(t_game *game);
void	ft_enemy_patrol(t_game *game);
void	enemy_patrol_next(t_game *game);
void	ft_enemy_right(t_game *game);
void	ft_enemy_left(t_game *game);
int		ft_dead(t_game *game);
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
