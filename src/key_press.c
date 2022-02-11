/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbayard <bbayard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 13:28:22 by bbayard           #+#    #+#             */
/*   Updated: 2022/02/05 13:28:24 by bbayard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_valid_move(t_p *s, int x, int y)
{
	if (s->map[y][x] == 'E' && s->c == 0)
		free_map(s->map, s->x_max, NULL);
	else if (s->map[y][x] != '1')
	{
		mlx_put_image_to_window(s->mlx, s->window, s->i_pos, x * 49, y * 49);
		if (s->map[y][x] == 'C')
		{
			s->c--;
			s->map[y][x] = '0';
		}
		else if (s->map[s->pos_s_y][s->pos_s_x] == 'E')
			mlx_put_image_to_window(s->mlx, s->window, s->i_exit,
				s->pos_s_x * 49, s->pos_s_y * 49);
		if (s->map[s->pos_s_y][s->pos_s_x] == '0')
			mlx_put_image_to_window(s->mlx, s->window, s->i_0,
				s->pos_s_x * 49, s->pos_s_y * 49);
		if (s->map[s->pos_s_y][s->pos_s_x] == 'P')
			mlx_put_image_to_window(s->mlx, s->window, s->i_0,
				s->pos_s_x * 49, s->pos_s_y * 49);
		s->pos_s_x = x;
		s->pos_s_y = y;
		s->move_counter++;
		printf("your make %i move\n", s->move_counter);
	}
}

int	key_hook(int keycode, t_p *s)
{
	int	x;
	int	y;

	x = s->pos_s_x;
	y = s->pos_s_y;
	if (keycode == 119 || keycode == 65362)
		y--;
	else if (keycode == 115 || keycode == 65364)
		y++;
	else if (keycode == 97 || keycode == 65361)
		x--;
	else if (keycode == 100 || keycode == 65363)
		x++;
	else if (keycode == 65307)
		free_map(s->map, s->x_max, NULL);
	if (keycode == 119 || keycode == 115 || keycode == 97 || keycode == 100
		|| keycode == 65362 || (keycode == 65361)
		|| keycode == 65364 || keycode == 65363)
		check_valid_move(s, x, y);
	return (0);
}
