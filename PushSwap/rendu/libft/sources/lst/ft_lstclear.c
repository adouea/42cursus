/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadoue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 16:19:36 by aadoue            #+#    #+#             */
/*   Updated: 2023/04/09 16:20:11 by aadoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next_to_drop;
	t_list	*to_drop;

	if (! lst || ! del || ! lst)
		return ;
	to_drop = *lst;
	while (to_drop)
	{
		next_to_drop = (to_drop)->next;
		ft_lstdelone(to_drop, del);
		to_drop = next_to_drop;
	}
	*lst = NULL;
}
