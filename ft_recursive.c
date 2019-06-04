/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 15:41:43 by viforget          #+#    #+#             */
/*   Updated: 2019/06/04 19:34:20 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			ft_freeitab(char ***itab)
{
	int i;

	i = 0;
	while (i < 8)
	{
		free(itab[0][i]);
		i++;
	}
	free(itab[0]);
	free(itab);
}

/*
** find every subdirectory and return a tab
*/

struct	dirent	**ft_rec(int ct, DIR *dir)
{
	struct dirent *rep;
	struct dirent **trep;

	rep = readdir(dir);
	if (rep)
	{
		trep = ft_rec(ct + 1, dir);
		trep[ct] = rep;
		return (trep);
	}
	else
	{
		trep = ft_memalloc(sizeof(struct dirent *) * (ct + 1));
		trep[ct] = NULL;
		return (trep);
	}
}

/*
** is recursive with ft_ls
** find every sub directory and call ft_ls for each
*/

void			ft_recursive_ls(char *s, int fg)
{
	DIR				*dir;
	struct dirent	**trep;
	size_t			ct;

	ct = 0;
	dir = opendir(s);
	s[ft_strlen(s) - 1] != '/' ? s = ft_strjoindel(s, "/") : 0;
	readdir2(dir);
	trep = ft_rec(0, dir);
	if (trep[0] != NULL)
		ft_sort_tab_dir(trep, fg);
	while (trep[ct])
	{
		if (trep[ct]->d_type == 4 && !(fg % 2 != 0
					&& trep[ct]->d_name[0] == '.') && trep[ct]->d_name[0] > 31)
		{
			ft_putchar('\n');
			ft_ls((fg % 13 == 0) ? fg : fg * 13,
				ft_strjoin(s, trep[ct]->d_name));
		}
		ct++;
	}
	(!s) ? 1 : ft_strdel(&s);
	ft_memdel((void **)&trep);
	closedir(dir);
}
