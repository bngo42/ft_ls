# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lvalenti <lvalenti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/28 11:12:19 by bngo              #+#    #+#              #
#    Updated: 2016/12/13 13:00:31 by lvalenti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
CC = gcc
FLAGS = -Werror -Wall -Wextra
SRCS = srcs/main.c srcs/list.c srcs/stat.c srcs/check.c

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	make -C libft/ fclean && make -C libft/
	gcc -c -g $(SRCS)
	gcc -g $(FLAGS) -o $(NAME) $(OBJS) libft/libft.a -I includes/
all: $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)
	rm -rf list.o main.o stat.o check.o

re: fclean all

.PHONY : all clean fclean re
