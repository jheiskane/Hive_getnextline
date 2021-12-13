/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheiskan <jheiskan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 21:47:28 by jheiskan          #+#    #+#             */
/*   Updated: 2021/12/13 15:53:31 by jheiskan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <fcntl.h>
# include "./libft/includes/libft.h"
# define BUFF_SIZE 100
# define MAX_FD 12228

typedef struct s_line
{
	char			*s_data;
	int				l_len;
	int				l_saved;
	int				fd;
}					t_line;

int	get_next_line(const int fd, char **line);

#endif
