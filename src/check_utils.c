/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheyo <cheyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:31:27 by cheyo             #+#    #+#             */
/*   Updated: 2024/12/05 22:58:04 by cheyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	countcoins(char **grid)
{
	int x;
	int y;
	int c;

	x = 0;
	y = 0;
	c = 0;
	while (grid[y])
	{
		x = 0;
		while (grid[y][x])
		{
			if (grid[y][x] == 'C')
				c++;
			x++;
		}
		y++;
	}
	return (c);
}

void refill(t_game *game, int x, int y)
{
    if (!game->grid[y] || !game->grid[y][x]
        || (game->grid[y][x] != 'F' && game->grid[y][x] != 'T'
		&& game->grid[y][x] != 'E'))
        return;
    if (game->grid[y][x] == 'T')
        game->grid[y][x] = 'C';
    else if (game->grid[y][x] == 'F' || game->grid[y][x] == 'E')
        game->grid[y][x] = '0';
    refill(game, x + 1, y);
    refill(game, x - 1, y);
    refill(game, x, y + 1);
    refill(game, x, y - 1);
}


void fill(t_game *game, int x, int y)
{
    if (!game->grid[y] || !game->grid[y][x]
        || (game->grid[y][x] != '0' && game->grid[y][x] != 'E'
        && game->grid[y][x] != 'C' && game->grid[y][x] != 'P'))
        return;
    if (game->grid[y][x] == 'E')
	{
		game->grid[y][x] == '0';
        game->vise++;
	}
    else if (game->grid[y][x] == 'C')
    {
        game->visc++;
        game->grid[y][x] = 'T';
    }
    else
        game->grid[y][x] = 'F';
    fill(game, x + 1, y);
    fill(game, x - 1, y);
    fill(game, x, y + 1);
    fill(game, x, y - 1);
}


int	ffxsize(t_game *game)
{
	int x;
	int y;

	x = getxpos(game->grid, 'P');
	y = getypos(game->grid, 'P');
	game->grid[game->eypos][game->expos] = 'E';
	if (!checkep(game))
		return (0);
	fill(game, x, y);
	//ft_printf("vise : %d\n", game->vise);
	//ft_printf("visc : %d\n", game->visc);
	if (game->visc != game->coins || game->vise < 1)
	{
		free_grid(game->grid);
		return (0);
	}
	refill(game, x, y);
	game->grid[game->pypos][game->pxpos] = 'P';
	return (1);
}