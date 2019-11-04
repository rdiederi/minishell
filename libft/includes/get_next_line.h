/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 22:13:33 by wseegers          #+#    #+#             */
/*   Updated: 2018/05/25 14:41:54 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"

int				get_next_line(const int fd, char **line);

# define BUFF_SIZE 32

typedef unsigned int	t_fpos;

typedef struct	s_file
{
	int		fd;
	char	*buf;
	size_t	bufsize;
	t_fpos	fpos;
	int		flag;
}				t_file;

# define NEWFILE(fd) (t_file){fd, ft_strnew(BUFF_SIZE), 0, 0, 1}

#endif
