/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 22:19:13 by cwu               #+#    #+#             */
/*   Updated: 2019/01/11 22:19:14 by cwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include "libft/libft.h"
# include "libft/ft_printf.h"
# include <stdbool.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <dirent.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <sys/ioctl.h>
# include <sys/xattr.h>
# include <sys/acl.h>
# define HY 15780000

bool			g_l;
bool			g_rec;
bool			g_a;
bool			g_r;
bool			g_t;
bool			g_d;
bool			g_u;
bool			g_f;
bool			g_g;
bool			g_header;
bool			g_files;
time_t			g_time;
struct winsize	g_win;

typedef struct	s_listobj
{
	char			*name;
	char			*path;
	struct stat		*st;
	char			*owner;
	char			*gp;
}				t_listobj;

typedef struct	s_ij
{
	int			i;
	int			j;
}				t_ij;

char			findtype(mode_t m);
int				numlength(int n);
void			sortfiles(t_listobj *files, int count);
void			freefiles(t_listobj *files, int count);
void			listfiles(char **args, int n, int *hc);
int				ft_ls(char *path);
int				getinfo(t_listobj *file, char *name, int *width, char *path);
void			print(t_listobj *files, int count, int *width, bool tot);
t_listobj		*setup(char *path, int *c, int *width);
char			get_ext(t_listobj *file);
int				compare(t_listobj *file1, t_listobj *file2);

#endif
