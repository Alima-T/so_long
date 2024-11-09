/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokhapki <aokhapki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 17:28:30 by aokhapki          #+#    #+#             */
/*   Updated: 2024/11/09 22:56:11 by aokhapki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

bool flood_fill(char **map, int x, int y, int *collectibles, bool *exit_found)
{
    if (map[y][x] == '1' || map[y][x] == 'V')
		return false;  // '1' is wall, 'V' is visited
    if (map[y][x] == 'C')
		(*collectibles)--; 
    if (map[y][x] == 'E')
		*exit_found = true; 
    map[y][x] = 'V';  
    flood_fill(map, x + 1, y, collectibles, exit_found);
    flood_fill(map, x - 1, y, collectibles, exit_found);
    flood_fill(map, x, y + 1, collectibles, exit_found);
    flood_fill(map, x, y - 1, collectibles, exit_found);
    return true;
}

void validate_path(t_game *game/*char **map*/, int start_x, int start_y, int total_collectibles)
{
	int collectibles;
	bool exit_found;
	char **temp_map;
	int	i;
	
	temp_map = malloc(sizeof(char *) * game->height_map);
	if (!temp_map)
		finish_game(game);
	i = -1;
	while (++i < game->height_map)
		temp_map[i] = ft_strdup(game->map[i]);
	collectibles = total_collectibles;
	exit_found = false;	
	flood_fill(temp_map, start_x, start_y, &collectibles, &exit_found);	
	if (!(collectibles == 0 && exit_found))
	{
		ft_printf("Invalid paht\n");
		free_temp_map(temp_map, game->height_map);
		finish_game(game);
	}
	free_temp_map(temp_map, game->height_map);
}

int	main(int argc, char **argv)
{
	t_game game;
	
	if(argc != 2)
		return(1);
	init_game(&game);
	map_reader(&game, argv[1]);
	check_validity(&game);
	init_mlx(&game);
	set_vars(&game); // later
	validate_path(&game/*temp_map*/, game.player.x, game.player.y, game.col_count);
	loops(&game);
	finish_game(&game); // if someone clicked on X the game must exit in a clean way
	return (0);
}

void	loops(t_game *game)
{
	mlx_loop_hook(game->mlx, draw, game);
	mlx_loop_hook(game->mlx, keyboard_control, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
}
