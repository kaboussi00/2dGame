NAME = 	so_long
INC = so_long.h
SRCS = parsing.c\
	so_long.c\
	utils00.c\
	utils01.c\
	get_next_line/get_next_line.c\
	get_next_line/get_next_line_utils.c\

OBJS = $(SRCS:.c=.o)

OBJS_B = $(SRCS_B:.c=.o)

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

CC = cc

all:$(NAME)

$(NAME):$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o:%.c $(INC)
	$(CC) $(CFLAGS) -Imlx -c $< -o $@
clean:
	$(RM) $(OBJS)

fclean:clean
	$(RM) $(NAME)

re: fclean all