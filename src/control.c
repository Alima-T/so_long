/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokhapki <aokhapki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:48:44 by aokhapki          #+#    #+#             */
/*   Updated: 2024/11/07 20:12:09 by aokhapki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void keyboard_control(void *parameter)
{
	t_game *game;

	game = parameter;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		exit(1);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_W))
	{
		game->player.y-=1;
		usleep(100000);
	}
	else if (mlx_is_key_down(game->mlx, MLX_KEY_S))
	{
		game->player.y+=1;
		usleep(100000);
	}
	else if (mlx_is_key_down(game->mlx, MLX_KEY_A))
	{
		game->player.x-=1;
		usleep(100000);
	}
	else if (mlx_is_key_down(game->mlx, MLX_KEY_D))
	{
		game->player.x+=1;
		usleep(100000);
	}
}