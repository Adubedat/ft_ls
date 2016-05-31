/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 17:35:46 by adubedat          #+#    #+#             */
/*   Updated: 2016/05/31 20:10:20 by adubedat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include "libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <dirent.h>
# include <sys/ioctl.h>

typedef struct		s_files
{
	char			*file_name;
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
	char			**files;
	char			**rep;
}					t_op;

t_op				get_options(int argc, char **argv);
void				sort_by_ascii(char **tab, int i);
void				print_files(t_op options);
void				print_rep(t_op options);
int					count_files(t_op, int *len);
void				initialize_options(t_op *options);
void				free_list(t_files *list);
void				free_options(t_op *options);

#endif
