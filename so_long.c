/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsurma <tsurma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:28:29 by tsurma            #+#    #+#             */
/*   Updated: 2024/03/11 17:55:31 by tsurma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// static void	print_map_terminal(char **map);


int	main(int argc, char **argv)
{
	static t_player	p;
	static t_level	l;
	static t_tex	t;
	static t_all	a;
	static t_mess	mess;

	argc = 0;
	a.level = &l;
	a.player = &p;
	a.tex = &t;
	a.mlx = NULL;
	a.mess = &mess;
	l.fd = open(argv[1], O_RDONLY);
	if (l.fd == -1)
		exit_clean(&a, NULL, UNKNOWN);
	fetch_map(&a);
	map_stats(&a);
	find_path(&a);
	a.mlx = window(&l);
	load_textures(&a, &t);
	print_map(&a);
	mlx_key_hook(a.mlx, &movement, &a);
	mlx_loop(a.mlx);
	exit_clean(&a, NULL, UNKNOWN);
	return (0);
}

// static void	print_map_terminal(char **map)
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

	mlx = mlx_init(x, y + 20, "Deep Terra", false);
	return (mlx);
}

void	exit_clean(t_all *a, char **mapc, t_errs err)
{
	if (a->mlx != NULL)
		mlx_terminate(a->mlx);
	if (mapc != NULL)
		free_map(mapc);
	if (a->level->map != NULL)
		free_map(a->level->map);
	if (err == COMPLETE)
		ft_printf("The mine grows deeper");
	else if (err == PSPAWNS)
		ft_printf("Error\nInvalid Player Spawns");
	else if (err == ESPAWNS)
		ft_printf("Error\nInvalid Exit Spawns");
	else if (err == MWALLS)
		ft_printf("Error\nInvalid Level Borders");
	else if (err == NOPATH)
		ft_printf("Error\nNo possible path");
	exit(0);
}
