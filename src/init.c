/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokhapki <aokhapki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 21:10:45 by aokhapki          #+#    #+#             */
/*   Updated: 2024/11/10 15:28:10 by aokhapki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_mlx(t_game *game)
{
	game->mlx = mlx_init(game->width_map * 45 + 2, game->height_map * 45 + 2,
			"SO_LONG", false);
	if (!game->mlx)
		finish_game(game);
	game->img = mlx_new_image(game->mlx, game->width_map * 45 + 2,
			game->height_map * 45 + 2);
	if (!game->img)
	{
		mlx_close_window(game->mlx);
		finish_game(game);
	}
	if (mlx_image_to_window(game->mlx, game->img, 0, 0) == -1)
	{
		mlx_close_window(game->mlx);
		finish_game(game);
	}
	init_textures(game);
}

void	init_textures(t_game *game)
{
	mlx_texture_t	*temp_texture;

	temp_texture = mlx_load_png("images/exit.png");
	game->all_images.exit_img = mlx_texture_to_image(game->mlx, temp_texture);
	temp_texture = mlx_load_png("images/player.png");
	game->all_images.player_img = mlx_texture_to_image(game->mlx, temp_texture);
	temp_texture = mlx_load_png("images/ground.png");
	game->all_images.ground_img = mlx_texture_to_image(game->mlx, temp_texture);
	temp_texture = mlx_load_png("images/wall.png");
	game->all_images.wall_img = mlx_texture_to_image(game->mlx, temp_texture);
	temp_texture = mlx_load_png("images/enemy.png");
	game->all_images.enemy_img = mlx_texture_to_image(game->mlx, temp_texture);
	temp_texture = mlx_load_png("images/honey.png");
	game->all_images.collectable_img = mlx_texture_to_image(game->mlx,
			temp_texture);
}

void	init_game(t_game *game)
{
	game->map_fd = 0;
	game->x = 0;
	game->y = 0;
	game->height_map = 0;
	game->width_map = 0;
	game->col_count = 0;
	game->steps = 0;
}

void	set_vars(t_game *game)
{
	int	player_counter;
	int	exit_counter;

	player_counter = 0;
	exit_counter = 0;
	count_vars(game, &player_counter, &exit_counter);
	if (player_counter != 1 || exit_counter != 1 || game->col_count < 1)
	{
		ft_printf("Not correct number of player, or exit or collectibles\n");
		finish_game(game);
	}
}

void	count_vars(t_game *game, int *player_counter, int *exit_counter)
{
	int	i;
	int	j;

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
				*player_counter += 1;
			}
			else if (game->map[i][j] == 'C')
				game->col_count++;
			else if (game->map[i][j] == 'E')
				*exit_counter += 1;
			j++;
		}
		i++;
	}
}
