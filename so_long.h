/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokhapki <aokhapki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 17:26:49 by aokhapki          #+#    #+#             */
/*   Updated: 2024/10/10 18:01:44 by aokhapki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <stdbool.h>
# include <MLX42/mlx.h>
# include "libft/libft.h"


# define W 13
# define S 1
# define A 0
# define D 2

# define IMG 60

typedef struct s_winsize
{
	int		height;
	int		weight;
}			t_winsize;

typedef	struct s_player
{
	int		pos_x;
	int		pos_y;
	int		step;
	int		trotpy;
}				t_player;

typedef	struct s_map
{
	int		pos_x;
	int		pos_y;
	int		collectable;
	int		pos_exit_x;
	int		pos_exit_y;
	char	**visited;
	char	prev;
	char	**map_ptr;
}				t_map;

typedef struct s_collectable
{
	int		pos_x;
	int		pos_y;
	int		collected;
}		t_collectable;

typedef struct s_game
{
	mlx_t			*mlx_ptr;
	mlx_image_t		*img;
	t_player		player;
	t_mapdata		map;
	t_texture		text;
	t_collectable	*collectables;
	mlx_image_t		*steps_img;
}				t_game;


#endif