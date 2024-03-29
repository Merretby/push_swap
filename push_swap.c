/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moer-ret <moer-ret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 17:49:05 by moer-ret          #+#    #+#             */
/*   Updated: 2024/03/01 14:02:32 by moer-ret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*find_min(t_list **stack)
{
	t_list	*min;
	t_list	*head;
	int		is_min;

	is_min = 0;
	head = *stack;
	min = NULL;
	if (head == NULL)
		return (min);
	while (head)
	{
		if (head->index == -1 && (is_min == 0 || head->content < min->content))
		{
			min = head;
			is_min = 1;
		}
		head = head->next;
	}
	return (min);
}

void	creat_list(int ac, char **av, t_list **stack_a, t_list **stack_b)
{
	char	**tmp;
	int		i;
	int		j;
	t_list	*node;

	i = 1;
	while (i < ac)
	{
		tmp = ft_split(av[i], ' ');
		j = 0;
		while (tmp[j])
		{
			if (check_dobel(ft_atoi(tmp[j]), stack_a))
			{
				free_stack (stack_a);
				free_stack (stack_b);
				print_error("Error", tmp);
			}
			node = ft_lstnew(ft_atoi(tmp[j++]));
			ft_lstadd_back(stack_a, node);
		}
		ft_free(tmp);
		i++;
	}
	index_of_stack(stack_a);
}

int	main(int ac, char **av)
{
	t_list	**stack_a;
	t_list	**stack_b;

	if (ac < 2)
		exit (1);
	check(ac, av);
	stack_a = malloc(sizeof(t_list *));
	stack_b = malloc(sizeof(t_list *));
	if (!stack_a || !stack_b)
		exit (1);
	*stack_a = NULL;
	*stack_b = NULL;
	creat_list(ac, av, stack_a, stack_b);
	if (cheack_sorted(stack_a))
	{
		free_stack(stack_a);
		free_stack(stack_b);
		exit (0);
	}
	sort_stack(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
}
