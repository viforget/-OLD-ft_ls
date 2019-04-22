/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fullinfo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 18:39:57 by viforget          #+#    #+#             */
/*   Updated: 2019/04/22 18:36:05 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

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
		while(i < ct)
		{
			if (ft_strlen(itab[i][j]) > len[j])
				len[j] = ft_strlen(itab[i][j]);
			i++;
		}
		if (j == 1 || j == 3 || j == 4)
			len[j] += len[j - 1] + 2;
		else if (j != 0)
			len[j] += len [j - 1] + 1;
		j++;
	}
	return (len);
}

void	setstr(char *bstr, char *str, size_t nbr)
{
	int i;

	i = ft_strlen(str) - 1;
	nbr--;
	while(i >= 0)
	{
		bstr[nbr] = str[i];
		i--;
		nbr--;
	}
}

char *strset(char *str, char c, int sz)
{
	while (sz >= 0)
	{
		str[sz] = c;
		sz--;
	}
	return (str);
}

char	*fusion(char *tab, char **itab, int *len)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)ft_memalloc(sizeof(char) * len[7] + 1);
	str = (char *)ft_memset(str, 32, len[7] + 1);
	//str = strset(str, ' ', len[8]);
	while(i < 8)
	{
		setstr(str, itab[i], len[i]);
		i++;
	}
	str = ft_strjoindel2(str, tab);
	//ft_strdel(tab);
	return (str);
}

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
