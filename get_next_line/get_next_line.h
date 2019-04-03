/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 19:46:17 by cwu               #+#    #+#             */
/*   Updated: 2018/04/18 19:46:19 by cwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# define BUFF_SIZE 42
# define MAX_FILENUMBER 4094

int				get_next_line(const int fd, char **line);

typedef struct	s_file
{
	int			fd;
	char		*m;
}				t_file;

#endif
