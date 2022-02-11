/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbayard <bbayard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 13:27:49 by bbayard           #+#    #+#             */
/*   Updated: 2022/02/05 13:27:56 by bbayard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}

void	ex_exit(char *str)
{
	if (str != 0)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd("\n", 2);
	}
	exit(1);
}

void	free_map(char **map, int len, char *s)
{
	int	i;

	i = 0;
	while (i < len)
	{
		free(map[i]);
		i++;
	}
	free(map);
	ex_exit(s);
}
