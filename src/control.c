/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokhapki <aokhapki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:48:44 by aokhapki          #+#    #+#             */
/*   Updated: 2024/11/08 16:34:42 by aokhapki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void keyboard_control(void *parameter)
{
	t_game *game;
	char c;

	c = '1';
	game = parameter;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
			finish_game(game);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_W))
	{
		c = 'w';
		game->player.y-=1;
		game->steps++;
		printf("Steps count: %d\n", game->steps);
	}
	else if (mlx_is_key_down(game->mlx, MLX_KEY_S))
	{
		c = 's';
		game->player.y+=1;
		game->steps++;
		printf("Steps count: %d\n", game->steps);
	}
	else if (mlx_is_key_down(game->mlx, MLX_KEY_A))
	{
		c = 'a';
		game->player.x-=1;
		game->steps++;
		printf("Steps count: %d\n", game->steps);

	}
	else if (mlx_is_key_down(game->mlx, MLX_KEY_D))
	{
		c = 'd';
		game->player.x+=1;
		game->steps++;
		printf("Steps count: %d\n", game->steps);
	}
	usleep(70000);
	check_path(game, game->player.x, game->player.y, c);
}
