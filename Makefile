NAME:= libftprintf.a

CC:= gcc
CFLAGS:= -Wall -Werror -Wextra

SRCS_DIR:= srcs/
SRCS_NAME:= main.c \
	ft_printf_utils.c \
	ft_printf_utils_con.c \
	ft_printf_utils_flag1.c \
	ft_printf_utils_flag2.c \
	ft_printf_utils_flag3.c \
	ft_printf.c \
	ft_printf_utils_cs.c \
	ft_printf_utils_diu.c \
	ft_printf_utils_pxX.c \
	ft_printf_utils_len.c \

BONUS_NAME:= main.c \
	ft_printf_utils.c \
	ft_printf_utils_con.c \
	ft_printf_utils_flag1.c \
	ft_printf_utils_flag2.c \
	ft_printf_utils_flag3.c \
	ft_printf.c \
	ft_printf_utils_cs.c \
	ft_printf_utils_diu.c \
	ft_printf_utils_pxX.c \
	ft_printf_utils_len.c \

OBJS_DIR = objs/
OBJS_NAME:= $(SRCS_NAME:.c=.o)
OBJS:= $(addprefix $(OBJS_DIR), $(OBJS_NAME))

BONUS_OBJS_NAME:= $(BONUS_NAME:.c=.o)
BONUS:= $(addprefix $(OBJS_DIR), $(BONUS_OBJS_NAME))

INC:= includes

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $^
	$(CC) -o a.out $(OBJS_DIR)main.o -lftprintf -L. -I./$(INC)
	##$(CC) -g -D main.c -o a.out -lftprintf -L. -I./$(INC)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	mkdir -p $(OBJS_DIR)
	$(CC) -I./$(INC) $(CFLAGS) -c $< -o $@

bonus: $(BONUS)
	ar -r $(NAME) $^
	$(CC) -o a.out $(OBJS_DIR)main.o -lftprintf -L. -I./$(INC)
	##$(CC) -g -D main.c -o a.out -lftprintf -L. -I./$(INC)

clean:
	rm -rf $(OBJS_DIR) a.out

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
