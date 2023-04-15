NAME = minishell


OBJS =  minishell.o utils.o

CC = cc
CFLAGS = -Wall -Wextra -Werror -I ./includes

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	@cd libft && make 
	@$(CC) $(CFLAGS) $(OBJS) ./libft/libft.a -o $(NAME)

$(OBJS): ./includes/minishell.h

clean:
	@cd libft && make clean
	@$(RM) $(OBJS)

fclean: clean
	@cd libft && make fclean
	@$(RM) $(NAME)

re: fclean all