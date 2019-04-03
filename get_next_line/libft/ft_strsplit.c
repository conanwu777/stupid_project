/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 00:04:33 by cwu               #+#    #+#             */
/*   Updated: 2018/04/17 00:04:34 by cwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	cw(char const *s, char c)
{
	int start;
	int count;

	count = 0;
	while (*s)
	{
		start = 1;
		while (*s && *s == c)
		{
			start = 0;
			s++;
		}
		while (*s && *s != c)
		{
			start = 1;
			s++;
		}
		(start ? count++ : 1);
	}
	return (count);
}

static int	length(char const *s, char c, int i)
{
	size_t l;

	l = 0;
	while (s[i] && s[i] != c)
	{
		l++;
		i++;
	}
	return (l);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**r;
	size_t	i;
	int		j;

	if (!s || !(r = (char**)malloc(sizeof(char*) * (cw(s, c) + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (j < cw(s, c))
	{
		while (s[i] == c && s[i])
			i++;
		r[j] = ft_strsub(s, i, length(s, c, i));
		j++;
		i += length(s, c, i);
	}
	r[j] = 0;
	return (r);
}
