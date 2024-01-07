# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbarone <gbarone@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/11 19:41:53 by filippo           #+#    #+#              #
#    Updated: 2024/01/07 17:25:17 by gbarone          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	$(BUILD_DIR)/minishell
ARGS			=	

VALGRIND-TOOL	=	memcheck
VALGRIND-OPTIONS=	--track-origins=yes --leak-check=full --show-leak-kinds=all --suppressions=./resources/readline.supp

CFLAGS			=	-g
REQUIRED_CFLAGS	=	$(CFLAGS) -Wall -Wextra -Werror
CPPFLAGS		=	$(addprefix -I, $(LIBFT_DIR)/$(INC_DIR) /usr/local/include)
LDFLAGS			=	$(addprefix -L, $(LIBFT_DIR)/$(BUILD_DIR) /usr/local/lib)
LDLIBS			=	$(addprefix -l, ft readline)

BUILD_DIR		=	build
INC_DIR			=	$(BUILD_DIR)/inc
OBJS_DIR		=	$(BUILD_DIR)/obj
LIBFT_DIR		=	libft
SRCS_DIR		=	src
P_HEADER		=	$(SRCS_DIR)/minishell_p.h

SRCS			=	$(SRCS_DIR)/main.c \
					$(SRCS_DIR)/init.c \
					$(SRCS_DIR)/lexer.c \
					$(SRCS_DIR)/parser.c \
					$(SRCS_DIR)/tlist.c \
					$(SRCS_DIR)/evlist.c \
					$(SRCS_DIR)/ilist.c \
					$(SRCS_DIR)/utils.c \
					$(SRCS_DIR)/free.c \
					$(SRCS_DIR)/string.c \

OBJS			=	$(SRCS:$(SRCS_DIR)%.c=$(OBJS_DIR)%.o)

RM				=	rm -fr

all: $(NAME)

$(NAME): $(LIBFT_DIR)/$(BUILD_DIR)/libft.a $(OBJS)
	$(CC) $(OBJS) $(REQUIRED_CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS) -o $(NAME)

$(LIBFT_DIR)/$(BUILD_DIR)/libft.a:
	make -C $(LIBFT_DIR)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(P_HEADER)
	@mkdir -p $(@D)
	$(CC) -c $< $(REQUIRED_CFLAGS) $(CPPFLAGS) -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

clear:
	clear

run: clear all
	$(NAME) $(ARGS)

mem: clear all
	valgrind --tool=$(VALGRIND-TOOL) $(VALGRIND-OPTIONS) $(NAME) $(ARGS)

vgdb: clear all
	valgrind --tool=$(VALGRIND-TOOL) $(VALGRIND-OPTIONS) --vgdb-error=0 $(NAME) $(ARGS)

gdb: clear all
	echo "target remote | vgdb\nb main\nc" > .gdbinit
	gdb --args $(NAME) $(ARGS)

debug: clear all
	gdb --args $(NAME) $(ARGS)

debugf: clear all
	vi .gdbinit && gdb --args $(NAME) $(ARGS)

arg_norme	?=	
norme:
	while [ 1 ] ; do sleep 1 ; clear ; norminette $(SRCS_DIR)/$(notdir $(arg_norme)) ; done

compile:
	while [ 1 ] ; do sleep 1 ; clear ; make ; done

test: clear all
	@tests/run_token_tests.sh

.PHONY: all clean fclean re clear run mem vgdb gdb debug debugf test
