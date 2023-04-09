/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadoue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 16:26:24 by aadoue            #+#    #+#             */
/*   Updated: 2023/04/09 16:26:32 by aadoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
//#include<stdio.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*new_obj;

	new_obj = (t_list *) malloc(sizeof(t_list));
	if (new_obj == NULL)
		return (NULL);
	if (! content)
		new_obj->content = NULL;
	else
		new_obj->content = content;
	new_obj->next = NULL;
	return (new_obj);
}
/*
int main()
{
    char c = 'a';
    char *ptr = NULL;//&c;
    t_list *tst = ft_lstnew(ptr);
    printf("%c\n", *((char *)(tst->content)));
}
*/
