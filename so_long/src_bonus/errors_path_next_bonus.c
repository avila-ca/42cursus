/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_path_next_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avila-ca <avila-ca@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 12:04:32 by avila-ca          #+#    #+#             */
/*   Updated: 2022/10/22 09:12:13 by avila-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_vir_north(t_game *game, int j, int i)
{
	if (game->dup_map[j - 1][i] == 'C')
		game->dup_map[j - 1][i] = 'x';
	game->dup_map[j - 1][i] = 'x';
	ft_virus_north(game, j - 1, i);
	ft_virus_west(game, j - 1, i);
	ft_virus_est(game, j - 1, i);
}

void	ft_vir_south(t_game *game, int j, int i)
{
	if (game->dup_map[j + 1][i] == 'C')
		game->dup_map[j + 1][i] = 'x';
	game->dup_map[j + 1][i] = 'x';
	ft_virus_south(game, j + 1, i);
	ft_virus_west(game, j + 1, i);
	ft_virus_est(game, j + 1, i);
}

void	ft_vir_est(t_game *game, int j, int i)
{
	if (game->dup_map[j][i + 1] == 'C')
		game->dup_map[j][i + 1] = 'x';
	game->dup_map[j][i + 1] = 'x';
	ft_virus_est(game, j, i + 1);
	ft_virus_north(game, j, i + 1);
	ft_virus_south(game, j, i + 1);
}

void	ft_vir_west(t_game *game, int j, int i)
{
	if (game->dup_map[j][i - 1] == 'C')
		game->dup_map[j][i - 1] = 'x';
	game->dup_map[j][i - 1] = 'x';
	ft_virus_west(game, j, i - 1);
	ft_virus_north(game, j, i - 1);
	ft_virus_south(game, j, i - 1);
}
