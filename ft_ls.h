/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bngo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 15:28:46 by bngo              #+#    #+#             */
/*   Updated: 2016/09/28 18:13:46 by bngo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <dirent.h>
# include <sys/stat.h>
# include <grp.h>
# include <sys/types.h>
# include <sys/xattr.h>
# include <pwd.h>
# include <time.h>

# define RED "\x1B[31m"
# define GRN "\x1B[32m"
# define YEL "\x1B[33m"
# define BLU "\x1B[34m"
# define END "\x1B[0m"

# define DBUG write(1, "DEBUG1\n", 7);
# define DBUG2 write(1, "DEBUG2\n", 7);
# define DBUG3 write(1, "DEBUG3\n", 7);

typedef struct		s_file
{
	char			*name;
	char			*path;
	unsigned char	type;
	struct stat		info;
	struct s_file	*next;
	struct s_file	*prev;
}					t_file;

#endif
