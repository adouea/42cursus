/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadoue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 13:15:56 by aadoue            #+#    #+#             */
/*   Updated: 2022/10/14 13:16:00 by aadoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int     ft_strlen(char *str)
{
        int     i;

        i = 0;
        while (str[i])
                i++;
        return (i);
}

char    *ft_strdup(char *src)
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

