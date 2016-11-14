/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 13:08:50 by jlasne            #+#    #+#             */
/*   Updated: 2016/11/07 15:52:02 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# define TRUE 1
# define FALSE 0
# define BUFF_SIZE 4096

typedef int		t_bool;

typedef struct s_tetrimino		t_tetrimino;

struct							s_tetrimino
{
	char			*str;
	char			lettre;
	t_tetrimino		*next;
};

typedef struct s_tetrivar		t_tetrivar;

struct							s_tetrivar
{
	int		tab_size;
	char 	**tab;
};

#endif
