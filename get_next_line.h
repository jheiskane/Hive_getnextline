/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheiskan <jheiskan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 21:47:28 by jheiskan          #+#    #+#             */
/*   Updated: 2021/12/10 10:02:10 by jheiskan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <fcntl.h>
# include "./libft/libft.h"
# define BUFF_SIZE 12

typedef struct s_line
{
	char			*s_data;
	int				l_len;
	int				l_saved;
}					t_line;
typedef struct k_line
{
	char			*tmp;
	int				b_read;
	int				i;
}					t_var;
int	get_next_line(const int fd, char **line);

#endif
