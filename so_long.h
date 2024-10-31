/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokhapki <aokhapki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 17:26:49 by aokhapki          #+#    #+#             */
/*   Updated: 2024/10/31 20:15:57 by aokhapki         ###   ########.fr       */
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

# define KEY_ESCAPE 53

# define W 13
# define S 1
# define A 0
# define D 2

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

typedef struct s_textures
{
	t_image	ground;
	t_image	wall;
	t_image	exit1;
	t_image	exit2;
	t_image	player;
	t_image	enemy;
	int		collectable;
}			t_textures;

typedef struct s_img
{
	mlx_image_t *door_img;
	mlx_image_t *ground_img;
	mlx_image_t *wall_img;
	mlx_image_t *exit1_img;
	mlx_image_t *player_img;
	mlx_image_t *enemy_img;
}		 t_img;


typedef struct s_info
{
	void		*mlx;
	void		*win;
	char		**map;
	int			x;
	int			y;
	int			h;
	int			w;
	mlx_image_t *img;
	t_img		all_images;
}	t_game;

int 	init_mlx(t_game *game);
void    loops(t_game *game);
void 	draw(void *para);
void	draw_doors(t_game *game);

char		*get_next_line(int fd);
#endif