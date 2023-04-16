/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadoue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 18:17:08 by aadoue            #+#    #+#             */
/*   Updated: 2023/04/09 18:17:11 by aadoue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_action(char *action)
{
	if (! ft_strncmp((const char *) action, "sa\n", 3)
		|| ! ft_strncmp((const char *) action, "sb\n", 3)
		|| ! ft_strncmp((const char *) action, "ss\n", 3)
		|| ! ft_strncmp((const char *) action, "pa\n", 3)
		|| ! ft_strncmp((const char *) action, "pb\n", 3)
		|| ! ft_strncmp((const char *) action, "ra\n", 3)
		|| ! ft_strncmp((const char *) action, "rb\n", 3)
		|| ! ft_strncmp((const char *) action, "rr\n", 3)
		|| ! ft_strncmp((const char *) action, "rra\n", 4)
		|| ! ft_strncmp((const char *) action, "rrb\n", 4)
		|| ! ft_strncmp((const char *) action, "rrr\n", 4))
		return (1);
	else
		return (0);
}

int	store_actions(char **plain_actions, char *input)
{
	ssize_t	end;
	int		i;

	while (1)
	{
		end = read(0, input, 4);
		if (! end)
			break ;
		else
			input[end] = '\0';
		if (! check_action(input))
			return (0);
		i = 0;
		while (input[i])
		{
			if (! ft_append_char(input[i++], plain_actions))
				return (0);
		}
		if (! ft_append_char('|', plain_actions))
			return (0);
	}
	return (1);
}

void	run_actions(char **actions, t_stack **a)
{
	t_stack	*b;
	int		i;

	b = NULL;
	i = 0;
	if (! actions)
		return ;
	while (actions[i])
	{
		if (actions[i][0] == 'p')
		{
			if (actions[i][1] == 'a')
				perform_action("pa", 1, &b, a);
			else
				perform_action("pb", 1, a, &b);
		}
		else if (actions[i][1] == 'b' || actions[i][2] == 'b')
			perform_action(actions[i], 1, &b, a);
		else
			perform_action(actions[i], 1, a, &b);
		i++;
	}
}

void	test_actions(t_stack **stk_a)
{
	char	**actions;
	char	*plain_actions;
	char	*input;

	actions = NULL;
	plain_actions = NULL;
	input = malloc(5 * sizeof(char));
	if (! input || ! store_actions(&plain_actions, input))
	{
		free_stack(stk_a);
		ft_raise_error_2("Error",(void **) &input, 1);
	}
	actions = ft_split(plain_actions, '|');
	run_actions(actions, stk_a);
	ft_free_double((void ***) &actions, ft_count_occ(plain_actions, '|'));
	free(input);
	free(plain_actions);
}
