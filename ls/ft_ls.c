/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 22:18:23 by cwu               #+#    #+#             */
/*   Updated: 2019/01/11 22:18:25 by cwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	checkrecurse(t_listobj *files, int count)
{
	int i;

	if (g_rec)
	{
		g_header = true;
		i = -1;
		while (++i < count)
			if (ft_strcmp(files[i].name, ".") && ft_strcmp(files[i].name, "..")
			&& S_ISDIR(files[i].st->st_mode))
				ft_ls(files[i].path);
	}
}

int		ft_ls(char *path)
{
	int			count;
	int			width[5];
	t_listobj	*files;

	count = 0;
	files = setup(path, &count, &width[0]);
	if (!g_f)
		sortfiles(files, count);
	print(files, count, &width[0], 1);
	checkrecurse(files, count);
	freefiles(files, count);
	return (0);
}

int		ls_files(char **args, int n)
{
	int i;
	int header_count;
	DIR	*dir;

	header_count = 0;
	listfiles(args, n, &header_count);
	if (header_count > 1)
		g_header = true;
	i = -1;
	while (!g_d && ++i < n)
		if ((dir = opendir(args[i])) && !closedir(dir))
			ft_ls(args[i]);
	return (0);
}

void	get_flag(char c)
{
	if (c == 'l')
		g_l = true;
	else if (c == 'R')
		g_rec = true;
	else if (c == 'a')
		g_a = true;
	else if (c == 'r')
		g_r = true;
	else if (c == 't')
		g_t = true;
	else if (c == 'd')
		g_d = true;
	else if (c == 'u')
		g_u = true;
	else if (c == 'f')
		g_f = true;
	else if (c == 'g')
		g_g = true;
	else
	{
		ft_printf("{O}Usage: ft_ls [-Ralrtufgd]\n");
		exit(1);
	}
}

int		main(int ac, char **av)
{
	t_ij ij;
	char *base;

	base = ".";
	time(&g_time);
	ioctl(0, TIOCGWINSZ, &g_win);
	while (++ij.i < ac)
	{
		if (av[ij.i][0] != '-')
			return (ls_files(&av[ij.i], ac - ij.i));
		ij.j = 0;
		while (av[ij.i][++ij.j])
			get_flag(av[ij.i][ij.j]);
		if (g_f)
			g_a = true;
		if (g_g)
			g_l = true;
	}
	if (g_d)
		return (ls_files(&base, 1));
	return (ft_ls(base));
}
