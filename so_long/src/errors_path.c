/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avila-ca <avila-ca@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 10:15:06 by avila-ca          #+#    #+#             */
/*   Updated: 2022/11/06 12:18:59 by avila-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_virus_north(t_game *game, int j, int i)
{
	if (game->virus == 1 && game->path_col == game->col)
		return (1);
	if (game->dup_map[j - 1][i] != '1')
	{
		if (game->dup_map[j - 1][i] == 'E')
		{
			game->virus = 1;
			return (1);
		}
		else if (game->dup_map[j - 1][i] == 'P')
			return (1);
		else if (game->dup_map[j - 1][i] == 'C')
		{
			game->path_col++;
			ft_vir_north(game, j - 1, i);
		}
		else if (game->dup_map[j - 1][i] == '0')
			ft_vir_north(game, j - 1, i);
		return (1);
	}
	return (1);
}

int	ft_virus_south(t_game *game, int j, int i)
{
	if (game->virus == 1 && game->path_col == game->col)
		return (1);
	if (game->dup_map[j + 1][i] != '1')
	{
		if (game->dup_map[j + 1][i] == 'E')
		{
			game->virus = 1;
			return (1);
		}
		else if (game->dup_map[j + 1][i] == 'P')
			return (1);
		else if (game->dup_map[j + 1][i] == 'C')
		{
			game->path_col++;
			ft_vir_south(game, j + 1, i);
		}
		else if (game->dup_map[j + 1][i] == '0')
			ft_vir_south(game, j + 1, i);
		return (1);
	}
	return (1);
}

int	ft_virus_est(t_game *game, int j, int i)
{
	if (game->virus == 1 && game->path_col == game->col)
		return (1);
	if (game->dup_map[j][i + 1] != '1')
	{
		if (game->dup_map[j][i + 1] == 'E')
		{
			game->virus = 1;
			return (1);
		}
		else if (game->dup_map[j][i + 1] == 'P')
			return (1);
		else if (game->dup_map[j][i + 1] == 'C')
		{
			game->path_col++;
			ft_vir_est(game, j, i + 1);
		}
		else if (game->dup_map[j][i + 1] == '0')
			ft_vir_est(game, j, i + 1);
		return (1);
	}
	return (1);
}

int	ft_virus_west(t_game *game, int j, int i)
{
	if (game->virus == 1 && game->path_col == game->col)
		return (1);
	if (game->dup_map[j][i - 1] != '1')
	{
		if (game->dup_map[j][i - 1] == 'E')
		{
			game->virus = 1;
			return (1);
		}
		else if (game->dup_map[j][i - 1] == 'P')
			return (1);
		else if (game->dup_map[j][i - 1] == 'C')
		{
			game->path_col++;
			ft_vir_west(game, j, i - 1);
		}
		else if (game->dup_map[j][i - 1] == '0')
			ft_vir_west(game, j, i - 1);
		return (1);
	}
	return (1);
}

int	ft_check_path(t_game *game, int j, int i)
{
	game->path_col = 0;
	game->virus = 0;
	j = game->y_hero;
	i = game->x_hero;
	ft_search_elements(game, 0, 0);
	j = game->y_hero;
	i = game->x_hero;
	ft_virus_north(game, j, i);
	ft_virus_est(game, j, i);
	ft_virus_west(game, j, i);
	ft_virus_south(game, j, i);
	i = 0;
	while (game->dup_map[i])
		free(game->dup_map[i++]);
	free(game->dup_map);
	if (game->virus == 1 && game->path_col == game->col)
		return (1);
	return (0);
}
