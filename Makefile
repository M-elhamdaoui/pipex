# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mel-hamd <mel-hamd@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/07 15:59:14 by mel-hamd          #+#    #+#              #
#    Updated: 2024/01/07 15:59:16 by mel-hamd         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
BONUS = pipex_bonus
CC = cc
FLAGS = -Wall -Wextra -Werror
LIB = lib
LIBNAME = libft
LIB_RELINK = libft/libft.h
PIPEX_RELINK = pipex.h
BONUS_PIPEX_RELINK =  pipex_bonus.h

SRC = pipex.c utils.c
SRCBON =splitting.c  pipex_bonus.c utils_bonus.c utils2_bonus.c

OBJBON = $(SRCBON:.c=.o)
OBJ = $(SRC:.c=.o)


all : $(LIB) $(NAME)
bonus : $(LIB) $(BONUS)

$(LIB) :
	@make -C $(LIBNAME)

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $^ -L $(LIBNAME) -l ft -o $@


$(BONUS) : $(OBJBON)
	$(CC) $(FLAGS) $^ -L $(LIBNAME) -l ft -o $@

$(OBJBON) : %.o : %.c $(LIB_RELINK) $(BONUS_PIPEX_RELINK)
	$(CC) $(FLAGS) -I $(LIBNAME) -c $< -o $@

$(OBJ) : %.o : %.c $(LIB_RELINK) $(PIPEX_RELINK)
	$(CC) $(FLAGS) -I $(LIBNAME) -c $< -o $@


clean :
	rm  -f $(OBJ) $(OBJBON) 
	@make clean -C $(LIBNAME)
fclean : clean
	rm  -f $(NAME) $(BONUS)
	@make fclean -C $(LIBNAME)

re : fclean all

.PHONY: clean
