/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moer-ret <moer-ret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 20:43:46 by moer-ret          #+#    #+#             */
/*   Updated: 2024/02/06 20:49:14 by moer-ret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int rra(t_list **stack_a)
{
	reverse_rotate(stack_a);
	ft_putstr("rra");
	return (0);
}

int rrb(t_list **stack_b)
{
	reverse_rotate(stack_b);
	ft_putstr("rrb");
	return (0);
}

int rrr(t_list **stack_a, t_list **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_putstr("rrr");
	return (0);
}
