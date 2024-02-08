/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moer-ret <moer-ret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 16:05:04 by moer-ret          #+#    #+#             */
/*   Updated: 2024/02/08 16:15:01 by moer-ret         ###   ########.fr       */
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
int the_min(t_list **stack, int i)
{
	t_list	*head;
	int		value;

	head = *stack;
	value = head->index;
	while (head->next)
	{
		head = head->next;
		if(head->index < value && head->index != i)
			value = head->index;
	}
	return (value);
}

void	sort_3(t_list **stack)
{
	t_list	*head;
	int		min_index;
	int		next_min_index;

	head = *stack;
	min_index = the_min(stack, -2);
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

int	track_index_min(t_list **stack, int i)
{
	t_list	*head;
	int track;

	head = *stack;
	track = 0;
	while (head)
	{
		if (head->index == i)
			break;
		track++;
		head = head->index;
	}
	return (track);
}

void	sort_4(t_list **stack_a, t_list **stack_b)
{
	t_list	*head;
	int 	track;
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
		sort_4();
}
