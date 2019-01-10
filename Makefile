# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 15:01:06 by pguthaus          #+#    #+#              #
#    Updated: 2019/01/10 18:43:03 by pguthaus         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Output name
NAME	=	libft.a

# Compilation
CC = clang
CFLAGS = -Wall -Werror -Wextra -I includes/

# Root ODIR
ODIR	= 	./objs/

include sources.mk

OBJS := ${SRCS:c=o} 

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
	@rm -rf $(NAME)

getSources:
	@rm -rf sources.mk
	@touch sources.mk
	@find src/ -name "*.c" | sed  "s/src\//SRCS+=src\//g" >> sources.mk

re: fclean $(NAME)