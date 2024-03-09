NAME = push_swap

SRCS = main.c

CFLAGS = #-Wall -Wextra -Werror 

LIBFT = utils/libft/libft.a

FT_PRINTF = utils/ft_printf/libftprintf.a

all : $(NAME)

$(NAME): $(SRCS) $(LIBFT) $(FT_PRINTF) push_swap.h
	cc $(CFLAGS) $(SRCS) $(LIBFT) $(FT_PRINTF) -o $(NAME)

$(LIBFT) :
	make bonus -C utils/libft/

$(FT_PRINTF) :
	make -C utils/ft_printf/

clean :
	make clean -C utils/libft/
	make clean -C utils/ft_printf/

fclean :
	make fclean -C utils/libft/
	make fclean -C utils/ft_printf/
	$(RM) $(NAME)

re : fclean all

