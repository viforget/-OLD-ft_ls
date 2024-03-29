/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 14:15:59 by viforget          #+#    #+#             */
/*   Updated: 2019/06/10 19:50:34 by viforget         ###   ########.fr       */
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
	if (!(dir = opendir(str)))
		return (0);
	rep = readdir(dir);
	while (rep)
	{
		if (flag % 2 == 0 || rep->d_name[0] != '.')
			nb++;
		rep = readdir(dir);
	}
	closedir(dir);
	return (nb);
}

/*
** find, sort and display all informations(name, flag -l)
*/

int		ft_affls(DIR *dir, int flag, size_t ct, char *str)
{
	struct dirent	*rep;
	char			**tab;
	unsigned char	*type;
	size_t			i;
	int				n;

	i = 0;
	n = 0;
	tab = (char **)ft_memalloc(sizeof(char *) * ct);
	type = (unsigned char *)ft_memalloc(sizeof(unsigned char) * ct);
	rep = readdir(dir);
	while (rep)
	{
		if (!(rep->d_name[0] == '.' && flag % 2 != 0))
		{
			rep->d_type == 4 ? n = 1 : 0;
			type[i] = rep->d_type;
			tab[i++] = ft_strdup(rep->d_name);
		}
		rep = readdir(dir);
	}
	ft_sorting(tab, ct, flag);
	flag % 3 == 0 ? ft_addinfotab(tab, ct, type, str) : 19;
	ft_freedom(&str, tab, ct, &type);
	return (n);
}

int		ft_ls(int flag, char *str)
{
	DIR	*dir;
	int	n;

	dir = opendir(str);
	if (dir == NULL && errno == ENOTDIR)
		return (freeandret(&str));
	if (flag % 13 == 0 && dir != NULL)
	{
		ft_putstr(str);
		ft_putstr(":\n");
	}
	if (dir != NULL && ft_countfile(str, flag) != 0)
		n = ft_affls(dir, flag, ft_countfile(str, flag), ft_strjoin(str, "/"));
	if (dir != NULL)
		closedir(dir);
	else if (errno != 0 && ft_puterror(str, errno) == 0)
		n = 0;
	if (flag % 7 == 0 && n == 1)
		ft_recursive_ls(str, flag);
	else
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
		if (!(flag *= alprime(argv[i++])))
			return (0);
	i < argc - 1 ? flag *= 13 : 19;
	if (argv[i])
	{
		flag % 3 == 0 ? ft_file(argv, i, argc, flag) : jstname(argv, i, argc);
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
	return (0);
}
