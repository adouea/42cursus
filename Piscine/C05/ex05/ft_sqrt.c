/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadoue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:21:16 by aadoue            #+#    #+#             */
/*   Updated: 2022/06/21 10:16:50 by aadoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	racine;

	racine = 1;
	while (racine < 46341)
	{
		if ((racine * racine) == nb)
			return (racine);
		racine++;
	}
	return (0);
}
