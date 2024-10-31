/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokhapki <aokhapki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 17:28:30 by aokhapki          #+#    #+#             */
/*   Updated: 2024/10/31 20:16:32 by aokhapki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int 	init_mlx(t_game *game);
void    loops(t_game *game);
void 	draw(void *para);
void	draw_doors(t_game *game);

int	main(void)
{
	t_game game;
	init_mlx(&game);
	loops(&game);
	return (0);
}
int init_mlx(t_game *game)
{
    game->mlx = mlx_init(1440, 960, "CUB3D", false);
    if (!game->mlx)
        return (1);
    game->img = mlx_new_image(game->mlx, 1440, 960);
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
	mlx_texture_t *temp =  mlx_load_png("textures/exit.png");
	game->all_images.door_img = mlx_texture_to_image(game->mlx, temp);
	// game->all_images.player_img = mlx_texture_to_image(game->mlx, temp);
    return (0);
}

void    loops(t_game *game)
{
    mlx_loop_hook(game->mlx, draw, game);
    mlx_loop(game->mlx);
    mlx_terminate(game->mlx);
}

void draw(void *para)
{
	//draw_map();
	//draw_player();
	t_game *game;
	game = para;
	draw_doors(game);
	int i;
	int j;

	i = 0;
	while ( i < 64)
	{
		j = 0;
		while (j < 64)
		{
			mlx_put_pixel(game->img, i , j, 123456);
			j++;
		}
		i++;
	}
}
void	draw_doors(t_game *game)
{
	mlx_image_to_window(game->mlx, game->all_images.door_img, 150, 200);
}

