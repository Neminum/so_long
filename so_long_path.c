/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsurma <tsurma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:50:50 by tsurma            #+#    #+#             */
/*   Updated: 2024/02/19 17:16:28 by tsurma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_path(t_level *l, t_player *p, char **map)
{
	char	**mapc;
	int		y;
	int		x;

	x = p->x;
	y = p->y;
	mapc = cpy_map(mapc, map, l);
	if (wall_check(mapc, l) != 0)
	{
		free_map(mapc);
		free_map(map);
		ft_printf("Error\nMap borders invalid\n");
		exit (0);
	}
	if (wanderer(mapc, x, y, l) == 1)
	{
		free_map(mapc);
		free_map(map);
		ft_printf("Error\nMap path invalid\n");
		exit (0);
	}
	free_map(mapc);
	return ;
}

int	wall_check(char	**map, t_level *l)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\n')
		{
			if (((y == 0 || y == l->max_y) || (x == 0 || x == l->max_x - 1))
				&& map[y][x] != '1')
				return (1);
			++x;
		}
		if (x != l->max_x)
			return (2);
		++y;
	}
	return (0);
}

int	wanderer(char **map, int x, int y, t_level *l)
{
	if (map[y][x] == 'C')
		l->poss_score++;
	else if (map[y][x] == 'E')
		l->poss_exit = 1;
	map[y][x] = 'W';
	if (map[y - 1][x] != '1' && map[y - 1][x] != 'W')
		wanderer(map, x, y - 1, l);
	if (map[y + 1][x] != '1' && map[y + 1][x] != 'W')
		wanderer(map, x, y + 1, l);
	if (map[y][x - 1] != '1' && map[y][x - 1] != 'W')
		wanderer(map, x - 1, y, l);
	if (map[y][x + 1] != '1' && map[y][x + 1] != 'W')
		wanderer(map, x + 1, y, l);
	if ((l->poss_score == l->target_score) && l->poss_exit == 1)
		return (0);
	return (1);
}

char	**cpy_map(char **mapc, char **map, t_level *l)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
		i++;
	mapc = ft_calloc(sizeof(char *), i + 1);
	i = 0;
	while (map[i] != NULL)
	{
		mapc[i] = ft_strdup(map[i]);
		++i;
	}
	return (mapc);
}
