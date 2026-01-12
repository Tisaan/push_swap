# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tseche <tseche@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/13 23:39:11 by tseche            #+#    #+#              #
#    Updated: 2026/01/11 20:30:15 by tseche           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# --- Colors ---
RED    := \033[0;31m
GREEN  := \033[0;32m
YELLOW := \033[0;33m
BLUE   := \033[0;34m
PURPLE := \033[0;35m
CYAN   := \033[0;36m
NC     := \033[0m # No Color

NAME = push_swap
CFLAGS = -Wall -Werror -Wextra -g 
CC	= cc
SRCS =  ./srcs/parsing/check.c \
		./srcs/parsing/parser.c \
		./srcs/utils/free_stack.c \
		./srcs/utils/ft_is_sorted.c \
		./srcs/utils/ft_stack_init_fill.c \
		./srcs/utils/mapping.c \
		./srcs/utils/print_stack.c \
		./srcs/utils/is_empty.c \
		./srcs/move/move.c \
		./srcs/tiny_sort.c \
		./srcs/push_swap.c \
		
INCLUDES = ./includes

LIBNAME = libft.a
LIBDIR = ./srcs/lib_ft
LIB = $(LIBDIR)/$(LIBNAME)
LIBMAKE =  $(MAKE) --no-print-directory -C $(LIBDIR)

OBJS = $(SRCS:%.c=%.o)

all:  libs $(NAME)

libs:
	@echo "$(BLUE)📦 Building library in $(LIBDIR)...$(NC)"
	@$(LIBMAKE)
	@echo "$(BLUE)📦 Lib_ft created $(NC)"

$(NAME): $(OBJS)
	@echo "$(BLUE)🔗 Creating Executable $@...$(NC)"
	@$(CC) $(CFLAGS) $(OBJS) -L$(LIBDIR) -l:$(LIBNAME) -o $(NAME) 
	@echo "$(GREEN)✅ Created $@$(NC)"
	
%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	
clean:
	@echo "$(RED)🧹 Cleaning...$(NC)"
	@rm -rf $(OBJS)

libclean:
	@echo "$(RED)🧹 Cleaning... lib-ft$(NC)"
	@make -C $(LIBDIR) fclean --no-print-directory

fclean: clean libclean
	@echo "$(RED)🗑️ Removing Executable $(NAME)...$(NC)"
	@rm -rf $(NAME)

re: fclean all

credit:
	@echo "SO a pchazalm"

help:
	@echo "$(PURPLE)=== Makefile Help ===$(NC)"
	@echo "$(PURPLE)all:$(NC) Build the library"
	@echo "$(PURPLE)clean:$(NC) Remove object files"
	@echo "$(PURPLE)fclean:$(NC) Remove object files and library"
	@echo "$(PURPLE)re:$(NC) Rebuild the library from scratch"
	@echo "$(PURPLE)help:$(NC) Show this help message"
	@echo "$(PURPLE)credit:$(NC) Show the people who help with this project"
	

.PHONY: all libs clean libclean fclean re credit help