/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 22:18:41 by cwu               #+#    #+#             */
/*   Updated: 2019/01/11 22:18:42 by cwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

const char *g_mode = "-rwxrwxrwx";

void	finishprint(t_listobj *file)
{
	int		j;
	char	buf[NAME_MAX];

	if (S_ISDIR(file->st->st_mode))
		ft_printf("{Y}%s", file->name);
	else if (S_IXUSR & file->st->st_mode)
		ft_printf("{R}%s", file->name);
	else
		ft_printf("{LG}%s", file->name);
	if (!S_ISLNK(file->st->st_mode))
		ft_printf("\n");
	else
	{
		j = readlink(file->path, buf, NAME_MAX);
		buf[j] = 0;
		ft_printf(" -> %s\n", buf);
	}
}

void	printl(t_listobj *file, int *width)
{
	int		j;
	char	*mode;
	char	**time;

	mode = ft_strdup(g_mode);
	mode[0] = findtype(file->st->st_mode);
	time = ft_strsplit((g_u ? ctime(&file->st->st_atime)
		: ctime(&file->st->st_mtime)), ' ');
	time[3][5] = 0;
	time[4][4] = 0;
	j = 0;
	while (++j <= 9)
		if (!(file->st->st_mode & (1 << (9 - j))))
			mode[j] = '-';
	ft_printf("%s%c %*d ", mode, get_ext(file), width[1], file->st->st_nlink);
	g_g ? 1 : ft_printf("%-*s  ", width[2], file->owner);
	ft_printf("%-*s  %*d %s %2s %5s ", width[3], file->gp, width[4],
		file->st->st_size, time[1], time[2],
		time[g_time - file->st->st_mtime > HY ? 4 : 3]);
	finishprint(file);
	free(mode);
	j = -1;
	while (time[++j])
		free(time[j]);
	free(time);
}

void	printlloop(t_listobj *files, int count, int *width, bool tot)
{
	int i;
	int total;

	if (tot)
	{
		total = 0;
		i = -1;
		while (++i < count)
			total += files[i].st->st_size;
		total /= 512;
		if (total)
		{
			total += 2;
			ft_printf("total %d\n", total);
		}
	}
	i = -1;
	while (++i < count)
		printl(&files[i], width);
}

void	printloop(t_listobj *files, int count, int *width)
{
	int i;
	int w;
	int c;

	w = g_win.ws_col / (width[0] + 1);
	c = w;
	i = -1;
	while (++i < count)
	{
		if (S_ISDIR(files[i].st->st_mode))
			ft_printf("{Y}%-*s", width[0], files[i].name);
		else if (S_IXUSR & files[i].st->st_mode)
			ft_printf("{R}%-*s", width[0], files[i].name);
		else
			ft_printf("{LG}%-*s", width[0], files[i].name);
		c--;
		if (c == 0 && (c = w) == w)
			ft_printf("\n");
		else
			ft_printf(" ");
	}
	if (c != 0)
		ft_printf("\n");
}

void	print(t_listobj *files, int count, int *width, bool tot)
{
	if (g_l)
		printlloop(files, count, &width[0], tot);
	else
		printloop(files, count, &width[0]);
}
