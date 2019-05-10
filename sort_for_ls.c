/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_for_ls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 21:50:42 by viforget          #+#    #+#             */
/*   Updated: 2019/05/10 13:01:54 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_sort_tab_dir(struct dirent **tr, int flag)
{
	int				j;
	struct dirent	*st;

	j = 0;
	while (tr[j + 1])
	{
		if ((ft_strcmp(tr[j]->d_name, tr[j + 1]->d_name) > 0 && flag % 5 != 0)
				|| (ft_strcmp(tr[j]->d_name, tr[j + 1]->d_name) < 0
					&& flag % 5 == 0))
		{
			st = tr[j];
			tr[j] = tr[j + 1];
			tr[j + 1] = st;
			j = 0;
		}
		else
		{
			j++;
		}
	}
}

void	ft_sort_ls_t(char **tab, size_t i, size_t ct)
{
	size_t		j;
	char		*st;
	struct stat	bf1;
	struct stat	bf2;

	j = i;
	while (j - i < ct && tab[j + 1])
	{
		stat(tab[j], &bf1);
		stat(tab[j + 1], &bf2);
		if (bf1.st_mtime < bf2.st_mtime)
		{
			st = tab[j];
			tab[j] = tab[j + 1];
			tab[j + 1] = st;
			j = i;
		}
		else
			j++;
	}
}

void	ft_sort_ls(char **tab, size_t i, size_t ct)
{
	size_t		j;
	char		*st;

	j = i;
	while (j - i < ct - 1 && tab[j + 1])
	{
		if (ft_strcmp(tab[j], tab[j + 1]) > 0)
		{
			st = tab[j];
			tab[j] = tab[j + 1];
			tab[j + 1] = st;
			j = i;
		}
		else
		{
			j++;
		}
	}
}

/*
** Reverse the result if the flag "-r" is activated
*/

void	ft_reverse_tab(char **tab, size_t ct)
{
	size_t	i;
	char	*buf;

	ct--;
	i = 0;
	while (i < ct)
	{
		buf = tab[i];
		tab[i] = tab[ct];
		tab[ct] = buf;
		i++;
		ct--;
	}
}
