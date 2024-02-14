/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsurma <tsurma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:28:29 by tsurma            #+#    #+#             */
/*   Updated: 2024/02/14 18:23:56 by tsurma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	int				i;
	int				fd;
	char			*temp;
	char			**map;
	static t_player	p;

	temp = NULL;
	map = NULL;
	fd = open("maps/map_small.ber", O_RDONLY);
	i = -1;
	while (i != -2)
	{
		temp = get_next_line(fd);
		if (temp == NULL)
			break ;
		map = ft_pointjoin(map, temp);
	}
	i = -1;
	find_player(map, &p);
	movement(map, &p, 'w');
	movement(map, &p, 'd');
	movement(map, &p, 'd');
	movement(map, &p, 'd');
	movement(map, &p, 'w');
	movement(map, &p, 'd');
	movement(map, &p, 'd');
	movement(map, &p, 'd');
	movement(map, &p, 'd');
	movement(map, &p, 'd');
	movement(map, &p, 'd');
	movement(map, &p, 'd');
	movement(map, &p, 's');
	movement(map, &p, 's');
	movement(map, &p, 'a');
	movement(map, &p, 'a');
	movement(map, &p, 'a');
	movement(map, &p, 'a');
	movement(map, &p, 'a');
	while (map[++i] != NULL)
		ft_printf("%s", map[i]);
	ft_printf("%d", p.score);
	i = -1;
	while (map[++i] != NULL)
		free (map[i]);
	free (map);
	return (0);
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

void	find_player(char **map, t_player *p)
{
	while (map[p->y] != NULL)
	{
		while (map[p->y][p->x] != '\0')
		{
			if (map[p->y][p->x] == 'P')
				return ;
			p->x++;
		}
		p->x = 0;
		p->y++;
	}
	ft_printf("Error\nCan\'t find Player\n");
	exit (0);
}

void	movement(char **map, t_player *p, char key)
{
	if (key == 'w' && map[p->y - 1][p->x] != '1')
	{
		p->lt = map[p->y - 1][p->x];
		map[p->y][p->x] = '0';
		p->y--;
		map[p->y][p->x] = 'P';
	}
	else if (key == 's' && map[p->y + 1][p->x] != '1')
	{
		p->lt = map[p->y + 1][p->x];
		map[p->y][p->x] = '0';
		p->y++;
		map[p->y][p->x] = 'P';
	}
	else if (key == 'd' && map[p->y][p->x + 1] != '1')
	{
		p->lt = map[p->y][p->x + 1];
		map[p->y][p->x] = '0';
		p->x++;
		map[p->y][p->x] = 'P';
	}
	else if (key == 'a' && map[p->y][p->x - 1] != '1')
	{
		p->lt = map[p->y][p->x - 1];
		map[p->y][p->x] = '0';
		p->x--;
		map[p->y][p->x] = 'P';
	}
	p->steps++;
	if (p->lt == 'C')
		p->score++;
	else if (p->lt == 'E' && p->score >= 1)
	{
		ft_printf("Conglaturations");
		exit (0);
	}
	return ;
}
