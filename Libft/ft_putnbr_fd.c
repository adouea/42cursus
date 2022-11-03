/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadoue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 14:56:06 by aadoue            #+#    #+#             */
/*   Updated: 2022/11/03 15:53:43 by aadoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd);

void	ft_putnbr_fd(int n, int fd)
{
	long	nb;

	nb = n;
	if (fd >= 0 && fd < 3)
	{
		if (nb < 0)
		{
			ft_putchar_fd('-', fd);
			nb = nb * -1;
		}
		if (nb > 9)
			ft_putnbr_fd((nb / 10), fd);
		ft_putchar_fd(((nb % 10) + '0'), fd);
	}
}
