# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bngo <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/05 11:40:59 by bngo              #+#    #+#              #
#    Updated: 2017/01/05 12:06:04 by bngo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
CC = clang
CFLAGS = -Wall -Werror -Wextra
CPATH = srcs/
OPATH = obj/
HPATH = includes/ libft/
INC = $(addprefix -I , $(HPATH))
CFILES = main.c\
		 list.c\
		 check.c\
		 stat.c \
		 stat2.c \
		 funct_0.c \
		 funct_1.c \
		 read.c
OFILES = $(CFILES:.c=.o)
HFILES = includes/ft_ls.h libft/libft.h
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
