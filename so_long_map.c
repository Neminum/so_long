/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsurma <tsurma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 15:19:58 by tobias            #+#    #+#             */
/*   Updated: 2024/02/19 14:01:27 by tsurma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**fetch_map(char **map, t_level *l)
{
	char	*temp;
	int		i;

	i = -1;
	temp = NULL;

	while (i != -2)
	{
		temp = get_next_line(l->fd);
		if (temp == NULL)
			break ;
		map = ft_pointjoin(map, temp);
	}
	return (map);
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
	ret[i] = src;
	if (dest != NULL)
		while (--i >= 0)
			ret[i] = dest[i];
	free(dest);
	return (ret);
}

int	map_stats(char **map, t_player *p, t_level *l)
{
	while (map[l->temp_y] != NULL)
	{
		l->temp_x = 0;
		while (map[l->temp_y][l->temp_x] != '\n')
		{
			pos_analyse(map, p, l);
			l->temp_x++;
		}
		l->temp_y++;
	}
	l->max_x = l->temp_x;
	l->max_y = l->temp_y - 1;
	if (l->exits != 1)
	{
		ft_printf("Error\nInvalid exit spawns\n");
		free_map(map);
		exit (0);
	}
	return (0);
}

void	pos_analyse(char **map, t_player *p, t_level *l)
{
	if (map[l->temp_y][l->temp_x] == '1' || (map[l->temp_y][l->temp_x] == '0'))
		return ;
	else if (map[l->temp_y][l->temp_x] == 'P')
	{
		if (p->x != 0 || p->y != 0)
		{
			ft_printf("Error\nToo many player spawns\n");
			free_map(map);
			exit (0);
		}
		p->x = l->temp_x;
		p->y = l->temp_y;
	}
	else if (map[l->temp_y][l->temp_x] == 'C')
		l->target_score++;
	else if (map[l->temp_y][l->temp_x] == 'E')
		l->exits++;
}

void	free_map(char **map)
{
	int	i;

	i = -1;
	while (map[++i] != NULL)
		free (map[i]);
	free (map);
}
