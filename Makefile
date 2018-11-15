# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 15:01:06 by pguthaus          #+#    #+#              #
#    Updated: 2018/11/15 17:49:51 by pguthaus         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra -Iincludes

RESET = \033[0m
PURPLE = \033[1;35m
GREEN = \033[1;32m
YELLOW = \033[1;33m

SRCS	=	ft_memchr.c		\
			ft_memset.c		\
			ft_memcpy.c		\
			ft_memccpy.c	\
			ft_memdel.c		\
			ft_memcmp.c		\
			ft_bzero.c		\
			ft_memalloc.c	\
			ft_memmove.c	\
			ft_isalnum.c	\
			ft_isalpha.c	\
			ft_isascii.c	\
			ft_isdigit.c	\
			ft_isprint.c	\
			ft_tolower.c	\
			ft_toupper.c	\
			ft_itoa.c		\
			ft_atoi.c		\
							\
			ft_strlen.c		\
			ft_strcat.c		\
			ft_strcmp.c		\
			ft_strncmp.c	\
			ft_strnew.c		\
			ft_strdel.c		\
			ft_strcpy.c		\
			ft_strncpy.c	\
			ft_strclr.c		\
			ft_striter.c	\
			ft_striteri.c	\
			ft_strchr.c		\
			ft_strrchr.c	\
			ft_strncat.c	\
			ft_strlcat.c	\
			ft_strjoin.c	\
			ft_strstr.c		\
			ft_strnstr.c	\
			ft_strtrim.c	\
			ft_strdup.c		\
			ft_strsub.c		\
			ft_strsplit.c	\
			ft_strequ.c		\
			ft_strnequ.c	\
			ft_strmap.c		\
			ft_strmapi.c	\
							\
			ft_putchar.c	\
			ft_putchar_fd.c	\
			ft_putstr.c		\
			ft_putstr_fd.c	\
			ft_putendl.c	\
			ft_putendl_fd.c	\
			ft_putnbr.c		\
			ft_putnbr_fd.c	\
							\
			ft_itoa.c		\
							\
			ft_lstnew.c		\
			ft_lstdelone.c	\
			ft_lstdel.c		\
			ft_lstadd.c		\
			ft_lstiter.c	\
			ft_lstmap.c		\

OBJS	=	$(SRCS:.c=.o)
NAME	=	libft.a

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(PURPLE)Packing library$(GREEN).$(PURPLE).$(GREEN).$(RESET)"
	@ar rcs $(NAME) $(OBJS)
	@echo "$(PURPLE)Library packed: $(YELLOW)$(NAME)"

%.o: %.c
	@echo "$(PURPLE)Compiling $(GREEN)$<$(PURPLE) → $(YELLOW)$@"
	@$(CC) $(CCFLAGS) -c $<

clean:
	@echo "$(YELLOW)Cleaning object files..."
	@rm -f $(OBJS)
	@echo "$(YELLOW)Object files has been cleaned !\n"

fclean: clean
	@echo "Deleting $(NAME)"
	@rm -rf $(NAME)
	@echo "$(NAME) has been deleted !"

re: fclean $(NAME)
