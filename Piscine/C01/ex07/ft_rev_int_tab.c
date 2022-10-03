/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadoue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 17:17:43 by aadoue            #+#    #+#             */
/*   Updated: 2022/06/14 11:25:00 by aadoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	stock;

	size = size - 1;
	i = 0;
	while (i < size)
	{
		stock = tab[i];
		tab[i] = tab[size];
		tab[size] = stock;
		i++;
		size--;
	}
}
