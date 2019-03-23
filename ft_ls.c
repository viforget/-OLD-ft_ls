/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 14:15:59 by viforget          #+#    #+#             */
/*   Updated: 2019/03/23 03:58:31 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_putillop(char c)
{
	ft_putstr("ft_ls: illegal option -- ");
	ft_putchar(c);
	ft_putstr("\nusage: ft_ls [-Ralrt] [file ...]\n");
}

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
		{
			ft_putillop(str[i]);
			return (0);
		}
		i++;
	}
	return (nbr);
}

size_t	ft_countfile(char *str, int flag)
{
	DIR				*dir;
	struct dirent	*rep;
	size_t			nb;

	nb = 0;
	dir = opendir(str);
	rep = readdir(dir);
	while(rep)
	{
		if (flag % 2 == 0 || rep->d_name[0] != '.')
			nb++;
		rep = readdir(dir);
	}
	return (nb);
}

void	ft_affls(DIR *dir, int flag, char *s)
{
	struct dirent	*rep;
	char			**tab;
	size_t				ct;
	size_t				i;

	ct = ft_countfile(s, flag);
	flag % 5 == 0 ? (i = ct - 1) : (i = 0);
	tab = (char **)ft_memalloc(sizeof(char *) * ct);
	rep = readdir(dir);
	while (rep)
	{
		if (!(rep->d_name[0] == '.' && flag % 2 != 0))
		{
			if (flag % 5 == 0)
				tab[i--] = rep->d_name;
			else
				tab[i++] = rep->d_name;
		}
		rep = readdir(dir);
	}
	ft_puttab(tab, ct);
}

void	ft_recursive_ls(char *s, int fg)
{
	DIR				*dir;
	struct dirent	*rep;

	dir = opendir(s);
	s = ft_strjoin(s, "/");
	rep = readdir(dir);
	rep = readdir(dir);
	rep = readdir(dir);
	while (rep)
	{
		if (rep->d_type == 4 && !(fg % 2 != 0 && rep->d_name[0] == '.'))
		{
			ft_putchar('\n');
			ft_ls((fg % 13 == 0) ? fg : fg * 13, ft_strjoin(s, rep->d_name)); //Malloc Warning
		}
		rep = readdir(dir);
	}
}

void	ft_ls(int flag, char *str)
{
	DIR	*dir;

	dir = opendir(str);
	if (flag % 13 == 0)
	{
		ft_putstr(str);
		ft_putstr(":\n");
	}
	if (dir != NULL)
	{
		ft_affls(dir, flag, str);
		closedir(dir);
	} //Penser a PE free dir en cas d'erreur (ou pas)
	if (flag % 7 == 0)
	{
		ft_recursive_ls(str, flag);
	}
}

void	ft_sort_tab(char **tab, int i, int flag)
{
	int		j;
	char	*st;

	j = i;
	while (tab[j + 1])
	{
		if ((ft_strcmp(tab[j], tab[j + 1]) > 0 && flag % 5 != 0) ||
			(ft_strcmp(tab[j], tab[j + 1]) < 0 && flag % 5 == 0))
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
	if (i < argc - 1)
		flag *= 13;
	if (argv[i])
	{
		ft_sort_tab(argv, i, flag);
		while (argv[i])
		{
			ft_ls(flag, argv[i++]);
			if (argv[i])
				ft_putchar('\n');
		}
	}
	else
		ft_ls(flag, ".");
}
