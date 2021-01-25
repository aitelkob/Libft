/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 09:56:12 by yait-el-          #+#    #+#             */
/*   Updated: 2021/01/25 09:56:13 by yait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*head;
	t_list	*tmp;

	if (!lst || !f)
		return (NULL);
	head = f(lst);
	tmp = head;
	lst = lst->next;
	while (lst)
	{
		head->next = f(lst);
		head = head->next;
		lst = lst->next;
	}
	return (tmp);
}
