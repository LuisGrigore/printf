CC = gcc
CCFLAGS = -Wall -Wextra -Werror

TEST_NAME = test_token

NAME = $(TEST_NAME).out

BASE_DIR = ../..
LIBFT_DIR = $(BASE_DIR)/libc

LIBFT_LIB = $(LIBFT_DIR)/libft.a
TESTED = $(BASE_DIR)/token/token.c
TESTED_DEPENDENCIES = $(BASE_DIR)/token_util/token_util_functs/token_util_chars_functs.c $(BASE_DIR)/token_util/token_util_functs/token_util_num_functs.c $(BASE_DIR)/token_util/token_util_functs/token_util_extra_functs.c
UNITY_TEST = $(BASE_DIR)/Unity-master/src/unity.c

SRC = $(TEST_NAME).c $(TESTED) $(TESTED_DEPENDENCIES) $(UNITY_TEST) $(LIBFT_LIB)

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
