/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moer-ret <moer-ret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:07:46 by moer-ret          #+#    #+#             */
/*   Updated: 2024/02/19 15:52:57 by moer-ret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_dobel(int nb, t_list **stack)
{
	t_list *tmp;

	tmp = *stack;
	while (tmp)
	{
		if (nb == tmp->content)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	ft_num(char *s)
{
	int	i;

	i = 0;
	if (s[0] == '-')
		i++;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

void	check(int ac, char **av)
{
	int		i;
	long	nb;
	char	**tmp;
	int		j;

	i = 1;
	while (i < ac)
	{
		tmp = ft_split(av[i], ' ');
		j = 0; 
		while (tmp[j])
		{
			nb = ft_atoi(tmp[j]);
			if (!ft_num(tmp[j]))
				print_error("Error");
			if (nb > 2147483647 || nb < -2147483648)
				print_error("Error");
			j++;
		}
		ft_free(tmp);
		i++;
	}
}
