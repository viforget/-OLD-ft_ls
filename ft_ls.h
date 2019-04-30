/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 11:26:16 by viforget          #+#    #+#             */
/*   Updated: 2019/04/30 17:52:30 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

#include <errno.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <pwd.h>
# include <dirent.h>
# include <time.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <grp.h>
# include "libft/libft.h"

void	ft_ls(int flag, char *str);
void	ft_addinfotab(char **tab, size_t ct, unsigned char *type, char *str);
void	ft_sort_ls(char **tab, int i, size_t ct);
void	ft_sort_ls_t(char **tab, int i, size_t ct);
void	ft_sort_tab_dir(struct dirent **tr, int flag);
char	**fullinfo(char ***itab, char **tab, size_t ct);
void	ft_reverse_tab(char **tab, size_t ct);
int		ft_putillop(char c);
void	ft_puterror(char *str, int e);
void	ft_recursive_ls(char *s, int fg);

# define TYPE ".pc.d.b.-.l.s"
#endif
