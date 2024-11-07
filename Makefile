# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aokhapki <aokhapki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/06 16:37:47 by aokhapki          #+#    #+#              #
#    Updated: 2024/11/07 20:34:35 by aokhapki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long

CFLAGS	= -Wall -Wextra -Werror 
MLXFLAGS= -lglfw -L "$(HOME)/.brew/opt/glfw/lib/"

CC		= gcc
SRC_DIR = ./src/
OBJ_DIR = ./objs/
RM		= rm -rf

SRC		= 	$(SRC_DIR)so_long.c\
			$(SRC_DIR)get_next_line.c\
			$(SRC_DIR)init.c\
			$(SRC_DIR)draw.c\
			$(SRC_DIR)parsing.c\
			$(SRC_DIR)control.c\
			$(SRC_DIR)finish.c\
			#$(SRC_DIR)play.c
			
OBJ = $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

LIB = LIBFT/libft.a
MLX42 = MLX42/build/libmlx42.a

$(NAME): $(MLX42) $(OBJ) $(LIB) 
		@$(MAKE) -C Libft
		@$(CC) $(CFLAGS) $(MLXFLAGS) -o $(NAME) $(MLX42) $(OBJ) $(LIB)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIB):
	@$(MAKE) -C Libft

all: $(NAME)

mlx:
	git clone https://github.com/ashirzad313/MLX42 MLX42

cleanmlx:
		@rm -rf MLX42
		@echo "$(CYAN)MLX42 folder is deleted!$(WHITE)"

clean:
		@$(MAKE) -C Libft clean
		@rm -rf $(OBJ_DIR)
		@rm -f libmlx42.a
		@echo "$(CYAN)Object files cleaned!$(WHITE)"

fclean: clean
		@$(MAKE) -C Libft fclean
		@rm -f $(NAME)
		@echo "$(CYAN)Executable and object files cleaned!$(WHITE)"

cleanAll: fclean cleanmlx

re: fclean all

.PHONY: all clean fclean cleanmlx cleanAll re