# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Cutku <cutku@student.42heilbronn.de>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/05 15:43:45 by Cutku             #+#    #+#              #
#    Updated: 2023/02/09 18:29:09 by Cutku            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DEF_COLOR = \033[0;39m
RED = \033[0;91m
GREEN = \033[0;32m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

.SILENT:
# Sources
PS_SRCS		=	push_swap.c push.c rotate.c swap.c push_swap_utils.c lis.c small_functions.c \
				error_control.c memory_free.c extra_utils.c
PS_OBJS		=	$(PS_SRCS:.c=.o)

PS_MAIN		=	ps_main.c
PS_MAIN_OBJ	=	$(PS_MAIN:.c=.o)

GNL_SRCS	=	gnl/get_next_line.c gnl/get_next_line_utils.c
GNL_OBJS	=	$(GNL_SRCS:.c=.o)

CHECK_SRCS	= checker_bonus/checker.c
CHECK_OBJS	=	$(CHECK_SRCS:.c=.o)

LIBFT		= ./libft/
LIBFT_LIB	= ./libft/libft.a

FT_PRINTF	= ./printf/
PRINTF_LIB	= ./printf/libftprintf.a

CC			= gcc
RM			= rm -f
CFLAGS		= -Wall -Wextra -Werror 

NAME		= push_swap
NAME_B		= checker

all: $(NAME)

$(NAME): $(PS_OBJS) $(GNL_OBJS) $(PS_MAIN_OBJ)
	make bonus -C $(LIBFT) && make clean -C $(LIBFT)
	echo "$(GREEN)Libft compiled successfully!$(DEF_COLOR)"
	make -C $(FT_PRINTF) && make clean -C $(FT_PRINTF)
	echo "$(GREEN)Ft_Printf compiled successfully!$(DEF_COLOR)"
	$(CC) $(CFLAGS) $(PS_MAIN_OBJ) $(PS_OBJS) $(GNL_OBJS) $(LIBFT_LIB) $(PRINTF_LIB) -o $(NAME)
	echo "$(GREEN)Push_Swap compiled successfully!$(DEF_COLOR)"

$(NAME_B): $(PS_OBJS) $(GNL_OBJS) $(CHECK_OBJS)
	make bonus -C $(LIBFT) && make clean -C $(LIBFT)
	echo "$(GREEN)Libft compiled successfully!$(DEF_COLOR)"
	make -C $(FT_PRINTF) && make clean -C $(FT_PRINTF)
	echo "$(GREEN)Ft_Printf compiled successfully!$(DEF_COLOR)"
	$(CC) $(CFLAGS) $(CHECK_OBJS) $(PS_OBJS) $(GNL_OBJS) $(LIBFT_LIB) $(PRINTF_LIB) -o $(NAME_B)
	echo "$(GREEN)Checker compiled successfully!$(DEF_COLOR)"

clean:
	$(RM) $(PS_OBJS) $(PS_MAIN_OBJ)
	$(RM) $(GNL_OBJS) $(CHECK_OBJS)

fclean: clean
	make fclean -C $(LIBFT)
	make fclean -C $(FT_PRINTF)
	$(RM) $(NAME)
	$(RM) $(NAME_B)

re:	fclean all

bonus:	all $(NAME_B)


.PHONY:	all clean fclean re bonus