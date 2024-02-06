/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moer-ret <moer-ret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:07:46 by moer-ret          #+#    #+#             */
/*   Updated: 2024/02/05 16:15:52 by moer-ret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_dobel(int nb, char **tmp, int index)
{
	index++;
	while (tmp[index])
	{
		if (nb == ft_atoi(tmp[index]))
			return (1);
		index++;
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

	i = 0;
	if (ac == 2)
		tmp = ft_split(av[1], ' ');
	else
	{
		tmp = av;
		i++;
	}
	while (tmp[i])
	{
		nb = ft_atoi(tmp[i]);
		if (check_dobel(nb, tmp, i))
			print_error("Error");
		if (!ft_num(tmp[i]))
			print_error("Error");
		if (nb > 2147483647 && nb < -2147483648)
			print_error("Error");
		i++;
	}
	if (ac == 2)
		ft_free(tmp);
}
