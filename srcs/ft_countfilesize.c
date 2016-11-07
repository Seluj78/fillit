/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countfilesize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 11:08:42 by jlasne            #+#    #+#             */
/*   Updated: 2016/11/07 14:48:48 by alcollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

int		ft_countfilesize(char *filename)
{
	char	buffer;
	int		fd;
	int		lenght;

	fd = open(filename, O_RDONLY);
	lenght = read(fd, &buffer, 5000);
	return (lenght);
}
