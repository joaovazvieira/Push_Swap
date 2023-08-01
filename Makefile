# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jovieira <jovieira@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/07 10:04:13 by jovieira          #+#    #+#              #
#    Updated: 2023/08/01 17:31:54 by jovieira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= push_swap
HEADER 	= pushswap.h
CFLAGS	= -Wall -Werror -Wextra
# CFLAGS	+= -fsanitize=address -g
SRC_DIR	= $(shell find src -type f -name "*.c")
OBJ		= $(SRC_DIR:src/%.c=obj/%.o)
OBJ_DIR	= obj

# comp. headers
INCLUDES 	= -I libft/libft.a -I src

# libft variables
LIBFT 		= libft/libft.a
LIBFT_DIR	= libft

all: $(NAME)

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)
	
$(NAME): $(LIBFT) $(OBJ)
	gcc $(INCLUDES) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR) bonus

obj/%.o: src/%.c | $(OBJ_DIR)
	gcc $(INCLUDES) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -rf $(LIBFT) $(NAME)

re: fclean all