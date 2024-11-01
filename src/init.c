/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokhapki <aokhapki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 21:10:45 by aokhapki          #+#    #+#             */
/*   Updated: 2024/11/01 23:09:55 by aokhapki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int init_mlx(t_game *game)
{
    game->mlx = mlx_init(2000, 1800, "SO_LONG", false);
    if (!game->mlx)
        return (1);
    game->img = mlx_new_image(game->mlx, 2000, 1800);
    if (!game->img)
    {
        mlx_close_window(game->mlx);
        return (1);
    }
    if (mlx_image_to_window(game->mlx, game->img, 0, 0) == -1)
    {
        mlx_close_window(game->mlx);
        return (1);
    }
	mlx_texture_t *temp_texture =  mlx_load_png("images/exit.png");
	game->all_images.exit_img = mlx_texture_to_image(game->mlx, temp_texture);
	temp_texture =  mlx_load_png("images/player.png");
	game->all_images.player_img = mlx_texture_to_image(game->mlx, temp_texture);
	temp_texture =  mlx_load_png("images/ground.png");
	game->all_images.ground_img = mlx_texture_to_image(game->mlx, temp_texture);
	temp_texture =  mlx_load_png("images/wall.png");
	game->all_images.wall_img = mlx_texture_to_image(game->mlx, temp_texture);
	temp_texture =  mlx_load_png("images/enemy.png");
	game->all_images.enemy_img = mlx_texture_to_image(game->mlx, temp_texture);
	temp_texture =  mlx_load_png("images/honey.png");
	game->all_images.collectable_img = mlx_texture_to_image(game->mlx, temp_texture);
    return (0);
}