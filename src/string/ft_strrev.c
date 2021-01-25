/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 09:14:58 by yait-el-          #+#    #+#             */
/*   Updated: 2021/01/25 09:15:00 by yait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	char	*strcopy;
	char	*endstr;
	char	temp;

	endstr = str + ft_strlen(str);
	strcopy = str - 1;
	while (++strcopy < --endstr)
	{
		temp = *endstr;
		*endstr = *strcopy;
		*strcopy = temp;
	}
	return (str);
}
