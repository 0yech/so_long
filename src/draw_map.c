/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheyo <cheyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 19:41:51 by cheyo             #+#    #+#             */
/*   Updated: 2024/12/09 04:00:20 by cheyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_grid(t_game *game)
{
	int	y;

	y = 0;
	game->tile_size = 64;
	while (game->grid[y])
	{
		int	x = 0;
		while (game->grid[y][x])
		{
			void	*image_to_draw = NULL;
			if (game->grid[y][x] == '1')
				image_to_draw = game->textures.wall;
			else if (game->grid[y][x] == 'P')
				image_to_draw = game->textures.player;
			else if (game->grid[y][x] == 'C')
				image_to_draw = game->textures.collectible;
			else if (game->grid[y][x] == 'E')
				image_to_draw = game->textures.exit;
			else if (game->grid[y][x] == '0')
				image_to_draw = game->textures.floor;
			if (image_to_draw)
				mlx_put_image_to_window(game->mlx, game->win, image_to_draw,
					x * game->tile_size, y * game->tile_size);
			x++;
		}
		y++;
	}
}
