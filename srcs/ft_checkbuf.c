/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkbuf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 14:09:38 by jlasne            #+#    #+#             */
/*   Updated: 2016/11/07 14:53:32 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

int			check_space(char *str)
{
	int		i;
	int		j;

	j = 0;
	i = 20;
	while (str[j] != '\0')
		j++;
	j--;
	if (str[j - 1] == '.' || str[j - 1] == '#')
		;
	else
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
		{
			if (str[i - 2] == '\n' || str[i + 1] == '\n')
				return (-1);
			i = i + 21;
		}
		else
			return (0);
	}
	return (1);
}

int			check_line(char *str, int i)
{
	int		diese;
	int		point;
	int		n;
	int		max;

	diese = 0;
	point = 0;
	n = 0;
	max = i + 19;
	while (i <= max)
	{
		if (str[i] == '.')
			point++;
		else if (str[i] == '#')
			diese++;
		else if (str[i] == '\n')
			n++;
		i++;
	}
	if (diese == 4 && point == 12 && n == 4)
		return (1);
	return (0);
}

int			check_forme(char *str, int i)
{
	int		hauteur;
	int		largeur;

	hauteur = get_hauteur(str, i);
	largeur = get_largeur(str, i);
	if ((hauteur == 1 && largeur == 4)
			|| (hauteur == 2 && largeur == 2)
			|| (hauteur == 2 && largeur == 3)
			|| (hauteur == 3 && largeur == 2)
			|| (hauteur == 4 && largeur == 1))
		return (1);
	return (0);
}

int			check_link(char *str, int i)
{
	int		max;
	int		link;

	max = i + 19;
	link = 0;
	while (i <= max)
	{
		if (str[i] == '#')
		{
			if (str[i + 1] == '#' || str[i - 1] == '#' || str[i + 5] == '#'
					|| str[i - 5] == '#')
				link++;
			if (link == 4)
				return (1);
		}
		i++;
	}
	return (0);
}

int			check_vide(char *str, int i)
{
	int		diese;
	int		x;
	int		max;

	diese = 0;
	x = 0;
	max = i + 19;
	while (i < max)
	{
		if (str[i] == '#')
			diese++;
		if (diese == 2 && str[i] == '#')
		{
			while (str[i + 1 + x] != '#' && str[i + x] != '\0')
				x++;
			if (x > 5)
				return (0);
		}
		i++;
	}
	return (1);
}
