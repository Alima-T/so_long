/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aokhapki <aokhapki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 21:10:09 by aokhapki          #+#    #+#             */
/*   Updated: 2024/11/14 16:35:39 by aokhapki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	draw(void *param)
{
	t_game	*game;

	game = param;
	draw_map(game);
	draw_player(game);
}

int	pixel(mlx_image_t *image, uint32_t x, uint32_t y)
{
	int		r;
	int		g;
	int		b;
	int		a;
	uint8_t	*pixel;

	if (x > image->width || y > image->height)
		return (0xFF000000);
	pixel = image->pixels + (y * image->width + x) * sizeof(uint32_t);
	r = pixel[0];
	g = pixel[1];
	b = pixel[2];
	a = pixel[3];
	if (a == 0)
		return (-1);
	return (r << 24 | g << 16 | b << 8 | a);
}

void	img_to_img(mlx_image_t *dst, mlx_image_t *src, int x, int y)
{
	uint32_t	i;
	uint32_t	j;
	int			color;

	x *= 45;
	y *= 45;
	i = 0;
	while (i < src->height)
	{
		j = 0;
		while (j < src->width)
		{
			color = pixel(src, j, i);
			if (color != -1)
				mlx_put_pixel(dst, x + j, y + i, color);
			j++;
		}
		i++;
	}
}

void	draw_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->height_map)
	{
		j = 0;
		while (j < (int)ft_strlen(game->map[i]))
		{
			if (game->map[i][j] == '1')
				img_to_img(game->img, game->all_images.wall_img, j, i);
			else if (game->map[i][j] == '0' || game->map[i][j] == 'P'
				|| game->map[i][j] == 'C' || game->map[i][j] == 'S'
				|| game->map[i][j] == 'E')
				img_to_img(game->img, game->all_images.ground_img, j, i);
			j++;
		}
		i++;
	}
}

void	draw_player(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->height_map)
	{
		x = 0;
		while (x < (int)ft_strlen(game->map[y]))
		{
			if (game->map[y][x] == 'P')
				img_to_img(game->img, game->all_images.player_img,
					game->player.x, game->player.y);
			else if (game->map[y][x] == 'C')
				img_to_img(game->img, game->all_images.collectable_img, x, y);
			else if (game->map[y][x] == 'S')
				img_to_img(game->img, game->all_images.enemy_img, x, y);
			else if (game->map[y][x] == 'E')
				img_to_img(game->img, game->all_images.exit_img, x, y);
			x++;
		}
		y++;
	}
}
