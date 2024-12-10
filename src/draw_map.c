/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheyo <cheyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 19:41:51 by cheyo             #+#    #+#             */
/*   Updated: 2024/12/10 01:20:50 by cheyo            ###   ########.fr       */
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
	return (NULL);
}

void	draw_grid(t_game *game)
{
	int		y;
	int		x;
	void	*image_to_draw;

	y = 0;
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
}
