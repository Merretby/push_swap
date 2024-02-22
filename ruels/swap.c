/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moer-ret <moer-ret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 16:05:04 by moer-ret          #+#    #+#             */
/*   Updated: 2024/02/22 18:22:11 by moer-ret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_swap(t_list **stack)
{
	t_list	*head;
	t_list	*node;
	int		tmp;
	int		index;

	if (*stack == NULL)
		return (-1);
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
	if (ft_swap(stack) != -1)
		ft_putstr("sa");
	return (0);
}

int	sb(t_list **stack)
{
	if (ft_swap(stack) != -1)
		ft_putstr("sb");
	return (0);
}

int	ss(t_list **stack_a, t_list **stack_b)
{
	if (ft_swap(stack_a) != -1 && ft_swap(stack_b) != -1)
		ft_putstr("ss");
	return (0);
}
