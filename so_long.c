/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsurma <tsurma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:28:29 by tsurma            #+#    #+#             */
/*   Updated: 2024/02/28 18:24:49 by tsurma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	static t_player	p;
	static t_level	l;
	static t_all	a;


	a.level = &l;
	a.player = &p;
	a.mlx = NULL;
	l.fd = open("maps/map_small.ber", O_RDONLY);

	fetch_map(&l);
	map_stats(&p, &l);
	find_path(&l, &p);
	a.mlx = window(&l);

	mlx_key_hook(a.mlx, &movement, &a);
	print_map(l.map, a.mlx);
	mlx_loop(a.mlx);
	free_map(l.map);
	mlx_terminate(a.mlx);
	return (0);
}

// void	print_map_terminal(char **map)
// {
// 	int	i;

// 	i = -1;
// 	while (map[++i] != NULL)
// 		ft_printf("%s", map[i]);
// }

void	*window(t_level *l)
{
	void		*mlx;
	int			x;
	int			y;
	int			multiplier;

	multiplier = 50;
	x = (l->max_x) * multiplier;
	y = (l->max_y + 1) * multiplier;

	mlx = mlx_init(x, y, "Deep Terra", false);
	return (mlx);
}
