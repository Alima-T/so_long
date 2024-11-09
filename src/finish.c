/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokhapki <aokhapki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 19:27:36 by aokhapki          #+#    #+#             */
/*   Updated: 2024/11/09 22:57:21 by aokhapki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_temp_map(char **temp_map,int line)
{
	int	i;

	i = 0;
	while (i < line)
	{
		free(temp_map[i]);
		i++;
	}
	free(temp_map);
}

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

void	finish(int exit_code)
{
	if (exit_code != 0)
		ft_printf("Error!\n");
	exit(exit_code);
}

void	finish_game(t_game *game)
{
	free_map(game, game->height_map);
	mlx_delete_image(game->mlx, game->all_images.ground_img);
	mlx_delete_image(game->mlx, game->all_images.wall_img);
	mlx_delete_image(game->mlx, game->all_images.exit_img);
	mlx_delete_image(game->mlx, game->all_images.player_img);
	mlx_delete_image(game->mlx, game->all_images.enemy_img);
	mlx_delete_image(game->mlx, game->win);
	finish(0);
}
