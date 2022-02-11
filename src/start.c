/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbayard <bbayard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 13:36:11 by bbayard           #+#    #+#             */
/*   Updated: 2022/02/05 13:36:15 by bbayard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_p	s;

	if (argc != 2)
		ex_exit("Wrong number of argument");
	s.map = map_record(argv[1], &s, 0);
	inicialization(&s);
	mlx_key_hook(s.window, key_hook, &s);
	mlx_hook(s.window, 0, 1, key_hook, &s);
	mlx_loop(s.mlx);
}
