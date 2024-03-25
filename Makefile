NAME = push_swap
B_NAME = checker
SRCS = $(shell find src -name "*.c") libs/get_next_line/get_next_line.c
OBJS = $(SRCS:.c=.o)
B_SRCS = $(shell find bonus/src -name "*.c")
B_OBJS = $(B_SRCS:.c=.o) libs/get_next_line/get_next_line.c
CFLAGS = #-Wall -Wextra -Werror
INC = includes/push_swap.h
LIBFT = libs/libft/libft.a
FT_PRINTF = libs/ft_printf/libftprintf.a
ARR = $(shell seq 1 500 | sort -R | tr '\n' ' ')

all : $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(FT_PRINTF)
	cc $(CFLAGS) $(OBJS) $(LIBFT) $(FT_PRINTF) -o $(NAME)

%.o : %.c $(INC)
	cc $(CFLAGS) -c $< -o $@

$(LIBFT) :
	@make bonus -C libs/libft/

$(FT_PRINTF) :
	@make -C libs/ft_printf/

bonus : $(B_NAME)

$(B_NAME): $(B_OBJS) $(LIBFT) $(FT_PRINTF)
	cc $(CFLAGS) $(B_OBJS) $(LIBFT) $(FT_PRINTF) -o $(B_NAME)

%_bonus.o : %_bonus.c bonus/includes/push_swap_bonus.h
	cc $(CFLAGS) -c $< -o $@

clean :
	@make clean -C libs/libft/
	@make clean -C libs/ft_printf/
	$(RM) $(OBJS)

fclean : clean
	@make fclean -C libs/libft/
	@make fclean -C libs/ft_printf/
	$(RM) $(NAME)

re : fclean all

run : all
	./push_swap $(ARR);
	@echo "";

visualize : all
	./visualizer-1.py $(ARR);