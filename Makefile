# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 15:01:06 by pguthaus          #+#    #+#              #
#    Updated: 2018/12/03 19:21:05 by pguthaus         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Output name
NAME	=	libft.a

# Root ODIR
RODIR	= 	objs

# Sub dir
SUBPRO	=	str io lst mem utils

# Global variables
include global.mk

all: $(NAME)

$(NAME): $(SUBPRO)
	@echo "$(PURPLE)Packing library$(GREEN).$(PURPLE).$(GREEN).$(RESET)"
	@ar rcs $(NAME) $(shell find $(RODIR) -name "*.o" | sed 's/\n/ /g')

$(SUBPRO):
	@mkdir -p $(RODIR)
	$(MAKE) -C src/$@

clean:
	@echo "$(YELLOW)Cleaning object files..."
	@rm -rf $(RODIR)

fclean: clean
	@echo "Deleting $(NAME)"
	@rm -rf $(NAME)

re: fclean $(NAME)