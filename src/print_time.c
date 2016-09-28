/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 16:57:28 by adubedat          #+#    #+#             */
/*   Updated: 2016/09/28 17:59:45 by adubedat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_time(t_files *tmp, t_op options)
{
	char	*temp;
	char	*time_char;
	time_t	actual_date;

	actual_date = time(NULL);
	if (options.u == 0 && options.c == 0)
		temp = ctime(&(tmp->check.st_mtime));
	else if (options.u == 1 && options.c  == 0)
		temp = ctime(&(tmp->check.st_atime));
	else if (options.u == 0 && options.c == 1)
		temp = ctime(&(tmp->check.st_ctime));
	time_char = ft_strsub(temp, 4, 7);
	if (actual_date - tmp->check.st_mtimespec.tv_sec > 15790000)
		time_char = ft_strjoin_free_s1(time_char, ft_strsub(temp, 19, 5));
	else
		time_char = ft_strjoin_free_s1(time_char, ft_strsub(temp, 11, 5));
	ft_printf("%s ", time_char);
	free(time_char);
}

void	print_name(t_files *tmp, t_op options)
{
	if (tmp->type == 3 || tmp->type == 4)
	{
		ft_printf("%s -> %s\n", tmp->file_name, tmp->link);
		free(tmp->link);
	}
	else if (options.p == 1 && tmp->type == 0)
		ft_printf("%s/\n", tmp->file_name);
	else
		ft_printf("%s\n", tmp->file_name);
}
