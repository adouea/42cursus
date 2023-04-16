/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raise_error_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadoue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 18:58:42 by aadoue            #+#    #+#             */
/*   Updated: 2023/04/12 18:59:01 by aadoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_raise_error_2(char *err_text, void **to_free, int end)
{
	write(2, err_text, ft_strlen(err_text));
	write(2, "\n", 1);
	if (to_free)
	{
		free(*to_free);
		*to_free = NULL;
	}
	if (end)
		exit(EXIT_FAILURE);
}
