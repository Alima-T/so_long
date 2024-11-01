/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokhapki <aokhapki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 17:28:30 by aokhapki          #+#    #+#             */
/*   Updated: 2024/11/02 00:37:23 by aokhapki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	main(int argc, char **argv)
{
	if(argc != 2)
		return(1);
	t_game game;
	init_mlx(&game);
	map_reader(&game, argv[1]);
	loops(&game);
	return (0);
}

void    loops(t_game *game)
{
    mlx_loop_hook(game->mlx, draw, game);
    mlx_loop(game->mlx);
    mlx_terminate(game->mlx);
}

