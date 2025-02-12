# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ego <ego@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/15 12:42:34 by hcavet            #+#    #+#              #
#    Updated: 2025/02/12 14:18:54 by ego              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

IDIR	=	include/
SDIR	=	src/

SRC		=	fractol.c				\
			init.c					\
			utils.c					\
			events.c				\
			fractals/julia.c		\
			fractals/mandelbrot.c	\
			display.c				\
			render.c				\
			color.c
SRCS	=	$(addprefix $(SDIR), $(SRC))
OBJS	=	$(SRCS:.c=.o)

MPATH	=	minilibx/
MLX		=	libmlx.a

CC		=	gcc
RM		=	rm -f
CFLAGS	=	-Wall -Wextra -Werror
NAME	=	fractol

all		:	$(NAME)

$(NAME)	:	$(MLX) $(OBJS) header
			echo "Linking object files..."
			$(CC) $(CFLAGS) $(OBJS) -I $(IDIR) -L$(MPATH) -lmlx -lXext -lX11 -lm -o $(NAME)
			echo "$(GREEN)[OK] $(NAME) is ready!$(RESET)"

bonus	:	all

.c.o	:
			echo "Compiling $<..."
			$(CC) $(CFLAGS) -I$(IDIR) -c $< -o $(<:.c=.o)

$(MLX)	:
			if test ! -f $(MPATH)$(MLX); then	\
				echo "Building MiniLibX...";	\
				make -sC $(MPATH);	\
				echo "$(GREEN)[OK] MiniLibX is ready!$(RESET)";	\
			fi

norm	:
			norminette -R CheckForbiddenSourceHeader $(SRCS) $(IDIR)

clean	:
			echo "Removing object files..."
			make --no-print-directory clean -sC $(MPATH)
			$(RM) $(OBJS)
			echo "$(ORANGE)[OK] All object files have been removed.$(RESET)"

fclean	:	clean
			echo "Removing binary files..."
			$(RM) $(NAME)
			echo "$(ORANGE)[OK] All binary files have been removed.$(RESET)"

re		:	fclean all

.PHONY	:	all clean fclean re
.SILENT	:	all $(NAME) bonus $(OBJS) norm clean fclean re header $(MLX)

RED		=	\033[31m
ORANGE	=	\033[38;5;214m
YELLOW	=	\033[33m
GREEN	=	\033[32m
BLUE	=	\033[34m
VIOLET	=	\033[38;5;93m
ITALIC	=	\033[3m
RESET	=	\033[0m

header	:
			echo "======================================="
			echo "$(RED)   __                _               _ $(RESET)"
			echo "$(RED)  / _|              | |             | |$(RESET)"
			echo "$(ORANGE) | |_ _ __ __ _  ___| |_ ______ ___ | |$(RESET)"
			echo "$(YELLOW) |  _| '__/ _  |/ __| __|______| _ \| |$(RESET)"
			echo "$(GREEN) | | | | | (_| | (__| |_      | (_) | |$(RESET)"
			echo "$(BLUE) |_| |_|  \__,_|\___|\__|      \___/|_|$(RESET)"
			echo "$(ITALIC)$(VIOLET)                 by Ego\n$(RESET)"
			echo "=======================================\n"
