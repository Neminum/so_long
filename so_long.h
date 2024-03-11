/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsurma <tsurma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:28:32 by tsurma            #+#    #+#             */
/*   Updated: 2024/03/11 18:05:33 by tsurma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "../MLX42/include/MLX42/MLX42.h"

typedef struct player
{
	size_t	x;
	size_t	y;
	size_t	score;
	size_t	steps;
	char	lt;
}	t_player;

typedef struct level
{
	int		fd;
	char	**map;
	size_t	max_x;
	size_t	max_y;
	size_t	temp_x;
	size_t	temp_y;
	size_t	target_score;
	size_t	poss_score;
	size_t	exits;
	size_t	poss_exit;
}	t_level;

typedef struct textures
{
	mlx_texture_t	*wall_t;
	mlx_image_t		*wall;
	mlx_texture_t	*ground_t;
	mlx_image_t		*ground;
	mlx_texture_t	*character_t;
	mlx_image_t		*character;
	mlx_texture_t	*collectible_t;
	mlx_image_t		*collectible;
	mlx_texture_t	*lexit_t;
	mlx_image_t		*lexit;

}	t_tex;

typedef struct s_messages
{
	mlx_image_t	*step_count;
}	t_mess;

typedef struct all
{
	void		*mlx;
	t_player	*player;
	t_level		*level;
	t_tex		*tex;
	t_mess		*mess;

}	t_all;

typedef enum err_codes
{
	COMPLETE,
	PSPAWNS,
	ESPAWNS,
	MWALLS,
	NOPATH,
	UNKNOWN
}	t_errs;

int		main(int argc, char **argv);
void	movement(mlx_key_data_t keydata, void *b);

//Map Functions
void	fetch_map(t_all *a);
char	**ft_pointjoin(char **dest, char *src);
int		map_stats(t_all *a);
void	free_map(char **map);
void	find_path(t_all *a);

//MLX functions
void	*window(t_level *l);
void	print_map(t_all *a);
void	load_textures(t_all *a, t_tex *t);
void	put_tile(int y, int x, t_all *a);
void	load_mess(t_all *a);
void	exit_clean(t_all *a, char **mapc, t_errs err);

#endif
