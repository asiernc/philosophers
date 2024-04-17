# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anovio-c <anovio-c@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/19 12:40:35 by anovio-c          #+#    #+#              #
#    Updated: 2024/04/17 09:52:00 by anovio-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	philo

CC			=	gcc
INCL	 	=	includes
CFLAGS		=	-Wall -Wextra -Werror -g -I$(INCL)
RM			=	rm -f

SRCDIR		=	srcs/
OBJDIR		=	obj/

SRC			=	srcs/main.c 			\
				srcs/init.c				\
				srcs/philo_routine.c	\
				srcs/controller.c		\
				srcs/utils.c			\
				srcs/utils_libft.c		\

OBJS		=	$(SRC:%.c=%.o)

all:			$(NAME)

$(NAME):		$(OBJS) Makefile #norm
				@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
				@echo "Linked into executable \033[0;32mphilo\033[0m with norminette \033[0;32mOK\033[0m."

.c.o:
				@$(CC) $(CFLAGS) -c $< -o $@
				@echo "Compiling $<."

norm:
				norminette -R CheckForbiddenSourceHeader $(SRC)
				norminette -R CheckDefine $(INCL)

clean:
				@$(RM) -r $(OBJDIR)
				@echo "Removed object files."

fclean:			clean
				@$(RM) $(NAME)
				@echo "Removed executable."

re:				fclean all

PHONY:			all clean fclean re bonus norm
