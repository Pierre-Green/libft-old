# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 15:01:06 by pguthaus          #+#    #+#              #
#    Updated: 2018/11/22 15:43:16 by pguthaus         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	gcc
CCFLAGS	=	-Wall -Werror -Wextra -Iincludes

RESET = \033[0m
PURPLE = \033[1;35m
GREEN = \033[1;32m
YELLOW = \033[1;33m

SRCS =  get_next_line.c	\
		tests/main.c	\

OBJS = $(SRCS:.c=.o)
NAME = get_next_line_tests
LIBFT_TASK = all

debug: CCFLAGS += -DDEBUG -g

debug: LIBFT_TASK = debug

debug: $(NAME)
	@echo "$(RESET)"

all: libft $(NAME)

libft:
	@$(MAKE) -C libft $(LIBFT_TASK)

$(NAME): $(OBJS)
	@echo "$(PURPLE)Packing executable$(GREEN).$(PURPLE).$(GREEN).$(RESET)"
	@$(CC) $(CCFLAGS) $(notdir $(OBJS)) -o $(NAME) ./libft/libft.a -lm
	@echo "$(PURPLE)Executable packed: $(YELLOW)./$(NAME)"

%.o: %.c
	@echo "$(PURPLE)Compiling $(GREEN)$<$(PURPLE) → $(YELLOW)$@"
	@$(CC) $(CCFLAGS) -c $<

clean:
	@echo "$(YELLOW)Cleaning object files..."
	@rm -f $(notdir $(OBJS))
	@echo "$(YELLOW)Object files has been cleaned !\n"

fclean: clean
	@echo "Deleting $(NAME)"
	@rm -rf $(NAME)
	@echo "$(NAME) has been deleted !"

re: fclean $(NAME)

run: $(NAME)
	@echo "\n$(PURPLE)Running: $(GREEN)$(NAME)\n$(RESET)"
	@./$(NAME)