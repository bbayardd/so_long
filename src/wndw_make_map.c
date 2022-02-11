/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wndw_make_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbayard <bbayard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 13:29:10 by bbayard           #+#    #+#             */
/*   Updated: 2022/02/05 13:29:14 by bbayard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_on_map(t_p *s, int x, int y)
{
	if (s->map[x][y] == '0')
		mlx_put_image_to_window(s->mlx, s->window, s->i_0,
			y * 49, x * 49);
	else if (s->map[x][y] == '1')
		mlx_put_image_to_window(s->mlx, s->window, s->i_wall,
			y * 49, x * 49);
	else if (s->map[x][y] == 'C')
		mlx_put_image_to_window(s->mlx, s->window, s->i_collect,
			y * 49, x * 49);
	else if (s->map[x][y] == 'P')
		mlx_put_image_to_window(s->mlx, s->window, s->i_pos,
			y * 49, x * 49);
	else
		mlx_put_image_to_window(s->mlx, s->window, s->i_exit,
			y * 49, x * 49);
}

void	put_img_to_wdw(t_p *s)
{
	int	x;
	int	y;

	x = 0;
	while (x < s->x_max)
	{
		y = -1;
		while (++y <= s->y_max)
			put_on_map(s, x, y);
		x++;
	}
}

void	inicialization(t_p *s)
{
	s->mlx = mlx_init();
	if (!s->mlx)
		free_map(s->map, s->x_max, "Wrong inicalization");
	s->window = mlx_new_window(s->mlx, 49 * s->y_max,
			49 * s->x_max, "Sou longe");
	s->i_0 = mlx_xpm_file_to_image(s->mlx, E_S,
			&s->img_size, &s->img_size);
	s->i_wall = mlx_xpm_file_to_image(s->mlx, W,
			&s->img_size, &s->img_size);
	s->i_collect = mlx_xpm_file_to_image(s->mlx, C_1,
			&s->img_size, &s->img_size);
	s->i_exit = mlx_xpm_file_to_image(s->mlx, EXIT,
			&s->img_size, &s->img_size);
	s->i_pos = mlx_xpm_file_to_image(s->mlx, PLR,
			&s->img_size, &s->img_size);
	s->move_counter = 0;
	put_img_to_wdw(s);
}
