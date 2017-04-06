# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rqueverd <rqueverd@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/07 11:46:16 by rqueverd          #+#    #+#              #
#    Updated: 2017/02/09 11:46:39 by rqueverd         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libft.a
HEADER = libft.h
SRCS = ft_swap.c ft_absolute.c get_next_line.c ft_memalloc.c ft_putchar_fd.c ft_strclr.c ft_strlen.c ft_strsplit.c ft_atoi.c ft_memccpy.c ft_putendl.c ft_strcmp.c ft_strmap.c ft_strstr.c ft_bzero.c ft_memchr.c ft_putendl_fd.c ft_strcpy.c ft_strmapi.c ft_strsub.c ft_isalnum.c ft_memcmp.c ft_putnbr.c ft_strdel.c ft_strncat.c ft_strtrim.c ft_isalpha.c ft_memcpy.c ft_putnbr_fd.c ft_strdup.c ft_strncmp.c ft_tolower.c ft_isascii.c ft_memdel.c ft_putstr.c ft_striter.c ft_strncpy.c ft_toupper.c ft_isdigit.c ft_memmove.c ft_putstr_fd.c ft_striteri.c ft_strnew.c ft_isprint.c ft_memset.c ft_strcat.c ft_strjoin.c ft_strnstr.c ft_putchar.c ft_strchr.c ft_strlcat.c ft_strrchr.c ft_strequ.c ft_strnequ.c ft_strsplit.c ft_itoa.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstdel.c ft_lstiter.c ft_lstmap.c ft_print_params.c ft_pwr.c ft_lstadd.c
OBJECTS = $(SRCS:.c=.o)

all: $(NAME)
$(NAME): $(OBJECTS)
	@echo "\033[32;40mCompilation des sources..."
	@gcc  -Wall -Werror -Wextra -c -I  $(HEADER) $(SRCS)
	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)
	@echo "Termine !"
clean:
	@echo "\033[32;40mSuppresion des objets."
	@rm -f $(OBJECTS)
	@echo "Termine !"
fclean: clean
	@echo "\033[32;40mSuppression bibliotheque statique"
	@rm -f $(NAME)
	@echo "Termine !"
re: fclean all
