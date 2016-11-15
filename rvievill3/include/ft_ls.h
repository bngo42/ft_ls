/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvievill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 16:18:11 by rvievill          #+#    #+#             */
/*   Updated: 2016/06/27 15:24:17 by rvievill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <sys/stat.h>
# include <dirent.h>
# include <sys/types.h>
# include <sys/xattr.h>
# include <time.h>
# include <stdlib.h>
# include <stdio.h>
# include <uuid/uuid.h>
# include <unistd.h>
# include <string.h>
# include <errno.h>
# include <pwd.h>
# include <grp.h>
# include "../libft/libft.h"

typedef struct	s_optl
{
	int				s_major;
	int				s_minor;
	int				s_maj_min;
	int				s_acces;
	off_t			s_lnk;
	int				s_user;
	int				s_grp;
	int				s_size;
	int				s_time;
	int				s_name;
	int				s_total;
	int				all;
}				t_optl;

typedef struct	s_lst
{
	char			type;
	int				rep;
	int				pos;
	int				major;
	int				minor;
	int				error;
	char			*file;
	char			*link;
	char			*time;
	char			*dir;
	char			*optl;
	struct stat		stat;
	t_optl			*size;
	struct s_lst	*next;
}				t_lst;

void			print_color(t_lst *start, char *opt);
void			permission_denied(char *elem, char *opt);
void			time_optl(char **optl, t_lst *start, int *i);
void			lnk(char **optl, t_lst *start, int *i);
void			size(char **optl, t_lst *start, int *i, int exist);
void			user(char **optl, t_lst *start, int *i);
void			grp(char **optl, t_lst *start, int *i);
void			access_file(char **optl, t_lst *start, int *i);
void			filling_optl(t_lst *start, int exist);
void			display_l(t_lst **start, char *arg, int exist);
void			display_first_dir(char *start, int size, char **file);
void			riffle_path(char *opt, char **lst_path, char **file, int path);
void			cmp_optl(t_lst *start, t_lst *new, char *opt);
void			first_size(t_lst *cur);
void			filling_size(t_lst *cur);
void			free_tab(char **tab);
void			inser_ascii(t_lst **start, t_lst *new);
void			inser_rascii(t_lst **start, t_lst *new);
void			free_lst(t_lst *start);
void			display(char *arg, t_lst *start, int exist);
void			create_lst_f(t_lst **start, char *name, char *rep, char *opt);
void			create_lst_r(t_lst **start, char *name, char *rep, char *opt);
void			create_lst(t_lst **start, char *name, char *rep, char *opt);
void			create_lst_t(t_lst **start, char *name, char *rep, char *opt);
void			create_lst_rt(t_lst **start, char *name, char *rep, char *opt);
void			first_elem(t_lst *start);
void			sort_ascii(t_lst *start);
void			sort_rev_ascii(t_lst *start);
void			option_a(t_lst *start);
int				dir_error(char **av, char *opt);
int				b_or_c(t_lst *start);
int				lst_size(t_lst *start);
void			filling_struct(t_lst *new, char *name, char *rep, char *opt);
char			*option_in_arg(char **av);
int				size_tab(char **start);
int				size_lst(t_lst *start, char *opt);
int				bad_option(char **av);
char			**stock_file(char **av);
char			**stock_dir(char **av, char *opt);
char			**tab_name(char **tab, struct dirent *dir, int i);
char			**stock_file_l(char **av);
char			**stock_dir_l(char **av, char *opt);
t_lst			*sort_inser(t_lst *first, t_lst *curent);
t_lst			*read_dir(char *rep, char *opt);
t_lst			*lst(char **arg, char *opt);

#endif
