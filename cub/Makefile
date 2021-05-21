NAME	=	cub3D
SRCS	=	main.c

FLAGS	=	-Wall -Wextra -Werror

MLX_INC =	/usr/X11/include
MLX_LIB =	/usr/X11/lib
MLX_FLAGS =	-lX11 -lXext
MLX_FLAGS += -L/usr/X11/lib /usr/X11/lib/libmlx.a -lXext -lX11 -lbsd

# mac
MLXDIR	=	./mlx
MLX_FLAGS	=	-framework OpenGL -framework AppKit
MLX_INC =	$(MLXDIR)
MLX_LIB =	$(addprefix $(MLXDIR)/,libmlx.a)

all:		$(NAME) $(MLX_LIB)

$(NAME):	$(SRCS) get_next_line/get_next_line.h cub3d.h $(MLX_LIB)
			gcc $(FLAGS) -I $(MLX_INC) -g $(MLX_LIB) $(SRCS) -lm -o $(NAME) $(MLX_FLAGS)

$(MLX_LIB):
			@make -C $(MLXDIR)

clean:
			rm -rf $(SRCS:.c=.o)
			make -C $(MLXDIR) clean

fclean:		clean
			rm -f $(NAME) cub3d.bmp
			make -C $(MLXDIR) fclean

re:			fclean all 