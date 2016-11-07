/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proto.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 13:02:21 by jlasne            #+#    #+#             */
/*   Updated: 2016/11/07 15:02:28 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTO_H
# define PROTO_H

# include "struct.h"

void			ft_usage(void);
int				check_space(char *str);
int				check_line(char *str, int i);
int				check_forme(char *str, int i);
int				check_link(char *str, int i);
int				check_vide(char *str, int i);
int				check_tetri(char *str);
int				get_largeur(char *str, int i);
int				get_hauteur(char *str, int i);
int				count_tetri(char *str);
t_tetrimino		*new_tetri(char *str, int nb);
char			*convert(char *str, int i);
t_tetrimino		*split(char *str);

#endif
