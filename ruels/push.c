/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moer-ret <moer-ret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 10:31:14 by moer-ret          #+#    #+#             */
/*   Updated: 2024/02/23 14:49:34 by moer-ret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_print_ruls(char *s)
{
	int	i;

	i = 0;
	if (s != NULL)
	{
		while (s[i])
		{
			write(1, &s[i], 1);
			i++;
		}
		write(1, "\n", 1);
	}
}

int	ft_push(t_list **stack_x, t_list **stack_y)
{
	t_list	*tmp;

	if ((*stack_x) == NULL)
		return (-1);
	tmp = *stack_x;
	*stack_x = tmp->next;
	ft_lstadd_front(stack_y, tmp);
	return (0);
}

int	pa(t_list **stack_a, t_list **stack_b)
{
	if (ft_push(stack_b, stack_a) != -1)
		ft_print_ruls("pa");
	return (0);
}

int	pb(t_list **stack_a, t_list **stack_b)
{
	if (ft_push(stack_a, stack_b) != -1)
		ft_print_ruls("pb");
	return (0);
}
