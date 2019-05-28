/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fullinfo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 18:39:57 by viforget          #+#    #+#             */
/*   Updated: 2019/05/28 16:23:02 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** When the flag "-l" is activate, this function count the maximum number of
**character in each column
** ***itab is a tab of tab of str, the function will count in it
** ct is the number of line, the max value of **itab
*/

int	*cntlen(char ***itab, int ct)
{
	int	 i;
	int	 j;
	int	*len;

	len = ft_memalloc(sizeof(int) * 8);
	j = 0;
	while (j < 8)
	{
		i = 0;
		while (i < ct)
		{
			if (ft_strlen(itab[i][j]) > len[j])
			{
				len[j] = ft_strlen(itab[i][j]);
			}
			i++;
		}
		if (j == 1 || j == 3 || j == 4)
			len[j] += len[j - 1] + 2;
		else if (j != 0)
			len[j] += len[j - 1] + 1;
		j++;
	}
	return (len);
}

/*
** setstr fill bstr with str from bstr[nbr]
*/

char	*majmin(dev_t rdev)
{
	char	 *str;
	char	 *tp;
	int		i;
	int		j;

	str = (char *)malloc(sizeof(char) * 8);
	str = ft_memset(str, ' ', 8);
	tp = ft_itoa(major(rdev));
	i = ft_strlen(tp) - 1;
	j = 1;
	while(i >= 0)
		str[j--] = tp[i--];
	ft_strdel(&tp);
	tp = ft_itoa(minor(rdev));
	i = ft_strlen(tp) - 1;
	j = 6;
	while(i >= 0)
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
	str = ft_strjoindel2(str, tab);
	return (str);
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
	while (i < ct)
	{
		tab[i] = fusion(tab[i], itab[i], len);
		i++;
	}
	return (tab);
}
