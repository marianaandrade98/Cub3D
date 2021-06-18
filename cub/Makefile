CC	= gcc
MLX =  -lmlx -lm -framework OpenGL -framework AppKit
CFLAGS = -Wall -Werror -Wextra
RM			= rm -f

NAME		= cub3d
BONUS		= CUB3D
INCLUDE		= cub3d.h

SRCS = main.c calcs.c calcs2.c keys.c inits.c draws.c sprite.c utils/utils.c parse2.c \
	get_next_line/get_next_line.c get_next_line/get_next_line_utils.c parse.c parse_player.c utils/lst.c \
	utils/utils2.c utils/utils3.c parse3.c utils/utils4.c

SRCS_BONUS = cub3d_bonus.c calcs_bonus.c calcs2.c keys.c inits_bonus.c draws.c sprite.c utils/utils.c parse2_bonus.c \
	get_next_line/get_next_line.c get_next_line/get_next_line_utils.c parse_bonus.c parse_player.c utils/lst.c \
	bmp.c utils/utils2.c utils/utils3.c parse3.c utils/utils4.c

OBJS = $(SRCS:.c=.o)

BONUS_OBJS = $(SRCS_BONUS:.c=.o)

$(NAME) : $(OBJS)
	gcc  $(OBJS) $(MLX) -o $(NAME)

$(BONUS) : $(BONUS_OBJS)
	gcc $(BONUS_OBJS) $(MLX) -o $(BONUS)

.c.o:
	gcc $(CFLAGS) -c $< -o $(<:.c=.o)

all : $(NAME)

clean :
	rm -rf $(OBJS) $(BONUS_OBJS)

fclean : clean
	rm -rf $(NAME)
	rm -rf $(BONUS)
	rm -rf screenshot.bmp

re : fclean all

bonus : $(BONUS)
