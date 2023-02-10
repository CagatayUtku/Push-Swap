# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Cutku <cutku@student.42heilbronn.de>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/25 20:43:45 by Cutku             #+#    #+#              #
#    Updated: 2023/02/01 17:11:54 by Cutku            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:

SRCS	=	ft_printf.c ptf_putchar_fd.c ptf_putstr_fd.c \
			printf_itoa.c ft_itoa_uint.c ptf_strlen.c
 
OBJS	= $(SRCS:.c=.o)

CC		= gcc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror -I.

NAME	= libftprintf.a

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:		fclean all

.PHONY:	all clean fclean re