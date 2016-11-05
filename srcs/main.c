/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 12:50:11 by jlasne            #+#    #+#             */
/*   Updated: 2016/11/05 14:49:22 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

int		main(int argc, char **argv)
{
	//t_fillit var;
	if (argc != 2)
	{
		ft_usage();
		exit(EXIT_FAILURE);
	}
	ft_readfile(argc, argv);
	(void)argv;
	return (0);
}
