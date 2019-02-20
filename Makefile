# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 15:01:06 by pguthaus          #+#    #+#              #
#    Updated: 2019/02/20 22:34:42 by pguthaus         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include make/config.mk

PRODFILE	=	make/Makefile.prod
DEVFILE		=	make/Makefile.dev

all: lib

lib:
	@echo "Making the static library..."
	@$(MAKE) -f $(PRODFILE)
	@echo "Static library has been created"

devLib:
	@echo "Making the debugable static library..."
	@$(MAKE) -f $(DEVFILE)
	@echo "Debugable static library has been made"

test:
	@echo "Running tests..."
	@$(MAKE) -f $(PRODFILE) test

devTest:
	@echo "Running debugable tests..."
	@$(MAKE) -f $(DEVFILE) test

clean:
	@echo "Cleaning object files"
	@$(MAKE) -f $(PRODFILE) clean
	@$(MAKE) -f $(DEVFILE) clean
	@rm -rf objs/

fclean: clean
	@echo "Cleaning everything"
	@$(MAKE) -f $(PRODFILE) fclean
	@$(MAKE) -f $(DEVFILE) fclean

getSources:
	@rm -f $(SOURCEMAP)
	@rm -f $(TESTSOURCEMAP)
	@touch $(SOURCEMAP)
	@touch $(TESTSOURCEMAP) 
	@find src/ -name "*.c" | sed  "s/src\//SRCS+=/g" >> $(SOURCEMAP)
	@find tests/src/ -name "*.c" | sed "s/tests\/src\//TEST_SRCS+=/g" >> $(TESTSOURCEMAP)
