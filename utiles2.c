/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moer-ret <moer-ret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 18:16:54 by moer-ret          #+#    #+#             */
/*   Updated: 2024/02/17 10:29:17 by moer-ret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	track_index_min(t_list **stack, int i)
{
	t_list	*head;
	int		track;

	head = *stack;
	track = 0;
	while (head)
	{
		if (head->index == i)
			break ;
		track++;
		head = head->next;
	}
	return (track);
}

int	the_min(t_list **stack, int i)
{
	t_list	*head;
	int		value;

	head = *stack;
	value = head->index;
	while (head->next)
	{
		head = head->next;
		if (head->index < value && head->index != i)
			value = head->index;
	}
	return (value);
}

int	cheack_sorted(t_list **stack)
{
	t_list	*head;

	head = *stack;
	while (head && head->next)
	{
		if (head->content > head->next->content)
			return (0);
		head = head->next;
	}
	return (1);
}
