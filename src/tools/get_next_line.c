/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 09:12:21 by yait-el-          #+#    #+#             */
/*   Updated: 2021/01/25 09:12:22 by yait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static t_gnl	*new_gnl(int fd)
{
	t_gnl	*new;

	if (!(new = (t_gnl*)malloc(sizeof(t_gnl))))
		return (NULL);
	new->content = ft_strnew(0);
	new->fd = fd;
	return (new);
}

static t_gnl	*current_file(int fd, t_gnl **f)
{
	t_gnl *tmp;

	tmp = *f;
	while (tmp)
	{
		if (tmp->fd == fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = new_gnl(fd);
	tmp->next = *f;
	*f = tmp;
	return (tmp);
}

static int		ilen(char *r)
{
	int i;

	i = 0;
	while (r[i] && r[i] != '\n')
		i++;
	return (i);
}

static int		reading(const int fd, char **content)
{
	char	buff[BUFF_SIZE + 1];
	char	*tmp;
	int		re;

	while ((re = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[re] = '\0';
		tmp = *content;
		*content = ft_strjoin(tmp, buff);
		ft_strdel(&tmp);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	re += ft_strlen(*content);
	return (re);
}

int				get_next_line(const int fd, char **line)
{
	static t_gnl	*file;
	t_gnl			*fl;
	int				re;
	char			*tmp;

	if (fd < 0 || line == NULL || BUFF_SIZE < 0)
		return (-1);
	fl = current_file(fd, &file);
	re = reading(fd, &fl->content);
	if (re == -1)
		return (-1);
	*line = ft_strsub((fl->content), 0, ilen(fl->content));
	tmp = fl->content;
	if ((fl->content[ilen(tmp)]))
		fl->content = ft_strdup(ft_strchr(fl->content, '\n') + 1);
	else
		fl->content = ft_strnew(0);
	ft_strdel(&tmp);
	if (re == 0 && *fl->content == '\0' && **line == '\0')
	{
		ft_strdel(line);
		return (0);
	}
	return (1);
}
