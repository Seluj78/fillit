/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcollin <alcollin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 17:35:01 by alcollin          #+#    #+#             */
/*   Updated: 2016/11/17 10:35:06 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# include "../src/libft/libft.h"

int g_nb_tetrimino;
# define BUFF_SIZE 4096

typedef struct			s_tetrimino
{
	char				**tetrimino;
	char				letter;
	int					x;
	int					y;
	struct s_tetrimino	*next;
}						t_tetrimino;

t_tetrimino				*arrange(t_tetrimino *start);
int						check(char **tab);
int						get_nb_tetrimino(char *s);
char					**read_stdin(char *argv);
t_tetrimino				*splittab(char **tab);
t_tetrimino				*newtetri(char **tetrimino, int num);
char					**solve(t_tetrimino *start, int square_size,\
		char **tab_solved);
char					**create_tab(char **tab, int square_size);
void					free_tab(char **tab, int tab_size);
int						check_square(char *s);
int						check_bar(char *s);
int						get_height(char *s);
int						get_width(char *s);
int						is_alone(char *s);
int						check_void_int(char *s);
int						first_test(char *buf);
int						ft_sqrt(int nb);
void					ft_usage(void);

#endif
