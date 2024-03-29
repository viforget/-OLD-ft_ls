/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 11:26:16 by viforget          #+#    #+#             */
/*   Updated: 2019/06/06 20:15:50 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <errno.h>
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
# include <sys/acl.h>
# include <sys/xattr.h>

int		ft_ls(int flag, char *str);
void	ft_addinfotab(char **tab, size_t ct, unsigned char *type, char *str);
void	ft_addinfotab2(char **tab, size_t ct, unsigned char *type, char *str);
void	ft_sort_ls(char **tab, size_t i, size_t ct);
void	ft_sort_ls_t(char **tab, size_t i, size_t ct);
void	ft_sort_tab_dir(struct dirent **tr, int flag);
char	**fullinfo(char ***itab, char **tab, size_t ct);
void	ft_reverse_tab(char **tab, size_t ct, int i);
int		ft_putillop(char c);
int		ft_puterror(char *str, int e);
void	ft_recursive_ls(char *s, int fg);
void	ft_file(char **argv, int i, int ct, int flag);
char	*majmin(dev_t rdev);
int		*cntlen(char ***itab, int ct);
void	ft_tabstrdel(char **tab);
void	ft_freeitab(char ***itab);
int		freeandret(char **s);
void	ft_freedom(char **s, char **tab, size_t ct, unsigned char **type);
void	ft_sorting(char **tab, size_t ct, int flag);
void	readdir2(DIR *dir);
void	jstname(char **argv, int i, int ct);
char	ft_acl(char *pat);
void	ft_afffile(char **tab, int j, unsigned char *type, int flag);

# define TYPE "cpc.d.b.-.l.s"
#endif
