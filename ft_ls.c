/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 14:15:59 by viforget          #+#    #+#             */
/*   Updated: 2019/05/17 11:12:09 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** create a int flag that contain flag information
** if flag % 2 == 0, that mean the flag "a" is active
** 2 -> -a
** 3 -> -l
** 5 -> -r
** 7 -> -R
** 11 -> -t
*/

int		alprime(char *str)
{
	int i;
	int nbr;

	i = 1;
	nbr = 1;
	while (str[i])
	{
		if (str[i] == 'a' && nbr % 2 != 0)
			nbr *= 2;
		else if (str[i] == 'l' && nbr % 3 != 0)
			nbr *= 3;
		else if (str[i] == 'r' && nbr % 5 != 0)
			nbr *= 5;
		else if (str[i] == 'R' && nbr % 7 != 0)
			nbr *= 7;
		else if (str[i] == 't' && nbr % 11 != 0)
			nbr *= 11;
		else
			return (ft_putillop(str[i]));
		i++;
	}
	return (nbr);
}

/*
** return the number of file in the repertory (str)
*/

size_t	ft_countfile(char *str, int flag)
{
	DIR				*dir;
	struct dirent	*rep;
	size_t			nb;

	nb = 0;
	dir = opendir(str);
	rep = readdir(dir);
	while (rep)
	{
		if (flag % 2 == 0 || rep->d_name[0] != '.')
			nb++;
		rep = readdir(dir);
	}
	return (nb);
}

/*
** find, sort and display all informations(name, flag -l)
*/

void	ft_affls(DIR *dir, int flag, size_t ct, char *str)
{
	struct dirent	*rep;
	char			**tab;
	unsigned char	*type;
	size_t			i;

	i = 0;
	if (ct == 0)
		return ;
	tab = (char **)ft_memalloc(sizeof(char *) * ct);
	type = (unsigned char *)ft_memalloc(sizeof(unsigned char) * ct);
	rep = readdir(dir);
	while (rep)
	{
		if (!(rep->d_name[0] == '.' && flag % 2 != 0))
		{
			type[i] = rep->d_type;
			tab[i++] = ft_strdup(rep->d_name);
		}
		rep = readdir(dir);
	}
	flag % 11 == 0 ? ft_sort_ls_t(tab, 0, ct) : ft_sort_ls(tab, 0, ct);
	flag % 5 == 0 ? ft_reverse_tab(tab, ct, 0) : 19;
	flag % 3 == 0 ? ft_addinfotab(tab, ct, type, str) : 19;
	ft_puttab(tab, ct);
	ft_tabdel(tab, ct);
}

int		ft_ls(int flag, char *str)
{
	DIR	*dir;

	dir = opendir(str);
	if (dir == NULL && errno == ENOTDIR)
		return (0);
	if (flag % 13 == 0 && dir != NULL)//Ne plus y gerer les erreurs ici
	{
		ft_putstr(str);
		ft_putstr(":\n");
	}
	if (dir != NULL)
	{
		ft_affls(dir, flag, ft_countfile(str, flag), ft_strjoin(str, "/"));
		closedir(dir);
	}
	if (errno != 0)
		ft_puterror(str, errno, flag);
	if (flag % 7 == 0)
		ft_recursive_ls(str, flag);
	ft_strdel(&str);
	return (1);
}

int		main(int argc, char **argv)
{
	int i;
	int flag;

	i = 1;
	flag = 1;
	while (argv[i] && argv[i][0] == '-')
	{
		if (!(flag *= alprime(argv[i])))
			return (0);
		i++;
	}
	i < argc - 1 ? flag *= 13 : 19;
	if (argv[i])
	{
		ft_file(argv, i, argc, flag);
		ft_sort_ls(argv, i, argc);
		flag % 5 == 0 ? ft_reverse_tab(argv, argc, i) : 19;
		while (argv[i])
		{
			if (ft_ls(flag, ft_strdup(argv[i++])) == 1)
				if (argv[i])
					ft_putchar('\n');
		}
	}
	else
		ft_ls(flag, ft_strdup("."));
}
