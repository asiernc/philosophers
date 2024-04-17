# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anovio-c <anovio-c@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/19 12:40:35 by anovio-c          #+#    #+#              #
#    Updated: 2024/04/16 22:32:10 by asiercara        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	philo

CC			=	gcc
INCL	 	=	includes
CFLAGS		=	-Wall -Wextra -Werror -g -I$(INCL)
RM			=	rm -f

SRCDIR		=	srcs/
OBJDIR		=	obj/

SRC			=	main.c 				\
				init.c				\
				philo_routine.c		\
				controller.c		\
				utils.c				\
				utils_libft.c		\

OBJS		=	$(addprefix $(OBJDIR), $(SRC:%.c=%.o))

all:			$(NAME)

$(NAME):		$(OBJS) Makefile #norm
				@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
				@echo "Linked into executable \033[0;32mphilo\033[0m with norminette \033[0;32mOK\033[0m."

#$(OBJDIR)/%.o:	$(SRCDIR)%.c
$(OBJDIR)/%.o: $(SRCDIR)%.c
				@mkdir -p $(OBJDIR)
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
