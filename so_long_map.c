/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobias <tobias@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 15:19:58 by tobias            #+#    #+#             */
/*   Updated: 2024/02/16 16:00:10 by tobias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**fetch_map(char **map)
{
	int	fd;
	char *temp;
	int i;

	i = -1;
	temp = NULL;
	fd = open("maps/map_small.ber", O_RDONLY);
	while (i != -2)
	{
		temp = get_next_line(fd);
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

void	map_stats(char **map, t_player *p,  t_level *l)
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
			pos_analyse(map, p, l, x, y);
			x++;
		}
		y++;
	}
	l->max_x = x;
	l->max_y = y - 1;
	if (l->Players > 1)
	{
		ft_printf("Error\nToo many Player spawns.\n");
		exit (0);
	}
	if (l->Exits > 1)
	{
		ft_printf("Error\nToo many Exit spawns.\n");
		exit (0);
	}	
}

void	pos_analyse(char **map, t_player *p, t_level *l, size_t x, size_t y)
{
	if (map[y][x] == 'P' )
	{
		p->x = x;
		p->y = y;
	l->Players++;
	}	
	else if (map[y][x] == 'C')
		l->target_score++;
	else if (map[y][x] == 'E')
		l->Exits++;
}

void	free_map(char **map)
{
	int	i;

	i = -1;
	while (map[++i] != NULL)
		free (map[i]);
	free (map);
}