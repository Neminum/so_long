/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsurma <tsurma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:50:50 by tsurma            #+#    #+#             */
/*   Updated: 2024/03/04 19:12:10 by tsurma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	wanderer(char **map, int x, int y, t_level *l);
static char	**cpy_map(char **mapc, char **map);
static int	wall_check(t_level *l);


void	find_path(t_all *a)
{
	char	**mapc;
	int		y;
	int		x;

	mapc = NULL;
	x = a->player->x;
	y = a->player->y;
	mapc = cpy_map(mapc, a->level->map);
	if (wall_check(a->level) != 0)
		exit_clean(a, mapc, MWALLS);
	if (wanderer(mapc, x, y, a->level) == 1)
		exit_clean(a, mapc, NOPATH);
	free_map(mapc);
	return ;
}

static int	wall_check(t_level *l)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	while (l->map[y] != NULL)
	{
		x = 0;
		while (l->map[y][x] != '\n')
		{
			if (((y == 0 || y == l->max_y) || (x == 0 || x == l->max_x - 1))
				&& l->map[y][x] != '1')
				return (1);
			++x;
		}
		if (x != l->max_x)
			return (2);
		++y;
	}
	return (0);
}

static int	wanderer(char **map, int x, int y, t_level *l)
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

static char	**cpy_map(char **mapc, char **map)
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
