/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_board.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokhapki <aokhapki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 17:13:52 by aokhapki          #+#    #+#             */
/*   Updated: 2024/10/10 18:03:10 by aokhapki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<so_long.h>

void	add_img(t_game *game, int i, int x, int y)
{
	mlx_image_to_window(game->mlx_ptr, (game->text.img)[i], x, y);
}
static void add_wall(t_game *game, char ch, int x, int y)
{
	if(!ch)
		add_img(game,0, x * IMG, y * IMG);
	if (ch == '0')
		add_img(game, 0, x * IMG, y * IMG);
	else if (ch == '1')
		add_img(game, 2, x * IMG, y * IMG);
	else if (ch == 'P')
	{
		add_img(game, 0, x * IMG, y * IMG);
		add_img(game, 1, x * IMG, y * IMG);
		game->player.pos_x = x;
		game->player.pos_y = y;
	}
	else if (ch == 'C')
	{
		add_img(game, 0, x * IMG, y * IMG);
		add_img(game, 4, x * IMG, y * IMG);
		game->map.collectable++;
	}
	else if (ch == 'E')
	{
		add_img(game, 3, x * IMG, y * IMG);
		game->map.pos_exit_x = x;
		game->map.pos_exit_y = y;
	}
}
