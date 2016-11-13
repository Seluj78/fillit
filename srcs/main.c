/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 12:50:11 by jlasne            #+#    #+#             */
/*   Updated: 2016/11/08 15:22:13 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

int		main(int argc, char **argv)
{
	t_tetrimino	*list;
	t_tetrivar	 var;
	int			fd;
	int			ret;
	char		buf[BUFF_SIZE + 1];

	if (argc != 2)
	{
		ft_usage();
		exit(EXIT_FAILURE);
	}
	fd = open(argv[1], O_RDONLY);
	ret = read(fd, buf, BUFF_SIZE);
	if (check_space(buf) == 1 && check_tetri(buf) == 1)
	{
		list = split(buf);
	}
	ft_inittab(&var, 50);
	ft_printgrid(&var, 50);
	return (0);
}
