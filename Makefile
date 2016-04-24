
CC	=	gcc
NAME	=	ls
SRC	=	ls.c\
		ls_fct.c\
		list.c\
		list2.c\
		tree.c\
		term.c
OBJ	=	$(SRC:.c=.o)
CFLAGS	+=	-W -Wall -Werror -Wstrict-prototypes -pedantic -g
LDFLAGS	+=	-L./ -lmy_FreeBSD -I. -ltermcap -g

all: $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	rm -f *~ $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all