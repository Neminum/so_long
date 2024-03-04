/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsurma <tsurma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:32:45 by tsurma            #+#    #+#             */
/*   Updated: 2024/03/04 20:20:16 by tsurma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// static void	error(void);


void	print_map(t_all *a)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (a->level->map[y] != NULL)
	{
		x = 0;
		while (a->level->map[y][x] != '\n')
		{
			put_tile(y, x, a);
			++x;
		}
		++y;
	}
}

void	load_textures(t_all *a, t_tex *t)
{
	t->ground_t = mlx_load_png("./tiles/ground.png");
	t->ground = mlx_texture_to_image(a->mlx, t->ground_t);
	mlx_delete_texture(t->ground_t);
	t->wall_t = mlx_load_png("./tiles/wall.png");
	t->wall = mlx_texture_to_image(a->mlx, t->wall_t);
	mlx_delete_texture(t->wall_t);
	t->character_t = mlx_load_png("./tiles/player.png");
	t->character = mlx_texture_to_image(a->mlx, t->character_t);
	mlx_delete_texture(t->character_t);
	t->collectible_t = mlx_load_png("./tiles/coll.png");
	t->collectible = mlx_texture_to_image(a->mlx, t->collectible_t);
	mlx_delete_texture(t->collectible_t);
	t->lexit_t = mlx_load_png("./tiles/exit.png");
	t->lexit = mlx_texture_to_image(a->mlx, t->lexit_t);
	mlx_delete_texture(t->lexit_t);
}

void	put_tile(int y, int x, t_all *a)
{
	if (a->level->map[y][x] == '1')
		mlx_image_to_window(a->mlx, a->tex->wall, (x * 50), (y * 50));
	else
		mlx_image_to_window(a->mlx, a->tex->ground, (x * 50), (y * 50));
	if (a->level->map[y][x] == 'P')
		mlx_image_to_window(a->mlx, a->tex->character, (x * 50), (y * 50));
	else if (a->level->map[y][x] == 'C')
		mlx_image_to_window(a->mlx, a->tex->collectible, (x * 50), (y * 50));
	else if (a->level->map[y][x] == 'E')
		mlx_image_to_window(a->mlx, a->tex->lexit, (x * 50), (y * 50));
}

// static void	error(void)
// {
// 	puts(mlx_strerror(mlx_errno));
// 	exit(EXIT_FAILURE);
// }
