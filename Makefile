# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anovio-c <anovio-c@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/19 12:40:35 by anovio-c          #+#    #+#              #
#    Updated: 2024/04/15 17:18:15 by anovio-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	philo

CC			=	gcc
INCL	 	=	includes
CFLAGS		=	-Wall -Wextra -Werror -I$(INCL)
RM			=	rm -f

SRCS		=	srcs/main.c 			\
				srcs/init.c				\
				srcs/philo_routine.c	\
				srcs/controller.c		\
				srcs/utils.c			\
				srcs/utils_libft.c		\

OBJS		=	$(SRCS:%.c=%.o)

OBJS_B		= 	$(BSRCS:%.c=%.o)

all:			$(NAME)

$(NAME):		$(OBJS) Makefile #norm
				@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
				@echo "Linked into executable \033[0;32mphilo\033[0m with norminette \033[0;32mOK\033[0m."

.c.o:
				@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)
				@echo "Compiling $<."


#bonus:			$(OBJS_B) Makefile $(LIBFT_A) $(GNL_A) norm
#				@$(CC) $(CFLAGS) -o $(NAME) $(OBJS_B)
#				@echo "Linked into executable \033[0;32mphilo\033[0m with bonus and norminette \033[0;32mOK\033[0m."

norm:
				norminette -R CheckForbiddenSourceHeader $(SRCS) $(BSRCS)
				norminette -R CheckDefine $(INCL)

clean:
				@$(RM) $(OBJS) $(OBJS_B)
				@echo "Removed object files."

fclean:			clean
				@$(RM) $(NAME)
				@echo "Removed executable."

re:				fclean all

PHONY:			all clean fclean re bonus norm
