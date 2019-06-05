/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 01:02:47 by yait-el-          #+#    #+#             */
/*   Updated: 2019/04/22 21:28:05 by yait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;

	str = (char*)malloc((ft_strlen(s1) + 1) * sizeof(*str));
	if (str != NULL)
		ft_strcpy(str, s1);
	return (str);
}
