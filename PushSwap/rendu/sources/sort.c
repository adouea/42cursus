/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadoue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 18:20:19 by aadoue            #+#    #+#             */
/*   Updated: 2023/04/09 18:20:22 by aadoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two_ele(t_stack **stk)
{
	int	first;
	int	second;

	first = (*stk)->value;
	second = (*stk)->next->value;
	if (first > second)
		perform_action("sa", 1, stk, NULL);
}

void	sort_three_ele(t_stack **stk)
{
	int	type_triple;

	type_triple = check_triple(*stk);
	if (type_triple == 1)
	{
		perform_action("rra", 1, stk, NULL);
		perform_action("sa", 1, stk, NULL);
	}
	else if (type_triple == 2)
		perform_action("rra", 1, stk, NULL);
	else if (type_triple == 3)
	{
		perform_action("sa", 1, stk, NULL);
		perform_action("rra", 1, stk, NULL);
	}
	else if (type_triple == 4)
		perform_action("ra", 1, stk, NULL);
	else if (type_triple == 5)
		perform_action("sa", 1, stk, NULL);
}

void	sort(t_stack **a)
{
	int	n;

	n = n_nodes(*a);
	if (n == 1 || is_sorted(*a))
		return ;
	else if (n == 2)
		sort_two_ele(a);
	else if (n == 3)
		sort_three_ele(a);
	else
		algo_turk(a);
}
