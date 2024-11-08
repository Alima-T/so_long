/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokhapki <aokhapki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 19:27:36 by aokhapki          #+#    #+#             */
/*   Updated: 2024/11/08 16:33:23 by aokhapki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_map(t_game *game, int line)
{
	int	i;

	i = 0;
	while (i < line)
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
}
void	finish(int exit_code) //0 - success, 1 - unseccess, 2...etc - test failers
{
	if (exit_code != 0) 
		write(1, "Error\n", 6);
	exit(exit_code);
}

void	finish_game(t_game *game)
{
	free_map(game, game->h);
	mlx_delete_image(game->mlx, game->all_images.ground_img);
	mlx_delete_image(game->mlx, game->all_images.wall_img);
	mlx_delete_image(game->mlx, game->all_images.exit_img);
	mlx_delete_image(game->mlx, game->all_images.player_img);
	mlx_delete_image(game->mlx, game->all_images.enemy_img);
	mlx_delete_image(game->mlx, game->win);
	finish(0);
}
