/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadoue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 13:15:56 by aadoue            #+#    #+#             */
/*   Updated: 2022/10/31 15:33:33 by aadoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t	ft_strlen(const char *str);

char    *ft_strdup(const char *src)
{
        char    *stock;
        int             i;

        i = 0;
        stock = malloc((ft_strlen(src) + 1) * sizeof(char));
        if (!stock)
                return (0);
        while (src[i])
        {
                stock[i] = src[i];
                i++;
        }
        stock[i] = '\0';
        return (stock);
}

