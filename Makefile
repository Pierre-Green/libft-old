# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 15:01:06 by pguthaus          #+#    #+#              #
#    Updated: 2019/02/06 21:23:56 by pierre           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Sources sets
include sources.mk
include tests/sources.mk

# Output name
NAME	=	libft.a
TEST_NAME	= tests_bin

# Compilation
CC = clang
CFLAGS = 

# Paths
SRCDIR		=		./src/
INCDIR		=		./includes/
OUTDIR		=		./objs/

# MLX
MLX_INC		=		/usr/local/include
MLX_ARGS	=		-L /usr/local/lib -lmlx -framework OpenGL -framework AppKit

# Test paths
TEST_DIR	=		./tests/
TEST_SRCDIR	=		$(addprefix $(TEST_DIR), src/)
TEST_INCDIR	=		$(addprefix $(TEST_DIR), includes/)
TEST_OUTDIR	=		$(addprefix $(TEST_DIR), objs/)

# OBJS
OBJS		=		$(addprefix $(OUTDIR),$(SRCS:.c=.o))
TEST_OBJS	=		$(addprefix $(TEST_OUTDIR),$(TEST_SRCS:.c=.o))

all: $(NAME)

re: fclean $(NAME)

dev: CFLAGS += -g
dev: re

$(NAME): $(OBJS)
	@echo "$(PURPLE)Packing library$(GREEN).$(PURPLE).$(GREEN).$(RESET)"
	@ar rcs $(NAME) $(OBJS)
	@echo "Done"

$(OUTDIR)%.o: $(SRCDIR)%.c
	@if [ ! -d $(dir $@) ]; then mkdir -p $(dir $@); fi
	@echo "Making $<"
	@$(CC) $(CFLAGS) -I $(INCDIR) -I $(MLX_INC) -o $@ -c $<

devTest: CFLAGS += -g
devTest: re test

# Test rules
test: $(NAME) $(TEST_OBJS)
	@echo "Compiling tests"
	@$(CC) $(CFLAGS) $(TEST_OBJS) $(NAME) -o $(TEST_NAME) -lm
	@echo "Running tests"
	@./$(TEST_NAME)

$(TEST_OUTDIR)%.o: $(TEST_SRCDIR)%.c
	@if [ ! -d $(dir $@) ]; then mkdir -p $(dir $@); fi
	@echo "Making $<"
	@$(CC) $(CFLAGS) -I $(INCDIR) -I $(TEST_INCDIR) -o $@ -c $<

clean:
	@echo "$(YELLOW)Cleaning object files..."
	@rm -rf $(OUTDIR) $(TEST_OUTDIR)

fclean: clean
	@echo "Deleting $(NAME)"
	@rm -rf $(NAME) $(TEST_NAME)

getSources:
	@rm -f sources.mk
	@rm -f tests/sources.mk
	@touch sources.mk
	@touch tests/sources.mk 
	@find src/ -name "*.c" | sed  "s/src\//SRCS+=/g" >> sources.mk
	@find tests/src/ -name "*.c" | sed "s/tests\/src\//TEST_SRCS+=/g" >> tests/sources.mk

