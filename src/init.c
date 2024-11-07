/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokhapki <aokhapki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 21:10:45 by aokhapki          #+#    #+#             */
/*   Updated: 2024/11/07 20:33:52 by aokhapki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int init_mlx(t_game *game)
{
    game->mlx = mlx_init(1000, 1000, "SO_LONG", false);
    if (!game->mlx)
        return (1);
    game->img = mlx_new_image(game->mlx, 1000, 1000);
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

void	init_game(t_game *game)
{
	game->col_count = 0;
	game->map_fd = 0;
	game->x = 0;
	game->y = 0;
	game->h = 0;
	game->w = 0;
	game->height_map = 0;

	
}

void set_vars(t_game *game)
{
	int		i;
	int		j;
	
	i = 0;
	while (i < game->height_map)
	{
		j = 0;
		while (j < (int)ft_strlen(game->map[i]))
		{
			if (game->map[i][j] == 'P')
			{
				game->player.y = i;
				game->player.x = j;
			}
			else if (game->map[i][j] == 'C')
				game->col_count++;
			j++;
		}
		i++;
	}
}
