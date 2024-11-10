/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokhapki <aokhapki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 17:28:30 by aokhapki          #+#    #+#             */
/*   Updated: 2024/11/10 20:15:46 by aokhapki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

bool	flood_fill(char **map, int x, int y, t_flood_fill *data)
{
	if (map[y][x] == '1' || map[y][x] == 'V')
		return (false);
	if (map[y][x] == 'C')
		data->collectibles--;
	if (map[y][x] == 'E')
		data->exit_found = true;
	map[y][x] = 'V';
	flood_fill(map, x + 1, y, data);
	flood_fill(map, x - 1, y, data);
	flood_fill(map, x, y + 1, data);
	flood_fill(map, x, y - 1, data);
	return (true);
}

void	validate_path(t_game *game, int start_x, int start_y,
		int total_collectibles)
{
	t_flood_fill	data;
	char			**temp_map;
	int				i;

	temp_map = malloc(sizeof(char *) * game->height_map);
	if (!temp_map)
		finish_game(game);
	i = -1;
	while (++i < game->height_map)
		temp_map[i] = ft_strdup(game->map[i]);
	data.collectibles = total_collectibles;
	data.exit_found = false;
	flood_fill(temp_map, start_x, start_y, &data);
	if (!(data.collectibles == 0 && data.exit_found))
	{
		ft_printf("Error! Invalid path.\n");
		free_temp_map(temp_map, game->height_map);
		finish_game(game);
	}
	free_temp_map(temp_map, game->height_map);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (1);
	init_game(&game);
	map_reader(&game, argv[1]);
	check_validity(&game);
	init_mlx(&game);
	set_vars(&game);
	validate_path(&game, game.player.x, game.player.y, game.col_count);
	loops(&game);
	finish_game(&game);
	return (0);
}

void	loops(t_game *game)
{
	mlx_loop_hook(game->mlx, draw, game);
	mlx_loop_hook(game->mlx, keyboard_control, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
}
