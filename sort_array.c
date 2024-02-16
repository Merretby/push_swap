/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moer-ret <moer-ret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 13:59:05 by moer-ret          #+#    #+#             */
/*   Updated: 2024/02/16 21:37:15 by moer-ret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	simple_sort(t_list **stack_a, t_list **stack_b)
{
	t_sort sort_arr;

	array_sort(&sort_arr, stack_a,stack_b);
}

int	range(t_list **stack)
{
	int	size = ft_lstsize(*stack);
	if (size >= 6 && size <= 18)
		return (3);
	else if (size <= 100)
		return (10);
	else if (size <= 500)
		return (20);
	else 
		return (40);

}

void	bubble_sort(t_sort *new_sort, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < i)
		{
			if (new_sort->array[i] < new_sort->array[j])
			{
				tmp = new_sort->array[i];
				new_sort->array[i] = new_sort->array[j];
				new_sort->array[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

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
		if(is_max == 0 || tmp->content > max->content)
		{
			max = tmp;
			is_max = 1;
		}
		tmp = tmp->next;
	}
	return (max);
}

void	back_to_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*max;
	int 	size;

	while (*stack_b)
	{
		size = ft_lstsize(*stack_b);
		max = git_the_big(stack_b);
		if((*stack_b)->content == max->content)
			pa(stack_a, stack_b);
		else if (max->index < (size / 2))
			rb(stack_b);
		else
			rrb(stack_b);
		index_of_b(stack_b);
	}
}

void	array_sort(t_sort *new_sort, t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	int		i;
	int		j;

	i = 0;
	tmp = *stack_a;
	j = ft_lstsize(*stack_a);
	new_sort->Range = range(stack_a);
	new_sort->start = 0;
	new_sort->end = new_sort->Range - 1;
	new_sort->array = malloc(sizeof(int) * j);
	if (!new_sort->array)
		exit (1);
	while (tmp)
	{
		new_sort->array[i] = tmp->content;
		tmp = tmp->next;
		i++;
 	}
	bubble_sort(new_sort, j);
	sorting(stack_a, stack_b, new_sort);
	index_of_b(stack_b);
	back_to_a(stack_a, stack_b);
	free (new_sort->array);
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
	int size;
	int size_b;

	size = ft_lstsize(*stack_a);
	while (*stack_a)
	{
		if((*stack_a)->content <= new_sort->array[new_sort->start])
		{
			pb(stack_a, stack_b);
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
