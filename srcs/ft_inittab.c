/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inittab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 15:30:35 by jlasne            #+#    #+#             */
/*   Updated: 2016/11/07 15:54:03 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

void	ft_inittab(t_tetrivar* var, int size)
{
	int i;
	int j;

	i = size;
	j= 0;
	var->tab = (char**)malloc(sizeof(char*) * size);
	while (i > 0)
	{
		var->tab[j] = (char*)malloc(sizeof(char) * size);
		var->tab[j] = ft_memset(var->tab[j], '.', size);
		i++;
		j++;
	}
	ft_putstr(var->tab[0]);
	ft_putstr(var->tab[1]);
	ft_putstr(var->tab[2]);
	ft_putstr(var->tab[3]);
	ft_putstr(var->tab[4]);

}
