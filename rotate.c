/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moer-ret <moer-ret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 18:52:13 by moer-ret          #+#    #+#             */
/*   Updated: 2024/02/06 20:36:12 by moer-ret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_rotate(t_list **stack)
{
	t_list	*tmp;

	tmp = *stack;
	*stack = tmp->next;
	ft_lstadd_back(stack, tmp);
	return (0);
}

int	ra(t_list **stack_a)
{
	ft_rotate(stack_a);
	ft_putstr("ra");
	return (0);
}

int	rb(t_list **stack_b)
{
	ft_rotate(stack_b);
	ft_putstr("rb");
	return (0);
}

int	rr(t_list **stack_a, t_list **stack_b)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	ft_putstr("rr");
	return (0);
}

int	reverse_rotate(t_list **stack)
{
	t_list	*tmp;
	t_list	*second;

	second = *stack;
	while(second->next->next)
		second = second->next;
	tmp = ft_lstlast(*stack);
	ft_lstadd_front(stack, tmp);
	second->next = NULL;
	return (0);
}
