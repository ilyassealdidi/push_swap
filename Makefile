NAME = push_swap

SRCS = src/*.c

CFLAGS = -Wall -Wextra -Werror 

LIBFT = libs/libft/libft.a

LIB = includes/push_swap.h

FT_PRINTF = libs/ft_printf/libftprintf.a

all : $(NAME)

$(NAME): $(SRCS) $(LIBFT) $(FT_PRINTF) $(LIB)
	cc $(CFLAGS) $(SRCS) $(LIBFT) $(FT_PRINTF) -o $(NAME)

$(LIBFT) :
	make bonus -C libs/libft/

$(FT_PRINTF) :
	make -C libs/ft_printf/

clean :
	make clean -C libs/libft/
	make clean -C libs/ft_printf/

fclean :
	make fclean -C libs/libft/
	make fclean -C libs/ft_printf/
	$(RM) $(NAME)

re : fclean all

