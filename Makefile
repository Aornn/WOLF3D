# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/03 12:45:24 by rqueverd          #+#    #+#              #
#    Updated: 2017/04/13 14:19:23 by rqueverd         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = WOLF3D
HEADER = wolf.h
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Ofast
FLAGSFDF = -lmlx -framework OpenGL -framework AppKit
SRCS = main.c draw.c raycasting.c init_main.c event.c radar.c move.c
OBJECTS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	@make -C libft/
	@echo "\033[32;40mCompilation des sources de WOLF..."
	@$(CC) $(CFLAGS)  -I libft/ -c $(SRCS)
	@$(CC) -o $(NAME) $(OBJECTS) -lm -L libft/ -lft $(FLAGSFDF)
	@echo "Termine !"
clean:
	@echo "\033[32;40mSuppresion des objets du WOLF."
	@make -C libft/ clean
	@rm -rf $(OBJECTS)
	@echo "Termine ! WOLF"
fclean: clean
	@echo "Nettoyage complet WOLF"
	@make -C libft/ fclean
	@rm -rf $(NAME)
	@echo "Termine ! WOLF"
re: fclean all
.PHONY: clean fclean re all