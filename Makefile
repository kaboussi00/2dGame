NAME = 	so_long
NAME_B = so_long_bonus
INC = so_long.h
SRCS = parsing.c\
	parsing01.c\
	so_long.c\
	utils00.c\
	utils01.c\
	get_next_line/get_next_line.c\
	get_next_line/get_next_line_utils.c\

SRCS_B = parsing_bonus.c\
	parsing_bonus01.c\
	so_long_bonus.c\
	so_long_bonus01.c\
	utils00_bonus.c\
	utils01_bonus.c\
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

bonus:$(NAME_B)

$(NAME_B):$(OBJS_B)
	$(CC) $(CFLAGS) $(OBJS_B) -lmlx -framework OpenGL -framework AppKit -o $(NAME_B)

clean:
	$(RM) $(OBJS) $(OBJS_B)

fclean:clean
	$(RM) $(NAME) $(NAME_B)

re: fclean all