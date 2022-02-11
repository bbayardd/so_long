/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_work.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbayard <bbayard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 13:28:50 by bbayard           #+#    #+#             */
/*   Updated: 2022/02/05 13:28:53 by bbayard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_collect_c(char **map, int len, t_p *s)
{
	int	y;
	int	x;
	int	len_str;

	x = 0;
	s->c = 0;
	len_str = ft_strlen(map[0]);
	while (++x < len)
	{
		y = -1;
		while (++y < len_str)
		{
			if (map[x][y] == 'C')
				s->c++;
		}	
	}
	if (s->c == 0)
		free_map(s->map, len, "Wrong map");
	s->x_max = len + 1;
	s->y_max = len_str;
}

void	find_start_pos(char **map, int len, t_p *s)
{
	int	y;
	int	x;
	int	len_str;
	int	c;

	x = 0;
	c = 0;
	len_str = ft_strlen(map[0]);
	while (++x < len)
	{
		y = -1;
		while (++y < len_str)
		{
			if (map[x][y] == 'P')
			{
				s->pos_s_x = x;
				s->pos_s_y = y;
				c++;
			}
		}	
	}
	if (c != 1)
		free_map(s->map, len, "Wrong map");
	check_collect_c(map, len, s);
}

void	check_valid_map(char **map, int len, t_p *s)
{	
	int	i;
	int	c;
	int	e;
	int	p;

	c = 0;
	e = 0;
	p = 0;
	i = 0;
	while (i < len)
	{
		if (ft_strrchr(map[i], 'C') != NULL)
			c = 1;
		if (ft_strrchr(map[i], 'E') != NULL)
			e = 1;
		if (ft_strrchr(map[i], 'P') != NULL)
			p = 1;
		i++;
	}
	if (!p || !c || !e)
		free_map(map, len, "Wrong map");
	find_start_pos(map, len, s);
}

char	**map_check(char **map, int len, t_p *s)
{
	int	i;
	int	len_str;
	int	y;

	len_str = ft_strlen(map[0]);
	i = -1;
	while (map[++i])
	{
		if (ft_strlen(map[i]) != len_str || (map[i][0] != '1'
			|| map[i][len_str - 1] != '1'))
			len = -1;
	}
	i--;
	y = -1;
	while (map[0][++y])
	{
		if (map[0][y] != '1' || map[i][y] != '1')
			len = -1;
	}
	if (len == -1)
		free_map(map, i, "Wrong map");
	check_valid_map(map, i, s);
	return (map);
}

char	**map_record(char *argv, t_p *s, int len)
{
	char	buf[2];
	char	**map;
	int		fd;
	char	*line;

	map = NULL;
	line = NULL;
	len = ft_strlen(argv);
	if (len < 5 || argv[len - 1] != 'r' || argv[len - 2] != 'e'
		|| argv[len - 3] != 'b' || argv[len - 4] != '.')
		ex_exit("Wrong extension");
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		ex_exit("No such file or directory");
	len = 0;
	buf[1] = '\0';
	while (read(fd, buf, 1) > 0)
		line = ft_strjoin(line, buf);
	close(fd);
	map = ft_split(line, '\n');
	free(line);
	map_check(map, len, s);
	return (map);
}
