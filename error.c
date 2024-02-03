/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moer-ret <moer-ret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:06:39 by moer-ret          #+#    #+#             */
/*   Updated: 2024/01/22 18:45:29 by moer-ret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(char *err)
{
	ft_putendl_fd(err);
	exit (1);
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
