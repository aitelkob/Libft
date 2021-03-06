/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 09:52:16 by yait-el-          #+#    #+#             */
/*   Updated: 2021/03/05 19:09:55 by yait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					you(t_rst *tp, char **line, int i)
{
	char			*tmp;
	int				j;

	j = 0;
	if (tp->rst[i] != '\n')
	{
		j = read(tp->fd, *line, BUFF_SIZE);
		if (j == -1)
			return (-1);
		while (j != 0 || tp->rst[i] != '\0')
		{
			tmp = ft_strjoin(tp->rst, *line);
			free(tp->rst);
			tp->rst = tmp;
			ft_strclr(*line);
			while (tp->rst[i] != '\0' && tp->rst[i] != '\n')
				i++;
			if (tp->rst[i] == '\n')
				break ;
			j = read(tp->fd, *line, BUFF_SIZE);
		}
	}
	return (i);
}

t_rst				*list(t_rst *tp, const int fd)
{
	static	t_rst	*head;

	if (!head)
	{
		head = (t_rst *)malloc(sizeof(t_rst));
		head->rst = ft_memalloc(BUFF_SIZE + 1);
		head->fd = fd;
		head->next = NULL;
	}
	tp = head;
	while (tp->next != NULL)
	{
		if (tp->fd == fd)
			break ;
		tp = tp->next;
	}
	if (tp->fd != fd)
	{
		tp->next = (t_rst *)malloc(sizeof(t_rst));
		tp = tp->next;
		tp->rst = ft_memalloc(BUFF_SIZE + 1);
		tp->fd = fd;
		tp->next = NULL;
	}
	return (tp);
}

int					get_next_line(const int fd, char **line)
{
	int				i;
	char			*tmp;
	int				j;
	t_rst			*tp;

	tp = NULL;
	j = 0;
	tp = list(tp, fd);
	if (fd < 0 || line == NULL)
		return (-1);
	*line = ft_memalloc(BUFF_SIZE + 1);
	i = 0;
	while (tp->rst[i] != '\0' && tp->rst[i] != '\n')
		i++;
	i = you(tp, line, i);
	if (i == -1)
		return (-1);
	free(*line);
	*line = ft_strsub(tp->rst, 0, i);
	if (tp->rst[0] == '\0')
		j = -5;
	tmp = tp->rst;
	tp->rst = ft_strsub(tp->rst, i + 1, ft_strlen(tp->rst) - i);
	free(tmp);
	return (j != -5);
}
