/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 17:35:46 by adubedat          #+#    #+#             */
/*   Updated: 2016/04/26 16:22:05 by adubedat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include "libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <dirent.h>

typedef struct	s_options
{
	int			l;
	int			r;
	int			R;
	int			a;
	int			t;
	int			G;
	int			u;
	int			f;
	int			g;
	int			d;
	char		**files;
}				t_options;

t_options		get_options(int argc, char **argv);

#endif
