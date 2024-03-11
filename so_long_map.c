/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsurma <tsurma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 15:19:58 by tobias            #+#    #+#             */
/*   Updated: 2024/03/11 18:05:10 by tsurma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	pos_analyse(t_player *p, t_level *l);

void	fetch_map(t_all *a)
{
	char	*temp;
	int		i;

	i = -1;
	temp = NULL;
	while (i != -2)
	{
		temp = get_next_line(a->level->fd);
		if (temp == NULL)
			break ;
		a->level->map = ft_pointjoin(a->level->map, temp);
		if (a->level->map == NULL)
			exit_clean(a, NULL, UNKNOWN);
	}
}

char	**ft_pointjoin(char **dest, char *src)
{
	char	**ret;
	int		i;
	int		j;

	if (!src)
		exit (0);
	i = 0;
	j = -1;
	if (dest != NULL)
	{
		while (dest[i] != NULL)
			++i;
	}
	ret = ft_calloc(sizeof(char *), i + 2);
	if (!ret)
		return (NULL);
	ret[i] = src;
	if (dest != NULL)
		while (--i >= 0)
			ret[i] = dest[i];
	free(dest);
	return (ret);
}

int	map_stats(t_all *a)
{
	while (a->level->map[a->level->temp_y] != NULL)
	{
		a->level->temp_x = 0;
		while (a->level->map[a->level->temp_y][a->level->temp_x] != '\n')
		{
			if (pos_analyse(a->player, a->level) == -1)
				exit_clean(a, NULL, PSPAWNS);
			a->level->temp_x++;
		}
		a->level->temp_y++;
	}
	a->level->max_x = a->level->temp_x;
	a->level->max_y = a->level->temp_y - 1;
	if (a->level->exits != 1)
		exit_clean(a, NULL, ESPAWNS);
	if (a->level->target_score == 0)
		exit_clean(a, NULL, UNKNOWN);
	return (0);
}

static int	pos_analyse(t_player *p, t_level *l)
{
	if (l->map[l->temp_y][l->temp_x] == '1' ||
		(l->map[l->temp_y][l->temp_x] == '0'))
		return (0);
	else if (l->map[l->temp_y][l->temp_x] == 'P')
	{
		if (p->x != 0 || p->y != 0)
			return (-1);
		p->x = l->temp_x;
		p->y = l->temp_y;
	}
	else if (l->map[l->temp_y][l->temp_x] == 'C')
		l->target_score++;
	else if (l->map[l->temp_y][l->temp_x] == 'E')
		l->exits++;
	return (0);
}

void	free_map(char **map)
{
	int	i;

	i = -1;
	while (map[++i] != NULL)
		free (map[i]);
	free (map);
}
