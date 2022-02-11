/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbayard <bbayard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 13:31:34 by bbayard           #+#    #+#             */
/*   Updated: 2022/02/05 13:31:36 by bbayard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include "/home/artem/Sl21/minilibx-linux/mlx.h"
# include <stddef.h>

# define BOMB "./img/bmb_1.xpm"
# define BOMB_1 "./img/bmb_2.xpm"
# define C_1 "./img/c.xpm"
# define C_2 "./img/c_wpn_2.xpm"
# define E_S "./img/0.xpm"
# define EXIT "./img/e.xpm"
# define S_P "./img/strt_p.xpm"
# define W "./img/1.xpm"
# define PLR "./img/p.xpm"

typedef struct s_t
{
	int		pos_s_x;
	int		pos_s_y;
	int		x_max;
	int		y_max;
	char	**map;
	void	*mlx;
	void	*window;
	void	*i_0;
	void	*i_wall;
	void	*i_collect;
	void	*i_exit;
	void	*i_pos;
	int		img_size;
	int		move_counter;
	int		c;
}	t_p;

char	*get_next_line(int fd);
int		ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strrchr(const char *s, int c);
int		main(int argc, char **argv);
char	**map_record(char *argv, t_p *s, int len);
char	**map_check(char **map, int len, t_p *s);
void	check_valid_map(char **map, int len, t_p *s);
void	find_start_pos(char **map, int len, t_p *s);
void	check_collect_c(char **map, int len, t_p *s);
void	ex_exit(char *str);
void	free_map(char **map, int len, char *s);
char	**ft_split(char *s, char c);
void	free_map_list(char **map, int len, t_p *s);
void	free_list(t_p *s);
void	fre_list(t_p *s);
void	inicialization(t_p *s);
void	put_img_to_wdw(t_p *s);
void	put_on_map(t_p *s, int x, int y);
void	fre_list(t_p *s);
int		key_hook(int keycode, t_p *s);

#endif
