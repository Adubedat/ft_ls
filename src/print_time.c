/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubedat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 16:57:28 by adubedat          #+#    #+#             */
/*   Updated: 2016/09/26 18:16:14 by adubedat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_time(t_files *tmp)
{
	char	*temp;
	char	*time_char;
	time_t	actual_date;

	actual_date = time(NULL);
	temp = ctime(&(tmp->check.st_mtime));
	time_char = ft_strsub(temp, 4, 7);
	if (actual_date - tmp->check.st_mtimespec.tv_sec > 15790000)
		time_char = ft_strjoin_free_s1(time_char, ft_strsub(temp, 19, 5));
	else
		time_char = ft_strjoin_free_s1(time_char, ft_strsub(temp, 11, 5));
	ft_printf("%s ", time_char);
	free(time_char);
}

void	print_name(t_files *tmp)
{
	if (tmp->type == 3 || tmp->type == 4)
		ft_printf("%s -> %s\n", tmp->file_name, tmp->link);
	else
		ft_printf("%s\n", tmp->file_name);
}
