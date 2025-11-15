# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aoneil <aoneil@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/14 15:56:09 by aoneil            #+#    #+#              #
#    Updated: 2025/11/15 15:19:02 by aoneil           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -g
RM			= rm -rf

# Directories
SRCDIR		= src
OBJDIR		= obj
INCDIR		= include
LIBFTDIR	= libft

# Source files (explicit list, no wildcards)
SRCS		= \
	$(SRCDIR)/alg_rotate_both_push.c \
	$(SRCDIR)/alg_sort_big.c\
	$(SRCDIR)/alg_sort_small.c \
	$(SRCDIR)/costs.c\
	$(SRCDIR)/helpers.c \
	$(SRCDIR)/helpers_find_value.c \
	$(SRCDIR)/indexing.c\
	$(SRCDIR)/main.c \
	$(SRCDIR)/operations_push.c \
	$(SRCDIR)/operations_rotate.c \
	$(SRCDIR)/operations_rrotate.c \
	$(SRCDIR)/operations_swap.c \
	$(SRCDIR)/parse_val.c\
	$(SRCDIR)/targets.c \
	$(LIBFTDIR)/ft_atol.c\
	$(LIBFTDIR)/ft_putstr_fd.c\
	$(LIBFTDIR)/ft_split_atom.c\

# Object files
OBJS		= $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SRCS))

# Colors
GREEN		= \033[0;32m
RED			= \033[0;31m
RESET		= \033[0m

# Default rule
all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(CFLAGS) -I$(INCDIR) -I$(LIBFTDIR) $(OBJS) -o $(NAME)
	@echo "$(GREEN)✓ $(NAME) built$(RESET)"

# Compile object files
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -I$(INCDIR) -I$(LIBFTDIR) -c $< -o $@
	@echo "$(GREEN)Compiled:$(RESET) $<"

clean:
	@$(RM) $(OBJDIR)
	@echo "$(RED)✗ Object files removed$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)✗ Executable removed$(RESET)"

re: fclean all

.PHONY: all clean fclean re