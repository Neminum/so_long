/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsurma <tsurma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:28:32 by tsurma            #+#    #+#             */
/*   Updated: 2024/02/28 18:27:16 by tsurma           ###   ########.fr       */
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

typedef struct all
{
	void		*mlx;
	t_player	*player;
	t_level		*level;
}	t_all;

int		main(void);
void	movement(mlx_key_data_t keydata, void *b);
int		step(t_player *p, t_level *l, t_all *a);


//Map Functions
void	fetch_map(t_level *l);
char	**ft_pointjoin(char **dest, char *src);
int		map_stats(t_player *p, t_level *l);
void	pos_analyse(t_player *p, t_level *l);
void	free_map(char **map);
// void	print_map_terminal(char **map);
void	find_path(t_level *l, t_player *p);
int		wanderer(char **map, int x, int y, t_level *l);
char	**cpy_map(char **mapc, char **map);
int		wall_check(t_level *l);

//MLX functions
void	*window(t_level *l);
void	print_map(char **map, mlx_t *mlx);



#endif
