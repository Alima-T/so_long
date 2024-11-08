/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokhapki <aokhapki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 18:31:54 by aokhapki          #+#    #+#             */
/*   Updated: 2024/11/08 16:28:17 by aokhapki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void check_path(t_game *game, int new_y, int new_x, char c)
{
	if(game->map[new_x][new_y] == 'C')
	{
		game->col_count--;
		game->map[new_x][new_y] = '0';
	}
	if(game->map[new_x][new_y] == '1'
		|| (game->map[new_x][new_y] == 'E' && game->col_count!= 0))
		{
			if (c == 'w')
				game->player.y+=1;
			else if (c == 's')
				game->player.y-=1;
			else if (c == 'a')
				game->player.x+=1;
			else if (c == 'd')
				game->player.x-=1;
			game->steps --;
			return ;
		}	
	if (game->map[new_x][new_y] == 'E' && game->col_count == 0)
		finish(0);
	if (game->map[new_x][new_y] == 'S')
	{
		write(1, "You are eaten by enemy\n", 30);
		finish(0);
	}
}
