/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokhapki <aokhapki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 21:10:09 by aokhapki          #+#    #+#             */
/*   Updated: 2024/11/02 00:37:51 by aokhapki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void draw(void *param)
{
	t_game *game;
	game = param;
	draw_map(game);
}

void	draw_img(t_game *game, mlx_image_t *img, int j, int i)
{
	mlx_image_to_window(game->mlx, img, j * img->height, i * img->width);
}
void	draw_map(t_game *game)
{
	int		i;
	int		j;
	
	i = 0;
	while (i < game->height_map)
	{
		j = 0;
		while (j < (int)ft_strlen(game->map[i]))
		{
			if (game->map[i][j] == '1')	
				draw_img(game, game->all_images.wall_img, j, i);
			else if (game->map[i][j] == 'E')
				draw_img(game, game->all_images.exit_img, j, i);
			else if (game->map[i][j] == '0')
				draw_img(game, game->all_images.ground_img, j, i);
			else if (game->map[i][j] == 'P')
				draw_img(game, game->all_images.player_img, j, i);
			else if (game->map[i][j] == 'C')
				draw_img(game, game->all_images.collectable_img, j, i);
			else if (game->map[i][j] == 'S')
				draw_img(game, game->all_images.enemy_img, j, i);
			j++;
		}
		i++;
	}
}
