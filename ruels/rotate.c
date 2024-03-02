/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moer-ret <moer-ret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 18:52:13 by moer-ret          #+#    #+#             */
/*   Updated: 2024/02/29 14:39:40 by moer-ret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_res(t_list **stack_a, t_list **stack_b)
{
	if (cheack_sorted(stack_a) && ft_lstsize(*stack_b) == 0)
	{
		free_stack(stack_a);
		free_stack(stack_b);
		printf("OK\n");
		exit (0);
	}
	else
	{
		free_stack(stack_a);
		free_stack(stack_b);
		printf("KO\n");
		exit (0);
	}
}

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
