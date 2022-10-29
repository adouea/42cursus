/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadoue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 14:56:06 by aadoue            #+#    #+#             */
/*   Updated: 2022/10/29 15:00:19 by aadoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    ft_putchar_fd(char c, int fd);
{
        if (fd >= 0 && fd < 3)
        {
                write(fd, c, 1);
        }
}

void	ft_putnbr_fd(int n, int fd)
{
	long	nb;

	nb = n;
	if (fd >= 0 && fd < 3)
	{
		if (nb < 0)
		{
			ft_putchar_fd('-');
			nb = nb * -1;
		}
		if (nb > 9)
			ft_putnbr(nb / 10);
		ft_putchar((nb % 10) + '0');
	}
}
