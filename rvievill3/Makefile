# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rvievill <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/04 16:28:45 by rvievill          #+#    #+#              #
#    Updated: 2016/06/17 12:19:20 by rvievill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =ft_ls

SRC_NAMES = main.c \
			access.c \
			display.c \
			error.c \
			error_sys.c \
			filling_ascii.c \
			filling_optl.c \
			filling_rascii.c \
			filling_rtime.c \
			filling_size.c \
			filling_struct.c \
			filling_time.c \
			filling_without_sort.c \
			free_list.c \
			free_tab.c \
			opt_l.c \
			print_color.c \
			read_dir.c \
			recognition_option.c \
			recursif.c \
			sort_bad_dir.c \
			sort_dir.c \
			sort_dir_l.c \
			sort_file.c \
			sort_file_l.c \
			time_optl.c \
			user_grp_optl.c \
			lnk_size_optl.c

OBJ_NAMES = $(SRC_NAMES:.c=.o)
INC_NAMES =	libft.h
LIB_NAMES = libft.a

SRC_PATH = ./src
OBJ_PATH = ./obj
INC_PATH = ./incude ./libft
LIB_PATH = ./libft/

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAMES))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAMES))
INC = $(addprefix -I,$(INC_PATH))
LIB = $(LIB_PATH)$(LIB_NAMES)

################################################################################

LAGS = -Wall -Wextra -Werror
LDLIBS = -lft
COM = gcc

################################################################################

all: $(LIB) $(NAME)

$(NAME): $(LIB) $(OBJ)
	$(COM) $^ -o $@ -L $(LIB_PATH) -lft

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(COM) -g3 $(FLAGS) $(INC) -o $@ -c $<

$(LIB):
	@make -C $(LIB_PATH)

clean:
	@make clean -C libft
	@rm -rf $(OBJ_PATH) 2> /dev/null || true
	@rmdir $(OBJ_PATH) obj 2> /dev/null || echo  > /dev/null
	@rm -f $(OBJ)

fclean: clean
	make fclean -C libft
	@rm -f $(NAME)

re: fclean all

