/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsurma <tsurma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:28:32 by tsurma            #+#    #+#             */
/*   Updated: 2024/02/19 17:42:41 by tsurma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
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
	size_t	max_x;
	size_t	max_y;
	size_t	temp_x;
	size_t	temp_y;
	size_t	target_score;
	size_t	poss_score;
	size_t	exits;
	size_t	poss_exit;
}	t_level;



int		main(void);
int		movement(char **map, t_level *l, t_player *p, char key);

//Map Functions
char	**fetch_map(char **map, t_level *l);
char	**ft_pointjoin(char **dest, char *src);
int		map_stats(char **map, t_player *p, t_level *l);
void	pos_analyse(char **map, t_player *p, t_level *l);
void	free_map(char **map);
void	print_map_terminal(char **map);
void	find_path(t_level *l, t_player *p, char **map);
int		wanderer(char **map, int x, int y, t_level *l);
char	**cpy_map(char **mapc, char **map, t_level *l);
int	wall_check(char	**map, t_level *l);



#endif
