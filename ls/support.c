/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 22:18:51 by cwu               #+#    #+#             */
/*   Updated: 2019/01/11 22:18:54 by cwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	findtype(mode_t m)
{
	if (S_ISDIR(m))
		return ('d');
	if (S_ISCHR(m))
		return ('c');
	if (S_ISBLK(m))
		return ('b');
	if (S_ISLNK(m))
		return ('l');
	if (S_ISSOCK(m))
		return ('s');
	if (S_ISFIFO(m))
		return ('p');
	return ('-');
}

int		numlength(int n)
{
	int ret;

	ret = 1;
	while (n >= 10)
	{
		n /= 10;
		ret++;
	}
	return (ret);
}

void	sortfiles(t_listobj *files, int count)
{
	t_ij		ij;
	t_listobj	tmp;

	ij.i = -1;
	while ((ij.j = ++ij.i) < count - 1)
		while (++ij.j < count)
			if (compare(&files[ij.i], &files[ij.j]) > 0)
			{
				tmp = files[ij.i];
				files[ij.i] = files[ij.j];
				files[ij.j] = tmp;
			}
}

void	freefiles(t_listobj *files, int count)
{
	int i;

	i = -1;
	while (++i < count)
	{
		free(files[i].name);
		free(files[i].path);
		free(files[i].st);
		if (g_l)
		{
			free(files[i].owner);
			free(files[i].gp);
		}
	}
	free(files);
}

void	listfiles(char **args, int n, int *hc)
{
	int			i;
	t_listobj	*files;
	DIR			*dir;
	int			count;
	int			width[5];

	count = 0;
	files = malloc(sizeof(t_listobj));
	ft_bzero(width, sizeof(int) * 5);
	i = -1;
	while (++i < n)
	{
		if (!g_d && (dir = opendir(args[i])) && !closedir(dir))
			(*hc)++;
		else
		{
			files = realloc(files, sizeof(t_listobj) * (count + 1));
			if (getinfo(&files[count], args[i], width, args[i]) == 0)
				count++;
		}
	}
	if (count > 0 && ((*hc)++) != -1)
		print(files, count, &width[0], 0);
	freefiles(files, count);
}
