NAME		= cub3d
#BONUS		= CUB3D
SRCS = main.c inits.c utils/utils.c parse2.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
	parse.c parse_player.c utils/lst.c \
	utils/utils2.c utils/utils3.c parse3.c utils/utils4.c

#main.c calcs.c calcs2.c keys.c inits.c draws.c sprite.c utils/utils.c parse2.c \
	get_next_line/get_next_line.c get_next_line/get_next_line_utils.c parse.c parse_player.c utils/lst.c \
	bmp.c utils/utils2.c utils/utils3.c parse3.c utils/utils4.c

#SRCS_BONUS = cub3d_bonus.c calcs_bonus.c calcs2.c keys.c inits.c draws.c sprite.c utils/utils.c parse2.c \
	get_next_line/get_next_line.c get_next_line/get_next_line_utils.c parse.c parse_player.c utils/lst.c \
	bmp.c utils/utils2.c utils/utils3.c parse3.c utils/utils4.c

FLAGS = -Wall -Werror -Wextra

MLX_INC =		/usr/X11/include
MLX_LIB =		/usr/X11/lib
MLX_FLAGS =	-lX11 -lXext
MLX_FLAGS += -L/usr/X11/lib /usr/X11/lib/libmlx.a -lXext -lX11 -lbsd

# mac
MLXDIR = 	./mlx
MLX_FLAGS = 	-framework OpenGL -framework AppKit
MLX_INC = 	$(MLXDIR)
MLX_LIB = 	$(addprefix $(MLXDIR)/,libmlx.a)


all:		$(NAME) $(MLX_LIB)

$(NAME):	$(SRCS) get_next_line/get_next_line.h cub3d.h $(MLX_LIB)
			gcc $(FLAGS) -I $(MLX_INC) -g $(MLX_LIB) $(SRCS) -lm -o $(NAME) $(MLX_FLAGS)

$(MLX_LIB):
			@make -C $(MLXDIR)

#bonus:		$(BONUS) $(MLX_LIB)
#$(BONUS):	$(SRCS_BONUS) get_next_line/get_next_line.h cub3d.h $(MLX_LIB)
#			gcc $(FLAGS) -I $(MLX_INC) -g $(MLX_LIB) $(SRCS) -lm -o $(BONUS) $(MLX_FLAGS)


clean:
			rm -rf $(SRCS:.c=.o)
			make -C $(MLXDIR) clean

fclean:		clean
			rm -f $(NAME) cub3d.bmp
			make -C $(MLXDIR) fclean

re:			fclean all
