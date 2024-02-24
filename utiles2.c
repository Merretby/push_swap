/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moer-ret <moer-ret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 18:16:54 by moer-ret          #+#    #+#             */
/*   Updated: 2024/02/23 18:19:32 by moer-ret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int c)
{
	if ((c >= '0' && c <= '9'))
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

int	ft_strncmp(char *str1, char *str2, int n)
{
	int		i;
	char	*s1;
	char	*s2;

	i = 0;
	s1 = str1;
	s2 = str2;
	if (s1 == NULL || s2 == NULL)
		return (0);
	while (i < n && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}
