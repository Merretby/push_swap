/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moer-ret <moer-ret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 16:05:04 by moer-ret          #+#    #+#             */
/*   Updated: 2024/02/08 20:53:56 by moer-ret         ###   ########.fr       */
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

void	sort_3(t_list **stack)
{
	t_list	*head;
	int		min_index;
	int		next_min_index;

	head = *stack;
	min_index = the_min(stack, -1);
	next_min_index = the_min(stack, min_index);
	if (cheack_sorted(stack))
		return ;
	else if (head->next->index == next_min_index)
	{
		ra(stack);
		sa(stack);
	}
	else if (head->index > min_index && head->next->index > min_index)
		rra(stack);
	else if (head->index == min_index && head->next->index != next_min_index)
	{
		sa(stack);
		ra(stack);
	}
	else if (head->index == next_min_index)
		sa(stack);
	else if (head->next->index == min_index)
		ra(stack);
}

void	sort_4(t_list **stack_a, t_list **stack_b)
{
	int 	track;

	track = track_index_min(stack_a, the_min(stack_a, -1));
	if (cheack_sorted(stack_a))
		return ;
	if (track == 1)
		sa(stack_a);
	else if (track == 2)
	{
		rra(stack_a);
		rra(stack_a);
	}
	else if (track == 3)
		rra(stack_a);
	if (cheack_sorted(stack_a))
		return ;
	pb(stack_a, stack_b);
	sort_3 (stack_a);
	pa(stack_a, stack_b);
}

void	sort_5(t_list **stack_a, t_list **stack_b)
{
	int 	track;
	
	track = track_index_min(stack_a, the_min(stack_a, -1));
	if (cheack_sorted(stack_a))
		return ;
	if (track == 1)
		sa(stack_a);
	else if (track == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (track == 3)
	{
		rra(stack_a);
		rra(stack_a);
	}
	else if (track == 4)
		ra(stack_a);
	if (cheack_sorted(stack_a))
		return ;
	pb(stack_a, stack_b);
	sort_4 (stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	sort(t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = ft_lstsize(*stack_a);
	if (size == 2)
		sa(stack_a);
	if (size == 3)
		sort_3(stack_a);
	if (size == 4)
		sort_4(stack_a, stack_b);
	if (size == 5)
		sort_5(stack_a, stack_b);
}
