/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokhapki <aokhapki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 17:26:49 by aokhapki          #+#    #+#             */
/*   Updated: 2024/11/14 16:35:28 by aokhapki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "FT_PRINTF/ft_printf.h"
# include "LIBFT/libft.h"
# include "MLX42/include/MLX42/MLX42.h"
# include <fcntl.h>
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_player
{
	int			x;
	int			y;
}				t_player;

typedef struct s_img
{
	mlx_image_t	*ground_img;
	mlx_image_t	*wall_img;
	mlx_image_t	*exit_img;
	mlx_image_t	*player_img;
	mlx_image_t	*enemy_img;
	mlx_image_t	*collectable_img;
}				t_img;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	char		**map;
	int			map_fd;
	int			x;
	int			y;
	int			height_map;
	int			width_map;
	t_player	player;
	mlx_image_t	*img;
	t_img		all_images;
	int			col_count;
	int			steps;
}				t_game;

typedef struct s_flood_fill
{
	int			collectibles;
	bool		exit_found;
}				t_flood_fill;

// init.c
void			init_mlx(t_game *game);
void			init_textures(t_game *game);
void			init_game(t_game *game);
void			set_vars(t_game *game);
void			count_vars(t_game *game, int *player_counter,
					int *exit_counter);
// so_long.c
void			loops(t_game *game);
bool			flood_fill(char **map, int x, int y, t_flood_fill *data);
void			validate_path(t_game *game, int start_x, int start_y,
					int total_collectibles);
// draw.c
void			draw(void *para);
void			draw_map(t_game *game);
void			draw_player(t_game *game);
int				pixel(mlx_image_t *image, uint32_t x, uint32_t y);
void			img_to_img(mlx_image_t *dst, mlx_image_t *src, int x, int y);
// parsing.c
void			map_reader(t_game *game, char *map);
void			fill_real_map(t_game *game, char *reader);
int				is_only_spaces(char *str);
// GNL
char			*get_next_line(int fd);
// control.c
void			keyboard_control(void *parameter);
void			is_key_down(t_game *game, char *c);
void			keep_checking(t_game *game, int new_y, int new_x);
// check.c
void			check_validity(t_game *game);
int				check_walls(t_game *game);
int				check_row_lengths(t_game *game);
int				check_rectangular(t_game *game);
void			check_path(t_game *game, int new_y, int new_x, char c);
// finish.c
void			free_map(t_game *game, int line);
void			finish(int exit_code);
void			finish_game(t_game *game);
void			is_key_down(t_game *game, char *c);
void			free_temp_map(char **temp_map, int line);
#endif
