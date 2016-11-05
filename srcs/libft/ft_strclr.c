/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <jlasne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/27 12:53:32 by jlasne            #+#    #+#             */
/*   Updated: 2016/11/03 17:49:13 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strclr(char *s)
{
	int i;

	if (s == NULL)
		return ;
	i = ft_strlen(s);
	while (i--)
		s[i] = '\0';
}
