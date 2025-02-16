CC = gcc
CCFLAGS = -Wall -Wextra -Werror

NAME = printf.out
SRC = main.c ./tokenizer/tokenizer.c ./token_list/token_list.c ./token/token.c ./token_factory/token_factory.c ./token_util/token_util_functs/token_util_chars_functs.c ./token_util/token_util_functs/token_util_num_functs.c ./token_util/token_util_functs/token_util_extra_functs.c ./libc/ft_substr.c ./libc/ft_strchr.c ./libc/ft_isprint.c ./libc/ft_strlen.c ./libc/ft_putstr_fd.c ./libc/ft_putchar_fd.c ./libc/ft_strncmp.c ./libc/ft_strnstr.c ./libc/ft_putnbr_fd.c ./parser/parser.c ft_printf.c

OBJ = $(SRC:.c=.o)
INCLUDE = printf.h

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CCFLAGS) $(OBJ) -o $(NAME)

%.o: %.c $(INCLUDE)
	$(CC) $(CCFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
