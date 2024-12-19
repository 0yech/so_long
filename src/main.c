/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheyo <cheyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:01:13 by cheyo             #+#    #+#             */
/*   Updated: 2024/12/13 02:38:22 by cheyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(void *param)
{
	(void)param;
	exit(0);
}

int	game_call(t_game game)
{
	game.mlx = mlx_init();
	if (!game.mlx)
	{
		free_grid(game.grid);
		return (1);
	}
	game.win = mlx_new_window(game.mlx, game.len * 64, game.hei * 64,
			"so_long");
	if (!game.win)
	{
		free_grid(game.grid);
		mlx_destroy_display(game.mlx);
		free(game.mlx);
		return (1);
	}
	load_textures(&game);
	draw_grid(&game);
	mlx_hook(game.win, 17, 0, close_window, NULL);
	mlx_hook(game.win, 2, 1L << 0, keyhook, &game);
	mlx_loop(game.mlx);
	free_grid(game.grid);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_game	game;

	if (!openmap(argc, argv))
		return (1);
	if (!load_map(argc, argv, &game))
		return (1);
	if (!ffxsize(&game))
		return (1);
	if (game_call(game))
		return (2);
	return (0);
}

// so_long MEMO/TODO

// send help i'm losing my mind

/*
	HANDLING MAPS

	Maps are .ber files

	Make basic file checks
		- Can't find file
		- Empty file

	Map rules
		- Rectangular shape
		- Has a start (P), an exit (E) and collectibles (C)
		- Walls (1)

	Learn about floodfills to check that all coins
	are reachable and that the player can reach the end.


	Map logic and validity.

	I could check the map with GNL.
	
	The first and last line must be full of walls (1) followed by \n
	all other lines MUST have their first and last index as walls too

	make a struct called mapchecker (maybe ?) it contains ints for
	player, exit, collectables. player, exit must be at 1, collectables
	must match the amount that is encountered. Just scan through the map
	and count all elements.


*/