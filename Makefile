# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pnamnil <pnamnil@student.42bangkok.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/07 10:06:31 by pnamnil           #+#    #+#              #
#    Updated: 2023/09/17 16:56:51 by pnamnil          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= libftprintf.a
PREFIX 		= ft_printf
SRCS 		= $(addprefix $(PREFIX), .c _flags.c _utils.c _spec_c.c _spec_s.c\
				_spec_d.c _spec_p.c _spec_u.c _spec_x.c)
OBJS 		= $(patsubst %.c, bin/%.o, $(SRCS))

LIBFT_PATH 	= libft
LIBFT_OBJS 	= $(LIBFT_PATH)/bin/*.o
LIBFT_MAKE 	= $(MAKE) -C $(LIBFT_PATH) bonus

CC 			= cc
CFLAGS 		= -Wall -Werror -Wextra -I$(LIBFT_PATH)

all: $(NAME)

bonus: $(NAME)

bin/%.o: %.c
	mkdir -p bin
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): libft_make $(OBJS)
	ar rcs $(NAME) $(OBJS) $(LIBFT_OBJS)

libft_make:
	$(LIBFT_MAKE)

clean:
	rm -rf bin

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_PATH) fclean

re: fclean all
