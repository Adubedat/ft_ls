# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adubedat <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/23 17:07:31 by adubedat          #+#    #+#              #
#    Updated: 2016/09/28 16:07:33 by adubedat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:

NAME = ft_ls

SRC_PATH = .
ROOT = ..
OBJ_FOLDER = obj
INC_PATH = $(ROOT)/includes \
		   $(ROOT)/libft \

OBJ_PATH = $(ROOT)/$(OBJ_FOLDER)
DST_PATH = $(ROOT)
LFT_PATH = $(ROOT)/libft

CC = gcc -g
CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = $(addprefix -I ,$(INC_PATH))
LDFLAGS = -L$(LFT_PATH)
LDLIBS = -lft

SRC_NAME =	main.c \
			options.c \
			create_elem.c \
			print_files.c \
			print_rep.c \
			options2.c \
			sort.c \
			sort2.c \
			print_files_l.c \
			print_rights.c \
			free.c \
			print_time.c \

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
DST = $(addprefix $(DST_PATH)/,$(NAME))

all: $(ROOT)/libft/libft.a $(DST)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
	printf "\e[32m[✔]\e[36m $@"
	printf "\033[0m\n"

$(DST): $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) $(LDLIBS) -o $(DST)
	printf "\e[32m----------------------------------\e[36m\n"
	printf "\e[32m[✔]\e[36m $@"
	printf "\n\e[32m----------------------------------\e[36m"
	printf "\033[0m\n"

$(ROOT)/libft/libft.a:
	make -C $(ROOT) libft/libft.a

clean:
	printf "\e[36m"
	@cd $(ROOT) && rm -fv $(addprefix $(OBJ_FOLDER)/,$(OBJ_NAME))
	@rmdir $(OBJ_PATH) $(ROOT)/obj 2> /dev/null || true
	printf "\e[31m----------------------------------\n"
	printf "[✔]\e[36m $(NAME): Objects deleted\n"
	printf "\e[31m----------------------------------\e[36m"
	printf "\033[0m\n"

fclean: clean
	printf "\e[36m"
	@cd $(DST_PATH) && rm -fv $(NAME)
	printf "\e[31m----------------------------------\n"
	printf "[✔]\e[36m $(NAME): All deleted\n"
	printf "\e[31m----------------------------------\e[36m"
	printf "\033[0m\n"

re: fclean all

ac: all clean

norme:
	norminette $(SRC)

.PHONY: all clean fclean re
