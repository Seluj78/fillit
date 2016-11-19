/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcollin <alcollin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/18 15:09:49 by alcollin          #+#    #+#             */
/*   Updated: 2016/11/17 10:35:54 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

/*
** Remplit un char* pour creer une liste de tetriminos
** Return le tab (char**)
*/

static	char	**fill_tab(char **tab, char *buf)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (j < get_nb_tetrimino(buf))
	{
		tab[j] = (char*)malloc(sizeof(char) * 20 + 1);
		if (tab[j] == NULL)
			return (NULL);
		while (k < 20)
		{
			tab[j][k] = buf[i];
			k++;
			i++;
		}
		tab[j][20] = '\0';
		k = 0;
		j++;
		i++;
	}
	tab[j] = NULL;
	return (tab);
}

/*
**Read, get nb_tetrimino,
**verifie le format des pieces et remplit le tab de pieces
*/

char			**read_stdin(char *argv)
{
	int		fd;
	int		ret;
	char	buf[BUFF_SIZE + 1];
	char	**tmp;

	if ((fd = open(argv, O_RDONLY)) == -1)
		return (NULL);
	ret = 1;
	tmp = NULL;
	while ((ret = read(fd, buf, BUFF_SIZE)) != 0)
		buf[ret] = '\0';
	g_nb_tetrimino = get_nb_tetrimino(buf);
	tmp = (char**)malloc(sizeof(char *) * get_nb_tetrimino(buf) + 1);
	if (tmp == NULL)
		return (NULL);
	if (first_test(buf) == 0)
		return (NULL);
	tmp = fill_tab(tmp, buf);
	return (tmp);
}

/*
** Split tab pour créer une liste chainee de tetriminos
*/

t_tetrimino		*splittab(char **tab)
{
	int			i;
	t_tetrimino	*start;
	t_tetrimino	*ptr;

	i = 1;
	start = NULL;
	ptr = NULL;
	start = newtetri(ft_strsplit(tab[0], '\n'), 0);
	ptr = start;
	while (i < g_nb_tetrimino)
	{
		ptr->next = newtetri(ft_strsplit(tab[i], '\n'), i);
		ptr = ptr->next;
		i++;
	}
	ptr->next = NULL;
	return (start);
}
