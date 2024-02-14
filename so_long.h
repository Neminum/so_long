/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsurma <tsurma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:28:32 by tsurma            #+#    #+#             */
/*   Updated: 2024/02/14 18:08:21 by tsurma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct player
{
	size_t	x;
	size_t	y;
	size_t	score;
	size_t	steps;
	char	lt;
}	t_player;


int		main(void);
char	**ft_pointjoin(char **dest, char *src);
void	find_player(char **map, t_player *p);
void	movement(char **map, t_player *p, char key);


#endif
