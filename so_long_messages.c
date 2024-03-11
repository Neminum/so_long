/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_messages.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsurma <tsurma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:01:06 by tsurma            #+#    #+#             */
/*   Updated: 2024/03/11 15:34:14 by tsurma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_mess(t_all *a)
{
	char	*moves;

	moves = ft_itoa(a->player->steps);

	moves = "0";

	mlx_put_string(a->mlx, moves, 10, 10);
	ft_printf("Test\n");
	a->mess->step_count->enabled = 1;
	free(moves);
}
