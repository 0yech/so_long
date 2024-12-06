/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheyo <cheyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 20:02:57 by cheyo             #+#    #+#             */
/*   Updated: 2024/12/05 18:50:52 by cheyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	getxpos(char **grid, char c)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (grid[y])
	{
		x = 0;
		while (grid[y][x])
		{
			if (grid[y][x] == c)
				return (x);
			x++;
		}
		y++;
	}
	return (0);
}

int	getypos(char **grid, char c)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (grid[y])
	{
		x = 0;
		while (grid[y][x])
		{
			if (grid[y][x] == c)
				return (y);
			x++;
		}
		y++;
	}
	return (0);
}