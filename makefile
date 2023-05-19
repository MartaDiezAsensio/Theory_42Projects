# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdiez-as <mdiez-as@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/19 20:43:12 by mdiez-as          #+#    #+#              #
#    Updated: 2023/05/19 21:27:09 by mdiez-as         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

CC		= gcc
CFLAG	= -Wall -Wextra -Werror

RM		= rm -f

AR		= ar

ARFLAGS	= crs

INCLUDES	= printf.h 

SRCS	=  ft_strlen.c		\
		  ft_putchar.c		\
		  ft_putstr.c		\
		  ft_putnbr.c		\
		  ft_print_pointer.c	\

OBJS	= $(SRCS:.c=.o)

all : $(NAME)

%.o : %.c $(INCLUDES)
	$(CC) $(CFLAG) -c $< -o $@

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

 .PHONY : all clean fclean re