# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 15:01:06 by pguthaus          #+#    #+#              #
#    Updated: 2019/01/14 20:47:17 by pguthaus         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Output name
NAME	=	libft.a
TEST_NAME	= tests_bin

# Compilation
CC = clang
CFLAGS = -Wall -Werror -Wextra -I includes/

# Root ODIR
ODIR	= 	./objs/

include sources.mk
include tests/sources.mk

OBJS := ${SRCS:c=o} 
TEST_OBJS := ${TEST_SRCS:c=o}

ROBJS = $(subst src/,$(ODIR),$(OBJS))

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(PURPLE)Packing library$(GREEN).$(PURPLE).$(GREEN).$(RESET)"
	ar rcs $(NAME) $(OBJS)

clean:
	@echo "$(YELLOW)Cleaning object files..."
	find . -type f -name '*.o' -delete

fclean: clean
	@echo "Deleting $(NAME)"
	@rm -rf $(NAME) $(TEST_NAME)

test: $(NAME) $(TEST_OBJS)
	$(CC) $(TEST_OBJS) $(NAME) -o $(TEST_NAME)
	./$(TEST_NAME)


getSources:
	@rm -f sources.mk
	@rm -f tests/sources.mk
	@touch sources.mk
	@touch tests/sources.mk 
	@find src/ -name "*.c" | sed  "s/src\//SRCS+=src\//g" >> sources.mk
	@find tests/ -name "*.c" | sed  "s/tests\//TEST_SRCS+=tests\//g" >> tests/sources.mk

re: fclean $(NAME)
