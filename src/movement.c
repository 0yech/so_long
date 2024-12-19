/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheyo <cheyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:41:53 by cheyo             #+#    #+#             */
/*   Updated: 2024/12/13 02:07:52 by cheyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(int keycode, t_game *game)
{
	t_game	*cpy;

	cpy = game;
	if (keycode == 119)
	{
		if (cpy->grid[cpy->pypos - 1][cpy->pxpos] == '0'
		|| cpy->grid[cpy->pypos - 1][cpy->pxpos] == 'C'
		|| cpy->grid[cpy->pypos - 1][cpy->pxpos] == 'E')
		{
			if (cpy->grid[cpy->pypos - 1][cpy->pxpos] == 'C')
				game->coins--;
			game->pypos -= 1;
			game->moves++;
			game->textures.player = game->textures.pu;
			if (game->pxpos == game->expos && game->pypos == game->eypos
				&& game->coins == 0)
				exit(0);
		}
		else if (cpy->grid[cpy->pypos - 1][cpy->pxpos] == 'Z')
			exit(0);
	}
}

void	move_down(int keycode, t_game *game)
{
	t_game	*cpy;

	cpy = game;
	if (keycode == 115)
	{
		if (cpy->grid[cpy->pypos + 1][cpy->pxpos] == '0'
		|| cpy->grid[cpy->pypos + 1][cpy->pxpos] == 'C'
		|| cpy->grid[cpy->pypos + 1][cpy->pxpos] == 'E')
		{
			if (cpy->grid[cpy->pypos + 1][cpy->pxpos] == 'C')
				game->coins--;
			game->pypos += 1;
			game->moves++;
			game->textures.player = game->textures.pd;
			if (game->pxpos == game->expos && game->pypos == game->eypos
				&& game->coins == 0)
				exit(0);
		}
		else if (cpy->grid[cpy->pypos + 1][cpy->pxpos] == 'Z')
			exit(0);
	}
}

void	move_left(int keycode, t_game *game)
{
	t_game	*cpy;

	cpy = game;
	if (keycode == 97)
	{
		if (cpy->grid[cpy->pypos][cpy->pxpos - 1] == '0'
		|| cpy->grid[cpy->pypos][cpy->pxpos - 1] == 'C'
		|| cpy->grid[cpy->pypos][cpy->pxpos - 1] == 'E')
		{
			if (cpy->grid[cpy->pypos][cpy->pxpos - 1] == 'C')
				game->coins--;
			game->pxpos -= 1;
			game->moves++;
			game->textures.player = game->textures.pl;
			if (game->pxpos == game->expos && game->pypos == game->eypos
				&& game->coins == 0)
				exit(0);
		}
		else if (cpy->grid[cpy->pypos][cpy->pxpos - 1] == 'Z')
			exit(0);
	}
}

void	move_right(int keycode, t_game *game)
{
	t_game	*cpy;

	cpy = game;
	if (keycode == 100)
	{
		if (cpy->grid[cpy->pypos][cpy->pxpos + 1] == '0'
		|| cpy->grid[cpy->pypos][cpy->pxpos + 1] == 'C'
		|| cpy->grid[cpy->pypos][cpy->pxpos + 1] == 'E')
		{
			if (cpy->grid[cpy->pypos][cpy->pxpos + 1] == 'C')
				game->coins--;
			game->pxpos += 1;
			game->moves++;
			game->textures.player = game->textures.pr;
			if (game->pxpos == game->expos && game->pypos == game->eypos
				&& game->coins == 0)
				exit(0);
		}
		else if (cpy->grid[cpy->pypos][cpy->pxpos + 1] == 'Z')
			exit(0);
	}
}

int	keyhook(int keycode, t_game *game)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(game->mlx, game->win);
		exit(0);
	}
	if (keycode == 119)
		move_up(keycode, game);
	if (keycode == 115)
		move_down(keycode, game);
	if (keycode == 97)
		move_left(keycode, game);
	if (keycode == 100)
		move_right(keycode, game);
	if (game->coins == 0)
		game->grid[game->eypos][game->expos] = 'E';
	game->grid[getypos(game->grid, 'P')][getxpos(game->grid, 'P')] = '0';
	game->grid[game->pypos][game->pxpos] = 'P';
	ft_printf("Nb moves %d\n", game->moves);
	mlx_clear_window(game->mlx, game->win);
	draw_grid(game);
	return (0);
}
	//ft_printf("new pos [%d, %d]\n", game->pxpos, game->pypos);
	//ft_printf("Coins left %d\n", game->coins);