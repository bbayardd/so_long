NAME		=	so_long

MLX_DIR		=	/home/artem/Sl21/minilibx-linux/

SRC_DIR		=	./src/

HEADER		= 	./src/so_long.h

SRC_FILES	=	start.c\
				map_work.c\
				exit_error.c\
				libft.c\
				ft_split.c\
				wndw_make_map.c\
				key_press.c\

INCLUDES	=	/home/artem/Sl21//minilibx-linux/mlx.h
CC			=	clang
FLAGS		=	-g -Wall -Wextra -Werror -I $(INCLUDES)
LIBS		= 	-L $(MLX_DIR) -lmlx -lXext -lX11 -lm


SRCS 		=	$(addprefix $(SRC_DIR),$(SRC_FILES))
OBJS		=	$(SRCS:c=o)

all: $(NAME)

$(NAME):	$(OBJS) 
				cd $(MLX_DIR) && ./configure
				$(CC) $(FLAGS) -o $(NAME) $(SRCS) $(LIBS)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY = all clean fclean re