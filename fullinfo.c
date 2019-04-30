/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fullinfo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 18:39:57 by viforget          #+#    #+#             */
/*   Updated: 2019/04/29 16:05:03 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** When the flag "-l" is activate, this function count the maximum number of
**character in each column
** ***itab is a tab of tab of str, the function will count in it
** ct is the number of line, the max value of **itab
*/

int		*cntlen(char ***itab, size_t ct)
{
	int i;
	int j;
	int *len;

	len = ft_memalloc(sizeof(int) * 8);
	j = 0;
	while (j < 8)
	{
		i = 0;
		while (i < ct)
		{
			if (ft_strlen(itab[i][j]) > len[j])
				len[j] = ft_strlen(itab[i][j]);
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

void	setstr(char *bstr, char *str, size_t nbr)
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

/*
** fusion take a **itab and concatenate all str in it plus the *tab str
*/

char	*fusion(char *tab, char **itab, int *len)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)ft_memalloc(sizeof(char) * len[7] + 2);
	str = (char *)ft_memset(str, 32, len[7] + 1);
	while (i < 8)
	{
		setstr(str, itab[i], len[i]);
		i++;
	}
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
