/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_array2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moer-ret <moer-ret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 10:10:47 by moer-ret          #+#    #+#             */
/*   Updated: 2024/02/27 16:00:22 by moer-ret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	index_of_b(t_list **stack_b)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = *stack_b;
	while (tmp)
	{
		tmp->index = i++;
		tmp = tmp->next;
	}
}

t_list	*git_the_big(t_list **stack_b)
{
	t_list	*tmp;
	t_list	*max;
	int		is_max;

	tmp = *stack_b;
	max = NULL;
	is_max = 0;
	while (tmp)
	{
		if (is_max == 0 || tmp->content > max->content)
		{
			max = tmp;
			is_max = 1;
		}
		tmp = tmp->next;
	}
	return (max);
}

void	increment_range(t_sort *new_sort, int size)
{
	if (new_sort->start < new_sort->end)
		new_sort->start++;
	if (new_sort->end < size - 1)
		new_sort->end++;
}

void	sorting(t_list **stack_a, t_list **stack_b, t_sort *new_sort)
{
	int	size;
	int	size_b;

	size = ft_lstsize(*stack_a);
	while (*stack_a)
	{
		if ((*stack_a)->content <= new_sort->array[new_sort->start])
		{
			pb(stack_a, stack_b);
			if (ft_lstsize(*stack_b) >= 2)
				rb(stack_b);
			increment_range(new_sort, size);
		}
		else if ((*stack_a)->content <= new_sort->array[new_sort->end])
		{
			pb(stack_a, stack_b);
			size_b = ft_lstsize(*stack_b);
			if (size_b > 1 && (*stack_b)->content < (*stack_b)->next->content)
				sb(stack_b);
			increment_range(new_sort, size);
		}
		else
			ra(stack_a);
	}
}
