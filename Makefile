NAME = push_swap
SRCS = $(shell find src -name "*.c")
OBJS = $(SRCS:.c=.o)
CFLAGS = #-Wall -Wextra -Werror
INC = includes/push_swap.h
LIBFT = libs/libft/libft.a
FT_PRINTF = libs/ft_printf/libftprintf.a
ARR = $(shell seq 1 21 | sort -R | tr '\n' ' ' )

all : $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(FT_PRINTF)
	cc $(CFLAGS) $(OBJS) $(LIBFT) $(FT_PRINTF) -o $(NAME)

%.o : %.c $(INC)
	cc $(CFLAGS) -c $< -o $@

$(LIBFT) :
	@make bonus -C libs/libft/

$(FT_PRINTF) :
	@make -C libs/ft_printf/

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
	./push_swap $(ARR); echo "";

visualize : all
	./visualizer-1.py $(ARR)