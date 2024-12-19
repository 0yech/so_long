/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheyo <cheyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 19:41:51 by cheyo             #+#    #+#             */
/*   Updated: 2024/12/13 02:38:05 by cheyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*get_texture(char tile, t_textures *textures)
{
	if (tile == '1')
		return (textures->wall);
	else if (tile == 'P')
		return (textures->player);
	else if (tile == 'C')
		return (textures->collectible);
	else if (tile == 'E')
		return (textures->exit);
	else if (tile == '0')
		return (textures->floor);
	else if (tile == 'Z')
		return (textures->enemy);
	return (NULL);
}

void	draw_grid(t_game *game)
{
	int		y;
	int		x;
	void	*image_to_draw;
	char	*strmov;

	y = 0;
	strmov = ft_itoa(game->moves);
	game->tile_size = 64;
	image_to_draw = NULL;
	while (game->grid[y])
	{
		x = 0;
		while (game->grid[y][x])
		{
			image_to_draw = get_texture(game->grid[y][x], &game->textures);
			if (image_to_draw)
				mlx_put_image_to_window(game->mlx, game->win, image_to_draw,
					x * game->tile_size, y * game->tile_size);
			x++;
		}
		y++;
	}
	mlx_string_put(game->mlx, game->win, 80, 80, 0xFFFFFF,
		strmov);
	free(strmov);
}
