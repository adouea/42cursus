/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_double.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadoue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 16:29:18 by aadoue            #+#    #+#             */
/*   Updated: 2023/04/09 16:29:22 by aadoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_free_double(void ***to_free, int n_arr)
{
	int		i;
	char	***tmp;

	if (to_free && *to_free)
	{
		i = 0;
		if (n_arr == -1)
		{
			tmp = (char ***) to_free;
			while ((*tmp)[i])
				free((*tmp)[i++]);
			free(*tmp);
		}
		else
		{
			while (i < n_arr)
				free((*to_free)[i++]);
			free(*to_free);
		}
	}
	return (NULL);
}
