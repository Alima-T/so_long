# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aokhapki <aokhapki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/06 16:37:47 by aokhapki          #+#    #+#              #
#    Updated: 2024/10/07 18:47:04 by aokhapki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Output executable
NAME	= so_long

#compiling
CC		= cc
CFLAGS	= -Wall -Wextra -Wunreachable-code -Ofast

# Paths to external libraries (MLX42 and Libft)
LIBMLX	= ./MLX42
LIBFT	= ./LIBFT

# Header includes
HEADERS := -I ./include -I $(LIBMLX)/include -I $(LIBFT)

# Frameworks (for macOS)
FRAMEWORKS = -framework Cocoa -framework OpenGL -framework IOKit

# ********
# # Contains the X11 and MLX header files
# INCLUDES = -I/opt/X11/include -Imlx

# .c.o:
# 	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)
# ********

# Rule for compiling .c files to .o
%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)\n"
	
LIBS	:= $(LIBMLX)/build/libmlx42.a -lglfw -framework Cocoa -framework OpenGL -framework IOKit -L$(LIBFT) -lft

# Source Files TODO
SRCS = so_long.c

# Object Files
OBJS = $(SRCS:.c=.o)

# Compilation rule
all: libmlx libft $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS) $(FRAMEWORKS) $(HEADERS)

# Clean up object files
clean:
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX)/build
	@make -C $(LIBFT) clean

# Clean up object files and executable
fclean: clean
	@rm -rf $(NAME)
	@make -C $(LIBFT) fclean

# Rebuild the project
re: fclean all

# Update
t: $(NAME)
	./$(NAME) 
	
# Cleaning and rebuilding the program from scratch and then running it
ret: re t

# Phony targets
.PHONY: all, clean, fclean, re, libmlx, libft