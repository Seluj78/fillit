/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checktetri.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 14:12:43 by jlasne            #+#    #+#             */
/*   Updated: 2016/11/07 14:48:28 by alcollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

int		check_tetri(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (check_line(str, i) && check_forme(str, i) && check_link(str, i) &&
				check_vide(str, i))
		{
			if (str[i + 21] == '\0')
				return (1);
			i = i + 21;
		}
		else
			return (0);
	}
	return (1);
}
