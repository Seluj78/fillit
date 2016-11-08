/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printgrid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 15:18:34 by jlasne            #+#    #+#             */
/*   Updated: 2016/11/08 15:21:38 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

void	ft_printgrid(t_tetrivar* var, int size)
{
	int i;

	i = 0;
	while(i < size)
	{
		ft_putendl(var->tab[i]);
		i++;
	}
}
