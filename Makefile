# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 15:01:06 by pguthaus          #+#    #+#              #
#    Updated: 2018/12/02 20:57:21 by pguthaus         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compilator
CC		=	clang

# Compile flags
CFLAGS	=	-Wall -Werror -Wextra -Iincludes

# Output name
NAME	=	libft.a

# Srcs
include src/io/io.mk
include src/lst/lst.mk
include src/mem/mem.mk
include src/str/str.mk
include src/utils/utils.mk

OBJS		:=	$(SRC:.c=.o)

# Colors
RESET = \033[0m
PURPLE = \033[1;35m
GREEN = \033[1;32m
YELLOW = \033[1;33m

all: $(NAME)

$(NAME): $(OBJS)
	echo "$(PURPLE)Packing library$(GREEN).$(PURPLE).$(GREEN).$(RESET)"
	ar rcs $(NAME) $(notdir $^)

$(OBJS): %.o: %.c
	echo "$(PURPLE)Compiling $(GREEN)$<$(PURPLE) → $(YELLOW)$@"
	$(CC) $(CFLAGS) -c $<

clean:
	@echo "$(YELLOW)Cleaning object files..."
	@rm -rf *.o

fclean: clean
	@echo "Deleting $(NAME)"
	@rm -rf $(NAME)

re: fclean $(NAME)

run: $(NAME)
	@echo "\n$(PURPLE)Running: $(GREEN)$(NAME)\n$(RESET)"
	@./$(NAME)