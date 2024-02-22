/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moer-ret <moer-ret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 18:13:29 by moer-ret          #+#    #+#             */
/*   Updated: 2024/02/22 17:50:45 by moer-ret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atoi(const char *str)
{
	int		i;
	long	res;
	long	signe;

	i = 0;
	res = 0;
	signe = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			signe = -1;
		i++;
		if (str[i] == '+' || str[i] == '-' || str[i] == '\0')
			return (2147483649);
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if ((res * 10) > 2147483647)
			return (2147483649);
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res * signe);
}
	
void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (s != NULL)
	{
		while (s[i])
		{
			write(2, &s[i], 1);
			i++;
		}
		write(2, "\n", 1);
	}
}

static char	*small_alloc(char const *str, int *index, char separator)
{
	char	*ptr;
	int		len;
	int		pos;
	int		k;

	len = 0;
	while (str[*index] == separator && str[*index])
		(*index)++;
	pos = *index;
	while (str[*index] != separator && str[*index])
		(*index)++;
	len = *index - pos;
	ptr = malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (*ft_free(&ptr));
	k = 0;
	while (k < len)
	{
		ptr[k] = str[pos];
		k++;
		pos++;
	}
	ptr[k] = '\0';
	return (ptr);
}

static int	count_words(char const *str, char c)
{
	size_t	wo;
	size_t	i;

	wo = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i])
			wo++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (wo);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	int		i;
	int		count;
	int		j;

	j = 0;
	if (s == NULL)
		return (NULL);
	count = count_words(s, c);
	ptr = (char **)malloc(sizeof(char *) * (count + 1));
	if (!ptr)
		return (NULL);
	ptr[count] = NULL;
	i = 0;
	while (j < count)
	{
		ptr[j] = small_alloc(s, &i, c);
		j++;
	}
	return (ptr);
}
