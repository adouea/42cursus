/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadoue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 16:17:52 by aadoue            #+#    #+#             */
/*   Updated: 2023/04/09 16:18:08 by aadoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (! lst)
		return ;
	if (*lst)
		new->next = *lst;
	*lst = new;
}
/*
int main()
{
	int v1 = 1, v2 = 2, v3 = 3, v4 = 4;
	int *p1 = &v1, *p2 = &v2, *p3 = &v3, *p4 = &v4;
	t_list *first, *second, *third;
	t_list **vect_ptr = &first;
	first = (t_list *) malloc(sizeof(t_list));
	second = (t_list *) malloc(sizeof(t_list));
	third = (t_list *) malloc(sizeof(t_list));
	vect_ptr = (t_list **) malloc(sizeof(t_list *));
	first->content = p1;
	first->next = second;
	second->content = p2;   
	second->next = third;
	third->content = p3;
	third->next = NULL;
	
	vect_ptr = &first;
	t_list *fourth;
	fourth = (t_list *) malloc(sizeof(t_list));
	fourth->content = p4;
	fourth->next = NULL;
	ft_lstadd_front(vect_ptr, first);
	printf("%d\n", *((int *)((fourth->next)->content)));
	return (0);
}
*/
