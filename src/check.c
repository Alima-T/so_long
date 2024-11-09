/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokhapki <aokhapki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 18:11:30 by aokhapki          #+#    #+#             */
/*   Updated: 2024/11/09 22:48:22 by aokhapki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_validity(t_game *game)
{
	check_row_lengths(game);
	check_walls(game);
}

void	check_walls(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < game->width_map)
	{
		if (game->map[0][x] != '1' ||
			game->map[game->height_map - 1][x++] != '1')
			{
				ft_printf("Map not sourrounded by walls!\n");
				finish_game(game);
			}
	}
	while (y < game->height_map)
	{
		if (game->map[y][0] != '1' ||
			game->map[y++][game->width_map - 1] != '1')
			{
				ft_printf("Map not sourrounded by walls!\n");
				finish_game(game);
			}
	}
}

void	check_row_lengths(t_game *game)
{
	int	expected_length;
	int	y;
	
	expected_length = ft_strlen(game->map[0]);
	y = 1;
	while (y < game->height_map -1)
	{
		if ((int)ft_strlen(game->map[y]) != expected_length)
		{
			ft_printf("Map rows are not the same length.\n");
			finish_game(game);
		}
		y++;
	}
}

void check_path(t_game *game, int new_y, int new_x, char c)
{
	game->steps++;
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
		game->steps--;
		return ;
	}
	keep_checking(game, new_y, new_x);
}

void	keep_checking(t_game *game, int new_y, int new_x)
{
	if (game->map[new_x][new_y] == 'E' && game->col_count == 0)
	{
		ft_printf("Congratulations, You Won!!!\n");
		finish_game(game);
	}
	if (game->map[new_x][new_y] == 'S')
	{
		ft_printf("You are eaten by enemy\n");
		finish_game(game);
	}
	printf("%d \n",game->steps);
}
