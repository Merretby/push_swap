/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moer-ret <moer-ret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 17:49:05 by moer-ret          #+#    #+#             */
/*   Updated: 2024/02/16 21:57:52 by moer-ret         ###   ########.fr       */
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
		if (head->index == -1 && (is_min == 0 ||head->content < min->content))
		{
			min = head;
			is_min = 1;
		}
		head = head->next;
	}
	return (min);
}

void	index_of_stack(t_list **stack)
{
	t_list	*min;
	int		i;

	i = 0;
	min = find_min(stack);
	while (min)
	{
		min->index = i++;
		min = find_min(stack);
	}
}

void	creat_list(int ac, char **av, t_list **stack_a)
{
	int		i;
	char	**tmp;
	t_list	*node;

	i = 0;
	if (ac == 2)
		tmp = ft_split(av[1], ' ');
	else
	{
		i++;
		tmp = av;
	}
	while (tmp[i])
	{
		node = ft_lstnew(ft_atoi(tmp[i]));
		ft_lstadd_back(stack_a, node);
		i++;
	}
	index_of_stack(stack_a);
	if (ac == 2)
		ft_free(tmp);
}

void print_list(t_list *head) 
{
	printf("LIST => \n");
    while (head != NULL) {
        printf("Content: %d, Index: %d\n", head->content, head->index);
        head = head->next;
    }
	printf("\n\n");
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
	creat_list(ac, av, stack_a);
	if (cheack_sorted(stack_a))
		exit (0);
	sort_stack(stack_a, stack_b);
	print_list(*stack_b);
	print_list(*stack_a);
	free_stack(stack_a);
	free_stack(stack_b);
}
