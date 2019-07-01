/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhobbs <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 09:40:21 by rhobbs            #+#    #+#             */
/*   Updated: 2019/06/29 15:33:12 by rhobbs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE
# include BUFF_SIZE 200
# include <unistd.h>
# include "./libft/libft.h"

int	get_next_line(const int fd, char **line);

#endif