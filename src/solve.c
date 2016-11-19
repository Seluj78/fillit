/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcollin <alcollin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/18 15:09:48 by alcollin          #+#    #+#             */
/*   Updated: 2016/11/17 10:36:46 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

/*
** Test si la position est ok
** et que ça sort pas ou que ça touche pas une autre piece
*/

static int		test_pos(t_tetrimino *start, char **tab, int square_size)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			if (start->tetrimino[i][j] == '#' && (start->x + j >= square_size \
						|| start->y + i >= square_size))
				return (0);
			if (start->tetrimino[i][j] == '#' && \
					ft_isalpha(tab[start->y + i][start->x + j]) == 1)
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

/*
** Place le tetriminos dans le tableau si test_pos est ok
*/

static char		**placement(t_tetrimino *start, char **tab)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			if (start->tetrimino[i][j] == '#')
				tab[start->y + i][start->x + j] = start->letter;
			j++;
		}
		j = 0;
		i++;
	}
	return (tab);
}

/*
** Remplace la lettre du tetriminos par des points
*/

static char		**delete(t_tetrimino *start, char **tab)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (tab[i] != NULL)
	{
		while (tab[i][j] != '\0')
		{
			if (tab[i][j] == start->letter)
				tab[i][j] = '.';
			j++;
		}
		j = 0;
		i++;
	}
	return (tab);
}

/*
** Recherche recursive de la meilleure place tant que *start
** Teste de placer la pièce ou la supprime si celle d'après ne passe pas
** Retourne 1 si c'est ok ou 0
*/

int				place(t_tetrimino *start, int square_size, char **tab)
{
	if (start != NULL)
	{
		while (start->y * start->x < square_size * square_size)
		{
			if ((test_pos(start, tab, square_size)) == 1)
			{
				tab = placement(start, tab);
				if (place(start->next, square_size, tab) == 1)
					return (1);
				tab = delete(start, tab);
			}
			if (start->x < square_size)
				start->x++;
			else
			{
				start->x = 0;
				start->y++;
			}
		}
		start->x = 0;
		start->y = 0;
		return (0);
	}
	return (1);
}

/*
** Solve fillit et retourne la solution (char **)
** Square_size est la taille du tableau
** Return tab_solved
*/

char			**solve(t_tetrimino *start, int square_size, char **tab_solved)
{
	arrange(start);
	tab_solved = create_tab(tab_solved, square_size);
	while (place(start, square_size, tab_solved) == 0)
	{
		square_size++;
		start->x = 0;
		start->y = 0;
		free_tab(tab_solved, square_size);
		tab_solved = create_tab(tab_solved, square_size);
	}
	return (tab_solved);
}
