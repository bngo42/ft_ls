# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bngo <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/28 11:12:19 by bngo              #+#    #+#              #
#    Updated: 2016/11/28 11:48:14 by bngo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
CC = gcc
FLAGS = -Werror -Wall -Wextra
SRCS = srcs/main.c \

OBJS = $(SRCS:.c=.o)
	
$(NAME): $(OBJS)
	make -C libft/ fclean && make -C libft/
	gcc -c $(SRCS)
	gcc -g $(FLAGS) -o $(NAME) $(OBJS) libft/libft.a -I includes/
all: $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY : all clean fclean re
