/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moer-ret <moer-ret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 17:52:21 by moer-ret          #+#    #+#             */
/*   Updated: 2024/02/03 15:09:59 by moer-ret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
#include <stdio.h>
# include <stdlib.h>

typedef struct s_list
{
	int				content;
	int				index;
	struct s_list	*next;
}	t_list;

void	check(int ac, char **av);
//hande error
void	print_error(char *err);
void	**ft_free(char **fr);
//utiles for help
int		ft_isdigit(int c);
int		ft_num(char *s);
long	ft_atoi(const char *str);
void	ft_putendl_fd(char *s);
char	**ft_split(char const *s, char c);
//linked list
t_list	*ft_lstnew(int content);
void	ft_lstadd_back(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);

#endif