/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_sizes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 14:15:30 by jlasne            #+#    #+#             */
/*   Updated: 2016/11/07 14:18:08 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

int     get_largeur(char *str, int i)
{
	int     max;
	int     largeur;
	int     vide;

	vide = 0;
	largeur = 0;
	max = i + 4;
	while (i < max)
	{
		if (str[i] == '#' || str[i + 5] == '#' || str[i + 10] == '#'
				|| str[i + 15] == '#')
		{
			largeur++;
			if (vide > 0)
				return (0);
		}
		else if (largeur > 0)
			vide++;
		i++;
	}
	return (largeur);
}

int     get_hauteur(char *str, int i)
{
	int     max;
	int     hauteur;
	int     vide;

	hauteur = 0;
	vide = 0;
	max = i + 19;
	while (i < max)
	{
		if (str[i] == '#' || str[i + 1] == '#' || str[i + 2] == '#'
				|| str[i + 3] == '#')
		{
			hauteur++;
			if (vide > 0)
				return (0);
		}
		else if (hauteur > 0)
			vide++;
		i = i + 5;
	}
	return (hauteur);
}
