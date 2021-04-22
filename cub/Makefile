CC			= gcc
CFLAGS		= -Lmlx -lmlx -framework OpenGL -framework AppKit -g
RM			= rm -f
NAME		= cub3d.a
INCLUDE		= cub3d.h
SRCS =	main.c
OBJS		= $(SRCS:.c=.o)
all:
	$(CC) -lmlx -lm -framework OpenGL -framework AppKit -g $(SRCS)
clean:
			$(RM) $(OBJS)
fclean:		clean
			$(RM) $(NAME)
re:
	$(RM) a.out