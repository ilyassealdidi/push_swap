NAME = push_swap
B_NAME = checker
SRCS = src/instructions/push.c src/instructions/reverse_rotate.c src/instructions/rotate.c src/instructions/swap.c src/main.c src/parse/parser.c src/sort/sort.c src/sort/utils.c
OBJS = $(SRCS:.c=.o)
B_SRCS = bonus/src/checker/checker_bonus.c bonus/src/instructions/push_bonus.c bonus/src/instructions/reverse_rotate_bonus.c bonus/src/instructions/rotate_bonus.c \
	bonus/src/instructions/swap_bonus.c bonus/src/main_bonus.c bonus/src/parse/parser_bonus.c bonus/src/utils_bonus.c
B_OBJS = $(B_SRCS:.c=.o)
CFLAGS = -Wall -Wextra -Werror
INC = includes/push_swap.h
LIBFT = libs/libft/libft.a

all : $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	cc $(OBJS) $(LIBFT) -o $(NAME)

%_bonus.o : %_bonus.c bonus/includes/push_swap_bonus.h
	cc $(CFLAGS) -c $< -o $@

%.o : %.c $(INC)
	cc $(CFLAGS) -c $< -o $@

$(LIBFT) :
	@make -C libs/libft/

bonus : $(B_NAME)

$(B_NAME): $(B_OBJS) $(LIBFT)
	cc $(B_OBJS) $(LIBFT) -o $(B_NAME)

clean :
	@make clean -C libs/libft/
	$(RM) $(OBJS) $(B_OBJS)

fclean : clean
	@make fclean -C libs/libft/
	$(RM) $(NAME) $(B_NAME)

re : fclean all
