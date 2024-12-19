/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheyo <cheyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 17:40:28 by cheyo             #+#    #+#             */
/*   Updated: 2024/12/13 02:30:57 by cheyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_player(t_game *game)
{
	if (game->textures.player)
		mlx_destroy_image(game->mlx, game->textures.player);
	if (game->textures.pu)
		mlx_destroy_image(game->mlx, game->textures.pu);
	if (game->textures.pl)
		mlx_destroy_image(game->mlx, game->textures.pl);
	if (game->textures.pr)
		mlx_destroy_image(game->mlx, game->textures.pr);
	if (game->textures.pd)
		mlx_destroy_image(game->mlx, game->textures.pd);
}

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
	if (game->textures.enemy)
		mlx_destroy_image(game->mlx, game->textures.enemy);
	free_player(game);
}

void	init_player_textures(t_game *game)
{
	int	img_width;
	int	img_height;

	game->textures.pd = mlx_xpm_file_to_image(game->mlx,
			"textures/player.xpm", &img_width, &img_height);
	game->textures.pr = mlx_xpm_file_to_image(game->mlx,
			"textures/pr.xpm", &img_width, &img_height);
	game->textures.pl = mlx_xpm_file_to_image(game->mlx,
			"textures/pl.xpm", &img_width, &img_height);
	game->textures.pu = mlx_xpm_file_to_image(game->mlx,
			"textures/pu.xpm", &img_width, &img_height);
	game->textures.player = game->textures.pd;
	if (!game->textures.pr || !game->textures.pl
		|| !game->textures.pu || !game->textures.player)
	{
		free_textures(game);
		exit(1);
	}
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
	game->textures.enemy = mlx_xpm_file_to_image(game->mlx,
			"textures/enemy.xpm", &img_width, &img_height);
	init_player_textures(game);
	if (!game->textures.floor || !game->textures.wall
		|| !game->textures.collectible || !game->textures.exit
		|| !game->textures.enemy)
	{
		free_textures(game);
		exit(1);
	}
}
