/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokhapki <aokhapki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 21:05:39 by aokhapki          #+#    #+#             */
/*   Updated: 2024/11/10 18:53:37 by aokhapki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	map_reader(t_game *game, char *map)
{
	char	*reader;

	if (ft_strlen(map) <= 4 || ft_strncmp(map + (ft_strlen(map) - 4), ".ber",
			4))
	{
		ft_printf("Error! Map's name is not correct.\n");
		exit(EXIT_FAILURE);
	}
	game->map_fd = open(map, O_RDONLY);
	if (game->map_fd < 0)
	{
		ft_printf("Error! Couldn't load the map!\n");
		exit(EXIT_FAILURE);
	}
	reader = get_next_line(game->map_fd);
	while (is_only_spaces(reader) == 0)
	{
		free(reader);
		reader = get_next_line(game->map_fd);
	}
	fill_real_map(game, reader);
}

void	fill_real_map(t_game *game, char *reader)
{
	int	y;

	y = 0;
	game->map = ft_calloc(200, sizeof(char *));
	game->width_map = ft_strlen(reader) - 1;
	while (reader != NULL)
	{
		game->height_map++;
		game->map[y] = ft_strdup(reader);
		free(reader);
		reader = get_next_line(game->map_fd);
		y++;
		if (reader != NULL && is_only_spaces(reader) == 0)
		{
			free(reader);
			game->map[y] = NULL;
			break ;
		}
	}
}

int	is_only_spaces(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '\n')
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
			return (1);
		i++;
	}
	return (0);
}
