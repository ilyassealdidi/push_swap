NAME = push_swap
B_NAME = checker
SRCS = $(shell find src -name "*.c")
OBJS = $(SRCS:.c=.o)
B_SRCS = $(shell find bonus/src -name "*.c")
B_OBJS = $(B_SRCS:.c=.o)
CFLAGS = -Wall -Wextra -Werror
INC = includes/push_swap.h
LIBFT = libs/libft/libft.a
ARR = $(shell seq 1 1000 | sort -R | tr '\n' ' ')

all : $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	cc $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

%_bonus.o : %_bonus.c bonus/includes/push_swap_bonus.h
	cc $(CFLAGS) -c $< -o $@

%.o : %.c $(INC)
	cc $(CFLAGS) -c $< -o $@

$(LIBFT) :
	@make bonus -C libs/libft/

bonus : $(B_NAME)

$(B_NAME): $(B_OBJS) $(LIBFT)
	cc $(CFLAGS) $(B_OBJS) $(LIBFT) -o $(B_NAME)

clean :
	@make clean -C libs/libft/
	$(RM) $(OBJS)

fclean : clean
	@make fclean -C libs/libft/
	$(RM) $(NAME)

re : fclean all

run : all
	@./push_swap $(ARR);
	@echo "";

visualize : all
	@./visualizer-1.py $(ARR)