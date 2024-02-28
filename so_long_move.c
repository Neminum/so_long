/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsurma <tsurma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:08:36 by tsurma            #+#    #+#             */
/*   Updated: 2024/02/28 18:29:21 by tsurma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	movement(mlx_key_data_t keydata, void *b)
{
	t_all	*a;

	a = (t_all *)b;
	a->level->temp_x = a->player->x;
	a->level->temp_y = a->player->y;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		a->level->temp_y--;
	else if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		a->level->temp_y++;
	else if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		a->level->temp_x--;
	else if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		a->level->temp_x++;
	if (a->level->map[a->level->temp_y][a->level->temp_x] == '1')
		return ;
	else
		step(a->player, a->level, a);
}

int	step(t_player *p, t_level *l, t_all *a)
{
	if (p->lt == 'E')
		l->map[p->y][p->x] = 'E';
	else
		l->map[p->y][p->x] = '0';
	p->lt = l->map[l->temp_y][l->temp_x];
	p->x = l->temp_x;
	p->y = l->temp_y;
	l->map[p->y][p->x] = 'P';
	p->steps++;
	if (p->lt == 'C')
		p->score++;
	print_map(a->level->map, a->mlx);
	if (p->lt == 'E' && p->score == l->target_score)
		return (1);
	return (0);
}
