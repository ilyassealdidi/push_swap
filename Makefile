NAME = push_swap
B_NAME = checker
SRCS = $(shell find src -name "*.c")
OBJS = $(SRCS:.c=.o)
B_SRCS = $(shell find bonus/src -name "*.c")
B_OBJS = $(B_SRCS:.c=.o)
CFLAGS = -Wall -Wextra -Werror
INC = includes/push_swap.h
LIBFT = libs/libft/libft.a

all : $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	cc $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

%_bonus.o : %_bonus.c bonus/includes/push_swap_bonus.h
	cc $(CFLAGS) -c $< -o $@

%.o : %.c $(INC)
	cc $(CFLAGS) -c $< -o $@

$(LIBFT) :
	@make -C libs/libft/

bonus : $(B_NAME)

$(B_NAME): $(B_OBJS) $(LIBFT)
	cc $(CFLAGS) $(B_OBJS) $(LIBFT) -o $(B_NAME)

clean :
	@make clean -C libs/libft/
	$(RM) $(OBJS) $(B_OBJS)

fclean : clean
	@make fclean -C libs/libft/
	$(RM) $(NAME) $(B_NAME)

re : fclean all
