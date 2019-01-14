# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jquivogn <jquivogn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/26 00:27:28 by julesqvgn         #+#    #+#              #
#    Updated: 2019/01/14 19:19:01 by jquivogn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : all clean fclean re
.SILENT : $(OBJS) $(SRCS)

NAME = fractol

SRCS =	srcs/main.c\
		srcs/draw.c\
		srcs/init.c\
		srcs/output.c\
		srcs/check.c\
		srcs/julia.c\
		srcs/mandelbrot.c\
		srcs/pixel.c\
		srcs/hook.c\
		srcs/color.c\
		srcs/burningship.c\
		#srcs/hook2.c\
		#srcs/tools.c\

OBJS = $(SRCS:.c=.o)

INC = -I./include/

LIBFT = -lft -L./libft/ -I./libft/

MLX = -lmlx -framework OpenGL -framework AppKit

CFLAGS = -Wall -Werror -Wextra

CC = gcc

YEL = \033[1;33m
GRN = \033[0;32m
BLU = \033[1;34m
RED = \033[0;31m

all : $(NAME)

$(NAME) : $(OBJS) include/fractol.h
	@echo "$(BLU)libft compile..."
	@$(MAKE) -C libft/ 1>/dev/null || true
	@echo "$(GRN)[SUCCESS]"
	@echo "$(BLU)compilation .c with $(RED)$(FLAG)$(RED)"
	@echo "$(GRN)[SUCCESS]"
	@echo "$(BLU)creation -> $(RED)$(NAME)$(RED)"
	@$(CC) $(CFLAG) $(OBJS) $(LIBFT) -o $(NAME) $(MLX) $(INC) 01>/dev/null || true
	@echo "$(GRN)[SUCCESS]"

clean :
	@echo "$(YEL)suppression .o"
	@rm -rf $(OBJS)
	@$(MAKE) -C libft/ clean
	@echo "$(GRN)[SUCCESS]"

fclean : clean
	@echo "$(YEL)suppression $(NAME)"
	@rm -rf $(NAME)
	@$(MAKE) -C libft/ fclean
	@echo "$(GRN)[SUCCESS]$(RED)"

norme :
	@echo "$(BLU)norme .c files$(YEL)"
	@norminette $(SRCS)
	@echo "$(GRN)[SUCCESS]"

re : fclean all
