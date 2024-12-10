/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheyo <cheyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 00:47:17 by cheyo             #+#    #+#             */
/*   Updated: 2024/12/10 01:03:40 by cheyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	count_elem_in_line(char *line, t_game *game)
{
	int	j;

	j = 0;
	while (line[j])
	{
		if (line[j] == 'E')
			game->ce++;
		else if (line[j] == 'P')
			game->cp++;
		else if (line[j] == 'C')
			game->cc++;
		j++;
	}
}

void	count_elem_in_grid(char **grid, t_game *game)
{
	int	i;

	i = 0;
	while (grid[i])
	{
		count_elem_in_line(grid[i], game);
		i++;
	}
}

int	checkep(t_game *game)
{
	game->cc = 0;
	game->ce = 0;
	game->cp = 0;
	count_elem_in_grid(game->grid, game);
	if (game->ce != 1 || game->cp != 1 || game->cc < 1)
		return (0);
	return (1);
}
