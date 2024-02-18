/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobias <tobias@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:28:29 by tsurma            #+#    #+#             */
/*   Updated: 2024/02/16 16:09:22 by tobias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	int				i;
	char			**map;
	static t_player	p;
	static t_level	l;
	void	*img;
	void	*mlx;

	map = NULL;
	map = fetch_map(map);
	map_stats(map, &p, &l);
	mlx = mlx_init(1920, 1080, "test", true);
	img = mlx_new_image(mlx, 1920, 1080);


	i = -1;
	while (map[++i] != NULL)
		ft_printf("%s", map[i]);
	ft_printf("%d\n", p.steps);

	free_map(map);
	return (0);
}

void	movement(char **map, t_level *l, t_player *p, char key)
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
		return;
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
	{
		ft_printf("Conglaturations");
		exit (0);
	}
	return ;
}
