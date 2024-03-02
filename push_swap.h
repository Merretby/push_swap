/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moer-ret <moer-ret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 17:52:21 by moer-ret          #+#    #+#             */
/*   Updated: 2024/02/29 14:41:13 by moer-ret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "bonus/get_next_line_bonus.h"

typedef struct s_list
{
	int				content;
	int				index;
	struct s_list	*next;
}	t_list;

typedef struct s_sort
{
	int	start;
	int	end;
	int	range;
	int	*array;
}	t_sort;

//hande error
void	check(int ac, char **av);
void	error(char *err);
void	print_error(char *err, char **tmp);
void	**ft_free(char **fr);
void	free_stack(t_list **stack);
void	bonus_error(char *err, t_list **stack_a, t_list **stack_b);
//utiles for help
t_list	*find_min(t_list **stack);
void	index_of_stack(t_list **stack);
int		ft_isdigit(int c);
int		ft_num(char *s);
long	ft_atoi(const char *str);
void	ft_putstr(char *s);
int		check_dobel(int nb, t_list **stack);
char	**ft_split(char const *s, char c);
int		the_min(t_list **stack, int i);
int		track_index_min(t_list **stack, int i);
t_list	*git_the_big(t_list **stack_b);
void	index_of_b(t_list **stack_b);
int		ft_strcmp(char *str1, char *str2);
//linked list
t_list	*ft_lstnew(int content);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
//rules push_swap
int		ft_swap(t_list **stack);
int		sa(t_list **stack);
int		sb(t_list **stack);
int		ss(t_list **stack_a, t_list **stack_b);
int		ft_push(t_list **stack_x, t_list **stack_y);
int		pa(t_list **stack_a, t_list **stack_b);
int		pb(t_list **stack_a, t_list **stack_b);
int		ft_rotate(t_list **stack);
int		ra(t_list **stack_a);
int		rb(t_list **stack_b);
int		rr(t_list **stack_a, t_list **stack_b);
int		reverse_rotate(t_list **stack);
int		rra(t_list **stack_a);
int		rrb(t_list **stack_b);
int		rrr(t_list **stack_a, t_list **stack_b);
void	ft_print_ruls(char *s);
void	print_res(t_list **stack_a, t_list **stack_b);
int		ft_rules_2(char *buffer, t_list **stack_a, t_list **stack_b);
//sort
int		cheack_sorted(t_list **stack);
void	sort_stack(t_list **stack_a, t_list **stack_b);
void	sort(t_list **stack_a, t_list **stack_b);
void	simple_sort(t_list **stack_a, t_list **stack_b);
void	array_sort(t_sort *new_sort, t_list **stack_a, t_list **stack_b);
void	sorting(t_list **stack_a, t_list **stack_b, t_sort *new_sort);

#endif