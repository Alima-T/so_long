/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokhapki <aokhapki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:48:44 by aokhapki          #+#    #+#             */
/*   Updated: 2024/11/10 20:34:05 by aokhapki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	keyboard_control(void *parameter)
{
	t_game	*game;
	char	c;
	int		i;

	i = 0;
	c = '\0';
	game = parameter;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
	{
		finish_game(game);
	}
	is_key_down(game, &c);
	while (i < 70000000)
		i++;
}

void	is_key_down(t_game *game, char *c)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
	{
		game->player.y -= 1;
		*c = 'w';
		check_path(game, game->player.x, game->player.y, *c);
	}
	else if (mlx_is_key_down(game->mlx, MLX_KEY_S))
	{
		game->player.y += 1;
		*c = 's';
		check_path(game, game->player.x, game->player.y, *c);
	}
	else if (mlx_is_key_down(game->mlx, MLX_KEY_A))
	{
		game->player.x -= 1;
		*c = 'a';
		check_path(game, game->player.x, game->player.y, *c);
	}
	else if (mlx_is_key_down(game->mlx, MLX_KEY_D))
	{
		game->player.x += 1;
		*c = 'd';
		check_path(game, game->player.x, game->player.y, *c);
	}
}

void	keep_checking(t_game *game, int new_y, int new_x)
{
	if (game->map[new_x][new_y] == 'E' && game->col_count == 0)
	{
		printf("Step number: %d \n", game->steps);
		ft_printf("Congratulations, You Won!!!\n");
		finish_game(game);
	}
	if (game->map[new_x][new_y] == 'S')
	{
		printf("Step number: %d \n", game->steps);
		ft_printf("You are eaten by enemy\n");
		finish_game(game);
	}
	printf("Step number: %d \n", game->steps);
}
