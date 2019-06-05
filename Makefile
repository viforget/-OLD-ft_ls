# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: viforget <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/10 12:42:08 by viforget          #+#    #+#              #
#    Updated: 2019/06/05 19:28:25 by viforget         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRC = error.c\
	  ft_file.c\
	  ft_ls.c\
	  ft_ls_l.c\
	  ft_recursive.c\
	  fullinfo.c\
	  sort_for_ls.c\
	  fornorm.c\
	  acl.c\

OBJ = $(SRC:.c=.o)

FLAG = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) :
	gcc $(FLAG) -o $(NAME) $(SRC) libft/libft.a

clean :
	@rm -rf $(OBJ)
	@echo "\033[36mCLEAN FILLIT OK\033[0m"

fclean :
	@rm -rf $(OBJ) $(NAME)
	@echo "\033[36mFCLEAN FILLIT OK\033[0m"

re : fclean all

.PHONY: all clean fclean re
