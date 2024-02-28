/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsurma <tsurma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:32:45 by tsurma            #+#    #+#             */
/*   Updated: 2024/02/28 17:06:43 by tsurma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put_wall(int y, int x, mlx_t *mlx);
static void	put_ground(int y, int x, mlx_t *mlx);
static void	put_player(int y, int x, mlx_t *mlx);
static void	put_coll(int y, int x, mlx_t *mlx);
static void	put_exit(int y, int x, mlx_t *mlx);
static void	error(void);

void	print_map(char **map, mlx_t *mlx)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\n')
		{
			if (map[y][x] == '1')
				put_wall(y, x, mlx);
			else
				put_ground(y, x, mlx);
			if (map[y][x] == 'P')
				put_player(y, x, mlx);
			else if (map[y][x] == 'C')
				put_coll(y, x, mlx);
			else if (map[y][x] == 'E')
				put_exit(y, x, mlx);
			++x;
		}
		++y;
	}
}

static void	put_wall(int y, int x, mlx_t *mlx)
{
	mlx_texture_t	*texture;
	mlx_image_t		*img;

	texture = mlx_load_png("./tiles/wall.png");
	if (!texture)
		error();
	img = mlx_texture_to_image(mlx, texture);
	if (!img)
		error();
	if (mlx_image_to_window(mlx, img, (x * 50), (y * 50)) < 0)
		error();
}

static void	put_exit(int y, int x, mlx_t *mlx)
{
	mlx_texture_t	*texture;
	mlx_image_t		*img;

	texture = mlx_load_png("./tiles/exit.png");
	if (!texture)
		error();
	img = mlx_texture_to_image(mlx, texture);
	if (!img)
		error();
	if (mlx_image_to_window(mlx, img, (x * 50), (y * 50)) < 0)
		error();
}

static void	put_coll(int y, int x, mlx_t *mlx)
{
	mlx_texture_t	*texture;
	mlx_image_t		*img;

	texture = mlx_load_png("./tiles/coll.png");
	if (!texture)
		error();
	img = mlx_texture_to_image(mlx, texture);
	if (!img)
		error();
	if (mlx_image_to_window(mlx, img, (x * 50), (y * 50)) < 0)
		error();
}

static void	put_ground(int y, int x, mlx_t *mlx)
{
	mlx_texture_t	*texture;
	mlx_image_t		*img;

	texture = mlx_load_png("./tiles/ground.png");
	if (!texture)
		error();
	img = mlx_texture_to_image(mlx, texture);
	if (!img)
		error();
	if (mlx_image_to_window(mlx, img, (x * 50), (y * 50)) < 0)
		error();
}

static void	put_player(int y, int x, mlx_t *mlx)
{
	mlx_texture_t	*texture;
	mlx_image_t		*img;

	texture = mlx_load_png("./tiles/player.png");
	if (!texture)
		error();
	img = mlx_texture_to_image(mlx, texture);
	if (!img)
		error();
	if (mlx_image_to_window(mlx, img, (x * 50), (y * 50)) < 0)
		error();
}


static void	error(void)
{
	puts(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}
