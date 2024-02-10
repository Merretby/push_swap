/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moer-ret <moer-ret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 13:59:05 by moer-ret          #+#    #+#             */
/*   Updated: 2024/02/10 20:25:45 by moer-ret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	simple_sort(t_list **stack_a)
{
	t_sort sort_arr;

	array_sort(&sort_arr, stack_a);
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

void	sorting_array(t_sort *new_sort, int size)
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

void	array_sort(t_sort *new_sort, t_list **stack)
{
	t_list	*tmp;
	int		i;
	int		j;

	i = 0;
	tmp = *stack;
	j = ft_lstsize(*stack);
	new_sort->Range = range(stack);
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
	sorting_array(new_sort, j);
}
