/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 17:35:46 by adubedat          #+#    #+#             */
/*   Updated: 2016/09/26 17:59:37 by adubedat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include "libft.h"
# include <errno.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <dirent.h>
# include <sys/ioctl.h>
# include <grp.h>
# include <pwd.h>

typedef struct		s_files
{
	char			*file_name;
	char			*link;
	int				type;
	struct stat		check;
	struct group	*gid;
	struct passwd	*uid;
	struct s_files	*next;
}					t_files;

typedef struct		s_options
{
	int				l;
	int				r;
	int				maj_r;
	int				a;
	int				t;
	int				maj_g;
	int				u;
	int				f;
	int				g;
	int				d;
	int				flag;
	char			*path;
	t_files			*files;
}					t_op;

typedef struct		s_len
{
	int				blk;
	int				lnk;
	int				owner;
	int				group;
	int				bytes;
	int				minor;
	int				major;
}					t_len;

t_op				get_options(int argc, char **argv);
void				create_new_elem(t_op *options, char *name);
void				sort(t_op *options);
void				print_files(t_op options);
void				print_type(t_files *tmp);
void				print_time(t_files *tmp);
void				print_name(t_files *tmp);
void				print_files_l(t_op options);
void				copy_options(t_op *o, t_op options, char *name);
void				print_rep(t_op options);
int					count_files(t_op options, int *len);
void				free_options(t_op *options);
void				insert_sorted(t_files **new, t_files *elem);
void				insert_revert_sorted(t_files **new, t_files *elem);
void				insert_time_sorted(t_files **new, t_files *elem);
void				insert_revert_time(t_files **new, t_files *elem);

#endif
