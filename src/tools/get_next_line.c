/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 09:52:16 by yait-el-          #+#    #+#             */
/*   Updated: 2019/08/06 10:56:43 by yait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*ft_line_new(char *s, char **line)
{
	int		i;
	char	*rst;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	*line = ft_strsub(s, 0, i);
	if (s[i] == '\n')
		rst = ft_strdup(&s[i] + 1);
	if (!s[i])
		rst = ft_strnew(0);
	return (rst);
}

int				get_next_line(const int fd, char **line)
{
	static char	*str[FD_SIZE];
	char		buff[BUFF_SIZE + 1];
	int			ret;
	char		*tmp;

	if (!line || fd < 0 || fd > FD_SIZE || BUFF_SIZE < 0)
		return (-1);
	if (!str[fd])
		str[fd] = ft_strnew(0);
	while (!ft_strchr(str[fd], '\n') && (ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		tmp = ft_strjoin(str[fd], buff);
		free(str[fd]);
		str[fd] = tmp;
	}
	if (ret < 0)
		return (-1);
	if (ret == 0 && !ft_strlen(str[fd]))
		return (0);
	tmp = ft_line_new(str[fd], line);
	free(str[fd]);
	str[fd] = tmp;
	return (1);
}
