/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fullinfo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 18:39:57 by viforget          #+#    #+#             */
/*   Updated: 2019/06/05 18:52:40 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** setstr fill bstr with str from bstr[nbr]
*/

char	*majmin(dev_t rdev)
{
	char	*str;
	char	*tp;
	int		i;
	int		j;

	str = (char *)malloc(sizeof(char) * 8);
	str = ft_memset(str, ' ', 8);
	tp = ft_itoa(major(rdev));
	i = ft_strlen(tp) - 1;
	j = 1;
	while (i >= 0)
		str[j--] = tp[i--];
	ft_strdel(&tp);
	tp = ft_itoa(minor(rdev));
	i = ft_strlen(tp) - 1;
	j = 6;
	while (i >= 0)
		str[j--] = tp[i--];
	str[2] = ',';
	ft_strdel(&tp);
	return (str);
}

void	setstr(char *bstr, char *str, int nbr)
{
	int i;

	i = ft_strlen(str) - 1;
	nbr--;
	while (i >= 0 && bstr[nbr] && str[i])
	{
		bstr[nbr] = str[i];
		i--;
		nbr--;
	}
	free(str);
}

void	setstr2(char *bstr, char *str, int nbr)
{
	int i;

	i = 0;
	nbr++;
	while (bstr[nbr] && str[i])
	{
		bstr[nbr] = str[i];
		i++;
		nbr++;
	}
	free(str);
}

/*
** fusion take a **itab and concatenate all str in it plus the *tab str
*/

char	*fusion(char *tab, char **itab, int *len)
{
	char	*str;
	int		i;
	int		ln;

	i = 0;
	ln = len[7] + 2;
	str = (char *)ft_memalloc(sizeof(char) * ln);
	str = (char *)ft_memset(str, 32, ln - 1);
	while (i < ln)
	{
		str[i] = ' ';
		i++;
	}
	i = 0;
	while (i < 8)
	{
		if (i == 2 || i == 3)
			setstr2(str, itab[i], (int)len[i - 1]);
		else
			setstr(str, itab[i], (int)len[i]);
		i++;
	}
	str[ln - 1] = '\0';
	free(itab);
	return (ft_strjoindel2(str, tab));
}

/*
** full info take a tab of tab of str (itab) who haves all info and retrun
** a tab of str wich column are aligned
*/

char	**fullinfo(char ***itab, char **tab, size_t ct)
{
	int	*len;
	int	i;

	i = 0;
	len = cntlen(itab, ct);
	while ((size_t)i < ct)
	{
		tab[i] = fusion(tab[i], itab[i], len);
		i++;
	}
	free(itab);
	free(len);
	return (tab);
}
