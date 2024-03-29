# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: itan <itan@student.42kl.edu.my>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/18 20:55:16 by itan              #+#    #+#              #
#    Updated: 2023/03/16 01:10:34 by itan             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

# ** main src ** #
SRC_DIR	= src
OBJ_DIR	= obj

# this is for mirroring the out dir
OBJ_DIRS= $(subst $(SRC_DIR), $(OBJ_DIR), $(shell find $(SRC_DIR) -type d))

SRC		= $(shell find $(SRC_DIR) -name '*.c')
OBJ		= $(subst $(SRC_DIR), $(OBJ_DIR), $(SRC:.c=.o))

# ** checker src ** #
CHECKER_NAME	= checker
CHECKER_SRC_DIR	= src_checker
CHECKER_OBJ_DIR	= obj_checker

# this is for mirroring the out dir
CHECKER_OBJ_DIRS= $(subst $(CHECKER_SRC_DIR), $(CHECKER_OBJ_DIR), $(shell find $(CHECKER_SRC_DIR) -type d))

CHECKER_SRC		= $(shell find $(CHECKER_SRC_DIR) -name '*.c')
CHECKER_OBJ		= $(subst $(CHECKER_SRC_DIR), $(CHECKER_OBJ_DIR), $(CHECKER_SRC:.c=.o))

AR		= ar -rcs
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra
RM		= rm -f
INC		= $(addprefix -I , $(shell find includes -type d))

LIBDIR	= libft
LIB		= -L$(LIBDIR) -lft
LIBNAME	= libft.a
# this is for debugging
DNAME	= debug.out
DDIR	= test
DFLAGS	= -fsanitize=address -fdiagnostics-color=always -g3
DSRC	= $(shell find $(DDIR) -name '*.c')
DOBJ	= $(DSRC:.c=.o)


# ** COLORS ** #
BLACK		= \x1B[30m
RED			= \x1B[31m
GREEN		= \x1B[32m
YELLOW		= \x1B[33m
BLUE		= \x1B[34m
MAGENTA		= \x1B[35m
CYAN		= \x1B[36m
WHITE		= \x1B[37m
B_BLACK		= \x1B[40m
B_RED		= \x1B[41m
B_GREEN		= \x1B[42m
B_YELLOW	= \x1B[43m
B_BLUE		= \x1B[44m
B_MAGENTA	= \x1B[45m
B_CYAN		= \x1B[46m
B_WHITE		= \x1B[47m
BRIGHT		= \x1B[1m
NORMAL		= \x1B[0m
BLINK		= \x1B[4m
REVERSE		= \x1B[5m
UNDERLINE	= \x1B[3m

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c
				@mkdir -p $(OBJ_DIRS)
				@printf "$(YELLOW)$(BRIGHT)Generating %25s\t$(NORMAL)%.40s\r" "$(NAME) src objects..." $@
				@$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(DDIR)/%.o:	$(DDIR)/%.c
				@mkdir -p $(DDIR)
				@printf "$(YELLOW)$(BRIGHT)Generating %25s\t$(NORMAL)%.40s\r" "$(NAME) debug objects..." $@
				@$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(NAME)::	$(LIBDIR)/$(LIBNAME) $(OBJ) 
			@printf "\n$(MAGENTA)$(BRIGHT)Compiling $(NAME)...          \n"
			@$(CC) $(CFLAGS) $(OBJ) $(INC) -o $(NAME) $(LIB)
			@printf "$(GREEN)COMPLETE!!\n\n"

$(CHECKER_OBJ_DIR)/%.o:	$(CHECKER_SRC_DIR)/%.c
				@mkdir -p $(CHECKER_OBJ_DIRS)
				@printf "$(YELLOW)$(BRIGHT)Generating %25s\t$(NORMAL)%.40s\r" "$(CHECKER_NAME) src objects..." $@
				@$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(CHECKER_NAME)::	$(LIBDIR)/$(LIBNAME) $(CHECKER_OBJ) 
			@printf "\n$(MAGENTA)$(BRIGHT)Compiling $(CHECKER_NAME)...          \n"
			@$(CC) $(CFLAGS) $(CHECKER_OBJ) $(INC) -o $(CHECKER_NAME) $(LIB)
			@printf "$(GREEN)COMPLETE!!\n\n"

$(DNAME):	$(SRC) $(DSRC) $(LIBDIR)/$(LIBNAME)
			@printf "\n$(MAGENTA)$(BRIGHT)Compiling $(DNAME) for $(NAME)...          \n"
			@$(CC) $(CFLAGS) $(DFLAGS) $(INC) $(SRC) $(DSRC) -o $(DNAME) $(LIB)
			@printf "$(GREEN)COMPLETE!!\n\n"

$(LIBDIR)/$(LIBNAME):
		@make -C $(LIBDIR) --no-print-directory

debug:	$(DNAME)

all:	$(NAME)

bonus:	$(NAME) $(CHECKER_NAME)

clean:
		@printf "$(RED)$(BRIGHT)Removing $(NAME) objects...\n$(NORMAL)"
		@make clean -C $(LIBDIR) --no-print-directory
		@$(RM) -rf $(OBJ_DIR) $(CHECKER_OBJ_DIR)

fclean:	clean
		@printf "$(RED)$(BRIGHT)Deleting $(NAME) and $(DNAME) and $(CHECKER_NAME)...\n\n$(NORMAL)"
		@make fclean -C $(LIBDIR) --no-print-directory
		@$(RM) $(NAME) $(CHECKER_NAME) $(DNAME)

re:			fclean all

.PHONY: all clean fclean re debug bonus norm

norm:
		@norminette $(SRC_DIR) includes/