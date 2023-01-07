/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avila-ca <avila-ca@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 12:58:06 by avila-ca          #+#    #+#             */
/*   Updated: 2022/10/13 08:42:22 by avila-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_extension(char *s, int j, size_t i, char *aux)
{
	char	*ext;

	ext = ".ber";
	i = ft_strlen(s);
	while (i > ft_strlen(s) - 5)
	{
		aux[j--] = s[i--];
	}
	j = 0;
	i = 0;
	while (aux[j])
	{
		if (aux[j] == ext[j])
			i++;
		j++;
	}
	if (i == 4)
		return (1);
	else
		return (0);
}

int	ft_check_size( t_game *game)
{
	int	i;
	int	width_first;

	i = 0;
	while (game->height >= i && game->map[i])
	{
		if (i == 0)
		{
			width_first = ft_strlen(game->map[i]);
			i++;
		}
		else
		{
			game->width = ft_strlen(game->map[i]);
			if (game->width == width_first)
				i++;
			else
				return (0);
		}
	}
	return (1);
}

int	ft_check_walls(t_game *game, int j, int i)
{
	int	checker;

	checker = 0;
	while (game->map[j][i] && j <= game->height - 1)
	{
		while (game->map[j][i])
		{
			if (j == 0 && game->map[j][i] == '1' && i <= game->width)
				checker++;
			else if (j == game->height - 1
				&& game->map[j][i] == '1' && i <= game->width)
				checker++;
			else if (j > 0 && j < game->height - 1
				&& (i == 0 || i == game->width - 1) && game->map[j][i] == '1')
				checker++;
			i++;
		}
		if (j == game->height - 1 && i == game->width)
			break ;
		i = 0;
		j++;
	}
	return (checker);
}

int	ft_check_items(t_game *game, int j, int i)
{
	int	items;

	items = 0;
	while (j < game->height - 1)
	{
		while (i <= game->width)
		{
			if (game->map[j][i] == 'E')
				items++;
			if (game->map[j][i] == 'C')
				game->col++;
			if (game->map[j][i] == 'P')
				items++;
			if (game->map[j][i] != '0' && game->map[j][i] != '1'
				&& game->map[j][i] != 'E' && game->map[j][i] != 'C'
				&& game->map[j][i] != 'P' && game->map[j][i] != '\0')
				return (0);
			i++;
		}
		i = 0;
		j++;
	}
	if (items == 2 && game->col > 0)
		return (items);
	return (0);
}

int	ft_check_errors_map(t_game *game, int j, int i)
{
	if (!ft_check_size(game))
	{
		write(1, "Error\nInvalid size", 18);
		return (game->errors = 0);
	}	
	if (ft_check_walls(game, j, i) != game->width * 2
		+ ((game->height - 2) * 2))
	{
		write(1, "Error\nWrong walls", 17);
		return (game->errors = 0);
	}
	if (!ft_check_items(game, j, i))
	{
		write(1, "Error\nNot enough items", 22);
		return (game->errors = 0);
	}
	if (!ft_check_path(game, 0, 0))
	{
		write(1, "Error\nNo path", 14);
		return (game->errors = 0);
	}
	return (ft_check_big_map(game));
}
