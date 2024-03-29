/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadoue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 18:18:18 by aadoue            #+#    #+#             */
/*   Updated: 2023/04/09 18:18:20 by aadoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_r(int m1, int m2)
{
	if (m1 < 0 && m2 < 0)
	{
		m1 *= -1;
		m2 *= -1;
	}
	if (m1 > m2)
		return (m1 - m2);
	else
		return (m2 - m1);
}

int	get_rr(int m1, int m2)
{
	if (m1 < 0 && m2 < 0)
	{
		m1 *= -1;
		m2 *= -1;
	}
	if (m1 > m2)
		return (m2);
	else
		return (m1);
}

int	count_moves(int mv_a, int mv_b)
{
	if (mv_a * mv_b > 0)
		return (get_r(mv_a, mv_b) + get_rr(mv_a, mv_b));
	else
		return (ft_mod(mv_a) + ft_mod(mv_b));
}

int	count_rot_on_top(t_stack *element, t_stack *stk)
{
	int	pos;

	pos = 0;
	if (! element)
		return (pos);
	while (stk)
	{
		if (stk->value == element->value)
			break ;
		pos++;
		stk = stk->next;
	}
	return (pos);
}
