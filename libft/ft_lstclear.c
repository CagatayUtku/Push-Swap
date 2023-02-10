/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Cutku <cutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 08:17:27 by Cutku             #+#    #+#             */
/*   Updated: 2022/11/08 20:17:48 by Cutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp_lst;

	if (!lst || !del ||!*lst)
		return ;
	while (*lst)
	{
		tmp_lst = (*lst)->next;
		ft_lstdelone((*lst), del);
		(*lst) = tmp_lst;
	}
	*lst = NULL;
}
