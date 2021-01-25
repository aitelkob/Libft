/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 09:57:38 by yait-el-          #+#    #+#             */
/*   Updated: 2021/01/25 09:57:45 by yait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*head;
	t_list	*tmp;

	head = *alst;
	while (head)
	{
		tmp = head->next;
		del(head->content, head->content_size);
		free(head);
		head = tmp;
	}
	*alst = NULL;
}
