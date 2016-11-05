/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 12:50:11 by jlasne            #+#    #+#             */
/*   Updated: 2016/11/05 13:11:07 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

int		main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_usage();
		exit(EXIT_FAILURE);
	}
	(void)argv;
	ft_putstr("Hello");
	return (0);
}
