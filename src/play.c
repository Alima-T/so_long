/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokhapki <aokhapki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 18:31:54 by aokhapki          #+#    #+#             */
/*   Updated: 2024/11/04 16:49:09 by aokhapki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"


int key_press (t_game *game,int key)
{
	if(key == MLX_KEY_ESCAPE)
		finish(1); //change 
	if(key == MLX_KEY_W || key == MLX_KEY_S || key == MLX_KEY_A || key == MLX_KEY_D)
		go_player(game, key);
	return(0);
}

int check_path(t_game *game, int move_x, int move_y)
{
	int new_x = game->x + move_x;
	int new_y = game->y + move_y;
	
	if(game->map[new_x][new_y] == 'C')
	{
		game->all_images.collectable_img--;
		game->map[new_x][new_y] = '0';
	}
	if(game->map[new_x][new_y] == '1'
		|| (game->map[new_x][new_y] == 'E' && game->all_images.collectable_img != 0))
		return (0);
	if(game->map[new_x][new_y] == 'E' && game->all_images.collectable_img == 0)
		draw_img(game, game->all_images.player_img, game->x, game->y);
		return (1); //change
}

void go_player(t_game *game, int key)
{	
	int n = 0;
	if(key == MLX_KEY_W && check_path(game, 0, 1))
	{
		draw_img(game, game->all_images.ground_img, game->x, game->y);
		draw_img(game, game->all_images.player_img, game->x, game->y+1);
	}
		if(key == MLX_KEY_S && check_path(game, 0, -1))
	{
		draw_img(game, game->all_images.ground_img, game->x, game->y);
		draw_img(game, game->all_images.player_img, game->x, game->y-1);
	}
		if(key == MLX_KEY_A && check_path(game, -1, 0))
	{
		draw_img(game, game->all_images.ground_img, game->x, game->y);
		draw_img(game, game->all_images.player_img, game->x-1, game->y);
	}
		if(key == MLX_KEY_D && check_path(game, 1, 0))
	{
		draw_img(game, game->all_images.ground_img, game->x, game->y);
		draw_img(game, game->all_images.player_img, game->x+1, game->y);
	}
	n++;
	write(1, &n, 1);
}
