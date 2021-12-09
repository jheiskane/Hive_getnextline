/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheiskan <jheiskan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 22:36:26 by jheiskan          #+#    #+#             */
/*   Updated: 2021/12/09 16:20:02 by jheiskan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_line	*new_line(t_line *new, char buf[], t_var **var_s)
{
	int	i;

	i = -1;
	ft_bzero(buf, BUFF_SIZE + 1);
	*var_s = (t_var *)malloc(sizeof(t_var));
	(*var_s)->tmp = ft_strnew(0);
	(*var_s)->b_read = 1;
	if (new == NULL)
	{
		new = (t_line *)malloc(sizeof(t_line));
		new->s_data = ft_strnew(0);
		new->l_saved = 0;
	}
	else if (new->s_data)
	{
		while (new->s_data[++i] != '\0')
			buf[i] = new->s_data[i];
		ft_strdel(&(new->s_data));
		(*var_s)->b_read = i;
	}
	return (new);
}

char	*ft_realloc(char *buf, char *str, int b_read)
{
	char	*tmp_ptr;

	buf[b_read] = '\0';
	tmp_ptr = str;
	str = ft_strjoin(str, buf);
	ft_strdel(&tmp_ptr);
	return (str);
}

int	save_data(t_line **ptr, char *buf, t_var *s, char **line)
{
	int		saved_bytes;
	t_line	*tmp;
	int		l_len;

	l_len = (*ptr)->l_len;
	saved_bytes = s->b_read - l_len;
	if (s->b_read > ++l_len)
	{
		tmp = (t_line *)ft_memalloc(sizeof(t_line));
		if (!tmp)
			return (-1);
		tmp->s_data = ft_strsub((const char *)buf, l_len, saved_bytes);
		tmp->s_data[saved_bytes - 1] = '\0';
		tmp->l_saved = 1;
		tmp->l_len = l_len - 1;
		*ptr = tmp;
	}
	*line = ft_realloc(buf, s->tmp, l_len - 1);
	free(s);
	return (1);
}

int	seek_char(char *str, int c, int len, int *l_saved)
{
	int	i;

	i = 0;
	*l_saved = 0;
	while (i < len)
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	get_next_line(const int fd, char **line)
{
	t_var			*var_s;
	char			buf[BUFF_SIZE + 1];
	static t_line	*save;

	save = new_line(save, &(*buf), &var_s);
	save->l_len = -1;
	while (var_s->b_read > 0 && save->l_len == -1 && fd >= 0 && line)
	{
		if (save->l_saved == 0)
			var_s->b_read = read(fd, buf, BUFF_SIZE);
		if (var_s->b_read > 0)
		{
			save->l_len = seek_char(buf, '\n', var_s->b_read, &(save->l_saved));
			if (save->l_len == -1)
				var_s->tmp = ft_realloc(buf, var_s->tmp, var_s->b_read);
			else if (save->l_len >= 0)
				return (save_data(&save, buf, var_s, line));
		}
	}
	if (var_s->b_read < 0 || fd < 0 || !line)
		return (-1);
	*line = var_s->tmp;
	return (!(buf[0] == '\0'));
}
