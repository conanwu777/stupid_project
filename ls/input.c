/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 22:18:32 by cwu               #+#    #+#             */
/*   Updated: 2019/01/11 22:18:34 by cwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			compare(t_listobj *file1, t_listobj *file2)
{
	int ret;

	if (g_t)
	{
		if (g_u)
			ret = file2->st->st_atime - file1->st->st_atime;
		else
			ret = file2->st->st_mtime - file1->st->st_mtime;
	}
	else
		ret = ft_strcmp(file1->name, file2->name);
	if (g_r)
		ret *= -1;
	return (ret);
}

void		fillstat(t_listobj *file, int *width)
{
	int t;

	if ((t = numlength(file->st->st_nlink)) > width[1])
		width[1] = t;
	if ((t = numlength(file->st->st_size)) > width[4])
		width[4] = t;
	file->owner = ft_strdup(getpwuid(file->st->st_uid)->pw_name);
	if ((t = (int)ft_strlen(file->owner)) > width[2])
		width[2] = t;
	file->gp = ft_strdup(getgrgid(file->st->st_gid)->gr_name);
	if ((t = (int)ft_strlen(file->gp)) > width[3])
		width[3] = t;
}

int			getinfo(t_listobj *file, char *name, int *width, char *path)
{
	file->name = ft_strdup(name);
	if ((int)ft_strlen(file->name) > width[0])
		width[0] = ft_strlen(file->name);
	if (!ft_strcmp(name, path))
		file->path = ft_strdup(path);
	else
	{
		file->path = malloc(ft_strlen(path) + ft_strlen(file->name) + 2);
		ft_strcpy(file->path, path);
		file->path[ft_strlen(path)] = '/';
		ft_strcpy(&file->path[ft_strlen(path) + 1], file->name);
		file->path[ft_strlen(path) + ft_strlen(file->name) + 1] = 0;
	}
	file->st = malloc(sizeof(struct stat));
	if (lstat(file->path, file->st) == -1)
	{
		ft_printf("{O}ft_ls: %s: No such file or directory\n", path);
		free(file->st);
		free(file->name);
		free(file->path);
		return (-1);
	}
	if (g_l)
		fillstat(file, width);
	return (0);
}

t_listobj	*setup(char *path, int *c, int *width)
{
	t_listobj		*files;
	DIR				*dir;
	struct dirent	*entry;

	files = malloc(sizeof(t_listobj));
	if (!(dir = opendir(path)))
	{
		ft_printf("{O}ft_ls: %s: No such file or directory\n", path);
		exit(1);
	}
	if (g_header)
		ft_printf("{W}\n%s:\n", path);
	ft_bzero(width, sizeof(int) * 5);
	while ((entry = readdir(dir)))
	{
		if (!g_a && entry->d_name[0] == '.')
			continue ;
		files = realloc(files, sizeof(t_listobj) * (1 + *c));
		getinfo(&files[*c], entry->d_name, width, path);
		(*c)++;
	}
	closedir(dir);
	return (files);
}

char		get_ext(t_listobj *file)
{
	acl_t		acl;
	acl_entry_t	entry;
	ssize_t		xattr;
	char		c;

	xattr = 0;
	acl = acl_get_link_np(file->path, ACL_TYPE_EXTENDED);
	if (acl && acl_get_entry(acl, ACL_FIRST_ENTRY, &entry) == -1)
	{
		acl_free(acl);
		acl = NULL;
	}
	xattr = listxattr(file->path, NULL, 0, XATTR_NOFOLLOW);
	if (xattr > 0)
		c = '@';
	else if (acl != NULL)
		c = '+';
	else
		c = ' ';
	return (c);
}
