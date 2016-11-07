/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetri.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 14:20:31 by jlasne            #+#    #+#             */
/*   Updated: 2016/11/07 14:42:39 by alcollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

int				count_tetri(char *str)
{
	int		nb;
	int		i;

	i = 0;
	nb = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n' && (str[i + 1] == '\n' || str[i + 1] == '\0'))
			nb++;
		i++;
	}
	return (nb);
}

t_tetrimino		*new_tetri(char *str, int nb)
{
	t_tetrimino		*new;

	new = (t_tetrimino*)malloc(sizeof(t_tetrimino));
	new->str = str;
	new->lettre = 'A' + nb;
	new->next = NULL;
	return (new);
}

char			*convert(char *str, int i)
{
	int		max;
	char	*ptr;
	int		j;

	ptr = (char *)malloc(sizeof(char) * 19 + 1);
	max = i + 19;
	j = 0;
	while (i < max)
	{
		ptr[j] = str[i];
		j++;
		i++;
	}
	ptr[j] = '\0';
	return (ptr);
}

t_tetrimino		*split(char *str)
{
	t_tetrimino		*debut;
	t_tetrimino		*ptr;
	int				nb;
	int				i;
	char			*strptr;

	nb = 0;
	i = 0;
	debut = null;
	ptr = null;
	strptr = convert(str, i);
	debut = new_tetri(strptr, nb);
	ptr = debut;
	i = i + 21;
	nb++;
	while (nb < count_tetri(str))
	{
		strptr = convert(str, i);
		ptr->next = new_tetri(strptr, nb);
		ptr = ptr->next;
		i = i + 21;
		nb++;
	}
	ptr->next = NULL;
	return (debut);
}
