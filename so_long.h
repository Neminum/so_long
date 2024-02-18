/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobias <tobias@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:28:32 by tsurma            #+#    #+#             */
/*   Updated: 2024/02/16 16:06:20 by tobias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "MLX42/include/MLX42/MLX42.h"

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
	size_t	max_x;
	size_t	max_y;
	size_t	target_score;
	size_t	Exits;
	size_t	Players;

}	t_level;



int		main(void);
void	movement(char **map, t_level *l, t_player *p, char key);

//Map Functions
char	**fetch_map(char **map);
char	**ft_pointjoin(char **dest, char *src);
void	map_stats(char **map, t_player *p,  t_level *l);
void	pos_analyse(char **map, t_player *p, t_level *l, size_t x, size_t y);
void	free_map(char **map);

#endif
