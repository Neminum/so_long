/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsurma <tsurma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:08:36 by tsurma            #+#    #+#             */
/*   Updated: 2024/03/04 20:04:43 by tsurma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	step(t_all *a);
static void	score_increase(t_all *a);
static void	step_increase(t_all *a);


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
	else if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		exit_clean(a, NULL, -1);
	if (a->level->map[a->level->temp_y][a->level->temp_x] == '1')
		return ;
	else if (a->level->temp_y != a->player->y || a->level->temp_x != a->player->x)
		step(a);
}

static int	step(t_all *a)
{
	if (a->player->lt == 'E')
		a->level->map[a->player->y][a->player->x] = 'E';
	else
		a->level->map[a->player->y][a->player->x] = '0';
	put_tile(a->player->y, a->player->x, a);
	a->player->lt = a->level->map[a->level->temp_y][a->level->temp_x];
	a->player->x = a->level->temp_x;
	a->player->y = a->level->temp_y;
	a->level->map[a->player->y][a->player->x] = 'P';
	step_increase(a);
	if (a->player->lt == 'C')
		score_increase(a);
	put_tile(a->player->y, a->player->x, a);
	if (a->player->lt == 'E' && a->player->score == a->level->target_score)
		exit_clean(a, NULL, COMPLETE);
	if (a->player->lt == 'E' && a->player->score != a->level->target_score)
		ft_printf("I need more minerals");
	return (0);
}

static void	score_increase(t_all *a)
{
	a->player->score++;
	if (a->player->score == a->level->target_score)
		ft_printf("My pockets are full, let's move on\n");
}

static void	step_increase(t_all *a)
{
	a->player->steps++;
	ft_printf("%i\n", a->player->steps);
}
