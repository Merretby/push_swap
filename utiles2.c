/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moer-ret <moer-ret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 18:16:54 by moer-ret          #+#    #+#             */
/*   Updated: 2024/02/08 15:53:36 by moer-ret         ###   ########.fr       */
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

int	cheack_sorted(t_list **stack)
{
	t_list *head;

	head = *stack;
	while (head && head->next)
	{
		if(head->content > head->next->content)
			return (0);
		head = head ->next;
	}
	return (1);
}