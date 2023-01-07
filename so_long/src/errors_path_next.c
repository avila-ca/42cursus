/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_path_next.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avila-ca <avila-ca@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 11:32:53 by avila-ca          #+#    #+#             */
/*   Updated: 2022/11/06 12:18:56 by avila-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_vir_north(t_game *game, int j, int i)
{
	game->dup_map[j][i] = 'x';
	ft_virus_north(game, j, i);
	ft_virus_west(game, j, i);
	ft_virus_est(game, j, i);
}

void	ft_vir_south(t_game *game, int j, int i)
{
	game->dup_map[j][i] = 'x';
	ft_virus_south(game, j, i);
	ft_virus_west(game, j, i);
	ft_virus_est(game, j, i);
}

void	ft_vir_est(t_game *game, int j, int i)
{
	game->dup_map[j][i] = 'x';
	ft_virus_est(game, j, i);
	ft_virus_north(game, j, i);
	ft_virus_south(game, j, i);
}

void	ft_vir_west(t_game *game, int j, int i)
{
	game->dup_map[j][i] = 'x';
	ft_virus_west(game, j, i);
	ft_virus_north(game, j, i);
	ft_virus_south(game, j, i);
}
