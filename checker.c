/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moer-ret <moer-ret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 13:53:20 by moer-ret          #+#    #+#             */
/*   Updated: 2024/02/24 15:27:37 by moer-ret         ###   ########.fr       */
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

int	ft_rules(char *buffer, t_list **stack_a, t_list **stack_b)
{
	if (!ft_strncmp(buffer, "sa\n", 3))
		ft_swap(stack_a);
	else if (!ft_strncmp(buffer, "sb\n", 3))
		ft_swap(stack_b);
	else if (!ft_strncmp(buffer, "ss\n", 3) && !ft_swap(stack_a))
		ft_swap(stack_b);
	else if (!ft_strncmp(buffer, "pa\n", 3))
		ft_push(stack_b, stack_a);
	else if (!ft_strncmp(buffer, "pb\n", 3))
		ft_push(stack_a, stack_b);
	else if (!ft_strncmp(buffer, "ra\n", 3))
		ft_rotate(stack_a);
	else if (!ft_strncmp(buffer, "rb\n", 3))
		ft_rotate(stack_b);
	else if (!ft_strncmp(buffer, "rr\n", 3) && !ft_rotate(stack_a))
		ft_rotate(stack_b);
	else if (!ft_strncmp(buffer, "rra\n", 4))
		reverse_rotate(stack_a);
	else if (!ft_strncmp(buffer, "rrb\n", 4))
		reverse_rotate(stack_b);
	else if (!ft_strncmp(buffer, "rrr\n", 4) && !reverse_rotate(stack_a))
		reverse_rotate(stack_b);
	else
		return (-1);
	return (0);
}

int	main(int ac, char **av)
{
	t_list	**stack_a;
	t_list	**stack_b;
	char	*buffer;

	if (ac < 2)
		exit (1);
	check(ac, av);
	stack_a = malloc(sizeof(t_list *));
	stack_b = malloc(sizeof(t_list *));
	*stack_a = NULL;
	*stack_b = NULL;
	creat_list(ac, av, stack_a, stack_b);
	buffer = get_next_line(0);
	while (buffer)
	{
		if (ft_rules(buffer, stack_a, stack_b) == -1)
		{
			free (buffer);
			bonus_error("Error", stack_a, stack_b);
		}
		free(buffer);
		buffer = get_next_line(0);
	}
	print_res(stack_a, stack_b);
}
