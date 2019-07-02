/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhobbs <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 09:40:21 by rhobbs            #+#    #+#             */
/*   Updated: 2019/07/02 13:09:18 by rhobbs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include "./libft/libft.h"
# define BUFF_SIZE 32

typedef struct	s_gnl
{
	char *nlp;
	char *temp;
	char *del_temp;
}				t_gnl;

int				get_next_line(const int fd, char **line);

#endif
