/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheyo <cheyo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:01:13 by cheyo             #+#    #+#             */
/*   Updated: 2024/11/26 15:53:21 by cheyo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"

int close_window(void *param)
{
    (void)param;
    exit(0);
}

int main(int argc, char *argv[])
{
    t_data	data;
	t_image	img;

	if (!openmap(argc, argv))
		return (1);
    data.mlx = mlx_init();
	if (!data.mlx)
		return (1);
	data.win = mlx_new_window(data.mlx, 1920, 1080, "Hello MiniLibX!");
	img.img = mlx_new_image(data.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_length, &img.endian);
	if (!data.win)
		return (2);
	int f;

	f = 0;
	while (f < 1000)
	{
		my_mlx_pixel_put(&img, f, f, 0x00FF0000);
		f++;
	}
	mlx_put_image_to_window(data.mlx, data.win, img.img, 0, 0);
    mlx_hook(data.win, 17, 0, close_window, NULL); // Fermer la fenêtre avec la croix
    mlx_loop(data.mlx);
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