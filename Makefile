# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lvalenti <lvalenti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/28 11:03:48 by lvalenti          #+#    #+#              #
#    Updated: 2017/01/03 12:09:10 by lvalenti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
CC = clang
CFLAGS = -Weverything -Wstrict -pedantic -W -Wall -Werror -Wextra -g
CPATH = srcs/
OPATH = obj/
HPATH = includes/ libft/
INC = $(addprefix -I , $(HPATH))
CFILES = main.c\
		 list.c\
		 check.c\
		 stat.c
OFILES = $(CFILES:.c=.o)
HFILES = includes/ft_ls.h libft/includes/libft.h
OBJ = $(addprefix $(OPATH), $(OFILES))

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	$(CC) $(CFLAGS) $(OBJ) libft/libft.a -o $(NAME)

debug: $(OBJ)
	make -C libft
	$(CC) $(CFLAGS) $(OBJ) libft/libft.a -o $(NAME)

$(OPATH)%.o: $(CPATH)%.c $(HFILES)
	@mkdir -p $(OPATH)
	$(CC) -g $(INC) $< -c -o $@


clean:
	make -C libft clean
	rm -rf $(OBJ) $(OPATH)

fclean: clean
	make -C libft fclean
	rm -f $(NAME)

re: fclean all
