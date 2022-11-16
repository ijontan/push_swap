# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: itan <itan@student.42kl.edu.my>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/18 20:55:16 by itan              #+#    #+#              #
#    Updated: 2022/11/16 16:49:29 by itan             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

SRC_DIR	= src
OBJ_DIR	= obj

# this is for mirroring the out dir
OBJ_DIRS= $(subst $(SRC_DIR), $(OBJ_DIR), $(shell find src -type d))

SRC		= $(shell find $(SRC_DIR) -name '*.c')
OBJ		= $(subst $(SRC_DIR), $(OBJ_DIR), $(SRC:.c=.o))

AR		= ar -rcs
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra
RM		= rm -f
INC		= $(addprefix -I , $(shell find includes -type d))
LIB		= -Llib -lft

# this is for debugging
DNAME	= debug.out
DDIR	= test
DFLAGS	= -fsanitize=address -fdiagnostics-color=always -g3
DSRC	= $(shell find $(DDIR) -name '*.c')
DOBJ	= $(DSRC:.c=.o)

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c
				@mkdir -p $(OBJ_DIRS)
				$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(DDIR)/%.o:	$(DDIR)/%.c
				@mkdir -p $(DDIR)
				$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(NAME):	$(OBJ)
			$(CC) $(CFLAGS) $(OBJ) $(INC) -o $(NAME) $(LIB)

$(DNAME):	$(SRC) $(DSRC)
			$(CC) $(CFLAGS) $(DFLAGS) $(INC) $(SRC) $(DSRC) -o $(DNAME) $(LIB)

debug:	$(DNAME)

all:	$(NAME)

bonus:	$(NAME)

clean:
		@$(RM) $(OBJ) $(DOBJ)

fclean:	clean
		$(RM) $(NAME)
		$(RM) $(DNAME)
		$(RM) -r $(OBJ_DIR)

re:			fclean all

.PHONY: all clean fclean re debug bonus

norm:
		@norminette $(SRC_DIR) includes/