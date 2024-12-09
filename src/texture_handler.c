/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheyo <cheyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 17:40:28 by cheyo             #+#    #+#             */
/*   Updated: 2024/12/09 03:24:50 by cheyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_textures(t_game *game)
{
	if (game->textures.floor)
		mlx_destroy_image(game->mlx, game->textures.floor);
	if (game->textures.wall)
		mlx_destroy_image(game->mlx, game->textures.wall);
	if (game->textures.collectible)
		mlx_destroy_image(game->mlx, game->textures.collectible);
	if (game->textures.exit)
		mlx_destroy_image(game->mlx, game->textures.exit);
	if (game->textures.player)
		mlx_destroy_image(game->mlx, game->textures.player);
}

void	load_textures(t_game *game)
{
	int	img_width;
	int	img_height;

	game->textures.floor = mlx_xpm_file_to_image(game->mlx,
			"textures/floor.xpm", &img_width, &img_height);
	game->textures.wall = mlx_xpm_file_to_image(game->mlx,
			"textures/wall.xpm", &img_width, &img_height);
	game->textures.collectible = mlx_xpm_file_to_image(game->mlx,
			"textures/collectible.xpm", &img_width, &img_height);
	game->textures.exit = mlx_xpm_file_to_image(game->mlx,
			"textures/exit.xpm", &img_width, &img_height);
	game->textures.player = mlx_xpm_file_to_image(game->mlx,
			"textures/player.xpm", &img_width, &img_height);
	if (!game->textures.floor || !game->textures.wall
		|| !game->textures.collectible || !game->textures.exit
		|| !game->textures.player)
	{
		ft_printf("coup dur les textures.");
		free_textures(game);
		exit(1);
	}
}
