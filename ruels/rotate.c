/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moer-ret <moer-ret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 18:52:13 by moer-ret          #+#    #+#             */
/*   Updated: 2024/02/23 14:42:56 by moer-ret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_rotate(t_list **stack)
{
	t_list	*tmp;

	if ((*stack) == NULL)
		return (-1);
	tmp = *stack;
	*stack = tmp->next;
	ft_lstadd_back(stack, tmp);
	return (0);
}

int	ra(t_list **stack_a)
{
	if (ft_rotate(stack_a) != -1)
		ft_print_ruls("ra");
	return (0);
}

int	rb(t_list **stack_b)
{
	if (ft_rotate(stack_b) != -1)
		ft_print_ruls("rb");
	return (0);
}

int	rr(t_list **stack_a, t_list **stack_b)
{
	if (ft_rotate(stack_a) != -1 && ft_rotate(stack_b) != -1)
		ft_print_ruls("rr");
	return (0);
}
