/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsurma <tsurma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:28:29 by tsurma            #+#    #+#             */
/*   Updated: 2024/02/19 17:47:44 by tsurma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	static t_player	p;
	static t_level	l;
	char			**map;

	l.fd = open("maps/map_small.ber", O_RDONLY);
	map = NULL;
	map = fetch_map(map, &l);
	map_stats(map, &p, &l);
	find_path(&l, &p, map);

	void	*mlx;

	mlx = mlx_init(1920, 1080, "Test", true);
	mlx_loop(mlx);



	free_map(map);
	return (0);
}

void	print_map_terminal(char **map)
{
	int	i;

	i = -1;
	while (map[++i] != NULL)
		ft_printf("%s", map[i]);
}

int	movement(char **map, t_level *l, t_player *p, char key)
{
	int	x;
	int	y;

	x = p->x;
	y = p->y;
	if (key == 'W')
		--y;
	else if (key == 'S')
		++y;
	else if (key == 'A')
		--x;
	else if (key == 'D')
		++x;
	if (map[y][x] == '1')
		return (-1);
	if (p->lt == 'E')
		map[p->y][p->x] = 'E';
	else
		map[p->y][p->x] = '0';
	p->lt = map[y][x];
	p->x = x;
	p->y = y;
	map[p->y][p->x] = 'P';
	p->steps++;
	if (p->lt == 'C')
		p->score++;
	else if (p->lt == 'E' && p->score >= l->target_score)
		return (1);
	return (0);
}
