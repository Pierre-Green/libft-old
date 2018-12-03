include ../../global.mk

NAME	=	str

SRC 	= 	ft_strcat.c		\
			ft_strchr.c		\
			ft_strclr.c		\
			ft_strcmp.c		\
			ft_strcpy.c		\
			ft_strdel.c		\
			ft_strdup.c		\
			ft_strequ.c		\
			ft_striter.c	\
			ft_striteri.c	\
			ft_strjoin.c	\
			ft_strlcat.c	\
			ft_strlen.c		\
			ft_strmap.c		\
			ft_strmapi.c	\
			ft_strncat.c	\
			ft_strncmp.c	\
			ft_strncpy.c	\
			ft_strnequ.c	\
			ft_strnew.c		\
			ft_strnstr.c	\
			ft_strrchr.c	\
			ft_strsplit.c	\
			ft_strstr.c		\
			ft_strsub.c		\
			ft_strtrim.c	\

OBJ	= $(SRC:.c=.o)

all: prepare $(OBJ)

prepare:
	@mkdir -p $(ODIR)/$(NAME)

$(OBJ): %.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $(ODIR)/$(NAME)/$@