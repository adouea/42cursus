/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadoue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 14:46:28 by aadoue            #+#    #+#             */
/*   Updated: 2022/10/31 15:44:12 by aadoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_putchar_fd(char c, int fd);
{
	if (fd >= 0 && fd < 3)
	{
		write(fd, c, 1);
	}
}
