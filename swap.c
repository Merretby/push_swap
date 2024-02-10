/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moer-ret <moer-ret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 16:05:04 by moer-ret          #+#    #+#             */
/*   Updated: 2024/02/09 16:27:27 by moer-ret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_swap(t_list **stack)
{
	t_list	*head;
	t_list	*node;
	int		tmp;
	int		index;

	head = *stack;
	node = head->next;
	if (!head && !node)
		exit (1);
	tmp = head->content;
	head->content = node->content;
	node->content = tmp;
	index = head->index;
	head->index = node->index;
	node->index = index;
	return (0);
}

int	sa(t_list **stack)
{
	ft_swap(stack);
	ft_putstr("sa");
	return (0);
}

int	sb(t_list **stack)
{
	ft_swap(stack);
	ft_putstr("sb");
	return (0);
}

int	ss(t_list **stack_a, t_list **stack_b)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
	ft_putstr("ss");
	return (0);
}
