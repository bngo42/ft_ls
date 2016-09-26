/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bngo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 15:28:46 by bngo              #+#    #+#             */
/*   Updated: 2016/09/26 18:38:01 by bngo             ###   ########.fr       */
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
# include <sys/xattr.h>
# include <pwd.h>
# include <time.h>

# define RED "\x1B[34m"
# define END "\x1B[0m"

typedef struct		s_file
{
	char			*name;
	time_t			*date;
	dev_t			*dev_info;
	int				size;
	struct s_file	*next;
	struct s_file	*prev;
}					t_file;

#endif
