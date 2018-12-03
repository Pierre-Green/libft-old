include ../../global.mk

NAME	=	lst

SRC		=	ft_lstadd.c		\
			ft_lstat.c		\
			ft_lstdel.c		\
			ft_lstdelone.c	\
			ft_lstfold.c	\
			ft_lstiter.c	\
			ft_lstlast.c	\
			ft_lstmap.c		\
			ft_lstnew.c		\
			ft_lstsize.c	\

OBJ	= $(SRC:.c=.o)

all: prepare $(OBJ)

prepare:
	@mkdir -p $(ODIR)/$(NAME)

$(OBJ): %.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $(ODIR)/$(NAME)/$@