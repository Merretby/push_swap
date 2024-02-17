/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moer-ret <moer-ret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:27:03 by moer-ret          #+#    #+#             */
/*   Updated: 2024/02/17 10:25:38 by moer-ret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) <= 5)
		sort(stack_a, stack_b);
	else
		simple_sort(stack_a, stack_b);
}

static void	sort_3(t_list **stack)
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

static void	sort_4(t_list **stack_a, t_list **stack_b)
{
	int	track;

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

static void	sort_5(t_list **stack_a, t_list **stack_b)
{
	int	track;

	track = track_index_min(stack_a, the_min(stack_a, -1));
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
		rra(stack_a);
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
