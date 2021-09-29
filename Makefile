# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ychennaf <ychennaf@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/27 15:38:35 by ychennaf          #+#    #+#              #
#    Updated: 2021/06/02 14:12:40 by ychennaf         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Wextra -Werror
NAME_CHECK = checker
NAME_PS = push_swap
LIBPUSH_SWAP = libpush_swap.a
LIBCHECK = libchecker.a
MAIN_CHECK = srcs/checker.c
MAIN_PS = srcs/push_swap.c
SRCS = srcs/check_arg.c \
		srcs/ft_strcmp.c \
		srcs/get_next_line_bonus.c \
		srcs/get_next_line_utils_bonus.c \
		srcs/pop.c \
		srcs/push.c \
		srcs/rotate.c \
		srcs/swap.c \
		srcs/utils.c \
		srcs/utils2.c \
		srcs/utils_stack.c \
		srcs/utils_options.c \
		srcs/utils_tab.c \
		srcs/chunk_pivot_utils.c \
		srcs/push_swap_utils.c \
		srcs/list_to_tab_alloc_size.c \
		srcs/sorting_func_part.c \
		srcs/small_sort.c \
		srcs/quicksort.c

OBJS = $(SRCS:.c=.o)
MAIN_CHECK_O = $(MAIN_CHECK:.c=.o)
MAIN_PS_O = $(MAIN_PS:.c=.o)

HEADERS = -I libft -I .

all : mylib $(NAME_CHECK) $(NAME_PS)

$(NAME_CHECK): $(MAIN_CHECK_O) $(OBJS)
	ar rcs $(LIBCHECK) $(MAIN_CHECK_O) $(OBJS)
	$(CC) $(FLAGS) $(HEADERS) $(MAIN_CHECK_O) $(OBJS) libft/libft.a -o $(NAME_CHECK)

$(NAME_PS): $(MAIN_PS_O) $(OBJS)
	ar rcs $(LIBPUSH_SWAP) $(MAIN_PS_O) $(OBJS)
	$(CC) $(FLAGS) $(HEADERS) $(LIBPUSH_SWAP) libft/libft.a -o $(NAME_PS)

clean:
	cd libft && $(MAKE) clean
	rm -rf $(OBJS)
	rm -rf $(MAIN_CHECK_O)
	rm -rf $(MAIN_PS_O)

fclean: clean
	cd libft && $(MAKE) fclean
	rm -f $(NAME_CHECK)
	rm -f $(NAME_PS)
	rm -rf $(LIBPUSH_SWAP)
	rm -rf $(LIBCHECK)

mylib:
	cd libft && $(MAKE)

re: fclean all

%.o : %.c push_swap.h libft/libft.h
	$(CC) $(FLAGS) $(HEADERS) -c $< -o $@