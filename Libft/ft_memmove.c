/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadoue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 15:04:18 by aadoue            #+#    #+#             */
/*   Updated: 2022/10/13 15:15:16 by aadoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void    *ft_memmove(char *dest, char *src, int n)
{       
        int     i;
	char	*stock;

        i = 0;
	stock = NULL;
        while (i < n)
        {
                stock[i] = src[i];
                i++;
	}
	i = 0;
	while (i < n)
	{
		dest[i] = stock [i];
		i++;
	}
	return (*dest);
}
