/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moer-ret <moer-ret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:06:39 by moer-ret          #+#    #+#             */
/*   Updated: 2024/02/24 14:19:21 by moer-ret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(char *err, char **tmp)
{
	ft_putstr(err);
	ft_free(tmp);
	exit (1);
}

void	error(char *err)
{
	ft_putstr(err);
	exit (1);
}

void	bonus_error(char *err, t_list **stack_a, t_list **stack_b)
{
	ft_putstr(err);
	free_stack(stack_a);
	free_stack(stack_b);
	exit (1);
}

void	free_stack(t_list **stack)
{
	t_list	*head;
	t_list	*tmp;

	head = *stack;
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
	free(stack);
}

void	**ft_free(char **fr)
{
	size_t	i;

	i = 0;
	while (fr[i])
	{
		free(fr[i]);
		i++;
	}
	free (fr);
	return (0);
}
