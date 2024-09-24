# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yalazrek <yalazrek@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/15 17:42:59 by ybouryal          #+#    #+#              #
#    Updated: 2024/09/15 18:30:44 by yalazrek         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -I $(HEAD)
TESTCFLAGE = $(CFLAGS) -fsanitize=address

HEAD = $(HEAD_DIR)
HEAD_DIR = includes
SRC_DIR = src
HEAD = $(SRC_DIR)/rush.h
SRCS = $(wildcard $(SRC_DIR)/*.c)

NAME = rush-02
TEST = test

all: $(NAME)

$(TEST): $(SRCS)
	$(CC) $(TESTCFLAGS) -o $@ $^
$(NAME): $(SRCS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

.PHONY: clean fclean $(NAME) $(TEST)
