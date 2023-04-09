/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raise_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadoue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 16:31:47 by aadoue            #+#    #+#             */
/*   Updated: 2023/04/09 16:31:53 by aadoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_raise_error(char *text, int end)
{
	ft_putstr_fd(text, 2);
	ft_putchar_fd('\n', 2);
	if (end)
		exit(EXIT_FAILURE);
	else
		return (NULL);
}
