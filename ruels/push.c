/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moer-ret <moer-ret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 10:31:14 by moer-ret          #+#    #+#             */
/*   Updated: 2024/02/19 18:53:30 by moer-ret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_push(t_list **stack_x, t_list **stack_y)
{
	t_list	*tmp;

	tmp = *stack_x;
	*stack_x = tmp->next;
	ft_lstadd_front(stack_y, tmp);
	return (0);
}

int	pa(t_list **stack_a, t_list **stack_b)
{
	ft_push(stack_b, stack_a);
	ft_putstr("pa");
	return (0);
}

int	pb(t_list **stack_a, t_list **stack_b)
{
	ft_push(stack_a, stack_b);
	ft_putstr("pb");
	return (0);
}
