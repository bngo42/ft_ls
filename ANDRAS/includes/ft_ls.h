/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acottier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 15:48:53 by acottier          #+#    #+#             */
/*   Updated: 2016/06/22 15:50:11 by acottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <stdio.h>
# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <errno.h>
# include <pwd.h>
# include <time.h>
# include <grp.h>
# include "../libft/libft.h"

typedef struct			s_arg
{
	int				sorted;
	char			*path;
	struct stat	info;
	struct s_arg	*next;
	struct s_arg	*previous;
	struct s_arg	*onext;
	struct s_arg	*oprev;
}						t_arg;

typedef	struct			s_ent
{
	char				*name;
	struct stat info;
	struct s_ent		*next;
}						t_ent;

typedef	struct			s_sizes
{
	blkcnt_t			memblocks;
	int					link_size;
	size_t				usr_size;
	size_t				grp_size;
	int					file_size;
	int					minmaj;
	char				*opts;
}						t_sizes;

void	ft_error(int	error, char **args, char errchar, int index);

char	*ft_treat_opts(char	**argv, int *err, char *errchar);
char	ft_check_opts(char *input);
char	*ft_format_opts(char	*origin);

t_arg	*ft_treat_args(char	**argv, char *opts);
t_arg	*ft_mklist(char **argv, int firstarg, char *opts);

void	ft_global_treat(char	*options, t_arg 	*arguments);
void	ft_non_recursive(char	*opts, t_arg	*args);
t_arg	*ft_sort_display(t_arg	*lst, char	*opts, t_arg	*cursor);
void	ft_print_result_list(t_arg	*lsr, char	*opts, char *origin);
void	ft_long_display(t_arg	*lst, char	*opts, int link, char *origin);
void	ft_permissions(t_arg	*link);
void	ft_format_long_output(t_arg	*lst, t_sizes *data, int link, char *dir);

void	ft_simple_output(t_arg	*args, char *opts);
void	ft_file_walkthrough(t_arg	*args, char *opts);
void	ft_dir_walkthrough(t_arg	*args);
void	ft_show_dir_content(char	*path);

void	ft_sort_ent_list(t_ent	**tmp);

void	ft_recursive(char	*options, t_arg	*args, char	*prefix);

int		ft_hidden(const char	*str);
void	ft_ent_add(t_ent	**lst, char	*name, char *prefix, char *lnk);
t_arg	*ft_arg_add(t_arg	**lst, char	*path, char	*prefix, char *opts);
t_ent	*ft_ent_create(char	*name, char *prefix, char *lnk);
t_arg	*ft_arg_create(char	*path, t_arg	*previous, t_arg	*following,
		char	*prefix);
t_arg	*ft_compare(t_arg	*lst);
void	ft_free_list(t_arg *lst);
int		ft_islink(t_arg	*arg);
void	ft_denied(char *path, int error);
t_arg	*ft_nano(t_arg *a, t_arg *b);
t_arg	*ft_endlist(t_arg *lst);
int		ft_opt_hidden(char *opts);
void	ft_color_display(t_arg *arg, char *opts);
void	ft_ent_color_display(t_ent *ent);
void	inode_align(t_arg *arg);

#endif
