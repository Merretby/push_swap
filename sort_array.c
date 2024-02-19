/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moer-ret <moer-ret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 13:59:05 by moer-ret          #+#    #+#             */
/*   Updated: 2024/02/19 17:10:08 by moer-ret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	simple_sort(t_list **stack_a, t_list **stack_b)
{
	t_sort	sort_arr;

	array_sort(&sort_arr, stack_a, stack_b);
}

int	range(t_list **stack)
{
	int	size;

	size = ft_lstsize(*stack);
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

void	back_to_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*max;
	int		size;

	while (*stack_b)
	{
		size = ft_lstsize(*stack_b);
		max = git_the_big(stack_b);
		if ((*stack_b)->content == max->content)
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
	new_sort->range = range(stack_a);
	new_sort->start = 0;
	new_sort->end = new_sort->range - 1;
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
