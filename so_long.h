/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokhapki <aokhapki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 17:26:49 by aokhapki          #+#    #+#             */
/*   Updated: 2024/11/04 16:51:26 by aokhapki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "LIBFT/libft.h"
# include "MLX42/include/MLX42/MLX42.h"

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <fcntl.h>

// # define ESC 53
// # define UP_KEY 126
// # define DOWN_KEY 125
// # define RIGHT_KEY 124
// # define LEFT_KEY 123

// # define KEY_ESCAPE 53

// # define W 13
// # define S 1
// # define A 0
// # define D 2

typedef struct s_map
{
	int	start_position;
	int	collectible;
	int	wall;
	int	exit;
	int	is_valid;
}	t_map;

typedef struct s_image
{
	void	*img;
	int		h;
	int		w;
}	t_image;

typedef struct s_img
{
	mlx_image_t *ground_img;
	mlx_image_t *wall_img;
	mlx_image_t *exit_img;
	mlx_image_t *player_img;
	mlx_image_t *enemy_img;
	mlx_image_t *collectable_img;
}		 t_img;


typedef struct s_game
{
	void		*mlx;
	void		*win;
	char		**map;
	int			map_fd;
	int			x;
	int			y;
	int			h;
	int			w;
	int			height_map;
	t_map		map_again;
	mlx_image_t *img;
	t_img		all_images;
}			t_game;

// init.c
int 	init_mlx(t_game *game);
// so_long.c
void    loops(t_game *game);
// draw.c
void 	draw(void *para);
void	draw_map(t_game *game);
void	draw_img(t_game *game, mlx_image_t *img, int j, int i);
// parsing.c
void    map_reader(t_game *game, char *map);
void    fill_real_map(t_game *game, char *reader);
int 	is_only_spaces(char *str);
// GNL
char	*get_next_line(int fd);
// play.c
int		key_press (t_game *game,int key);
// int		mouse_exit(void);
int		check_path(t_game *game, int move_x, int move_y);
void	go_player(t_game *game, int key);
// finish.c
void	free_map(t_game *game, int line);
void	finish(int exit_code);
// void	finish_game(t_game *game);
#endif