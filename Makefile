# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: filippo <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/11 19:41:53 by filippo           #+#    #+#              #
#    Updated: 2023/12/18 23:12:38 by filippo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	$(BUILD_DIR)/minishell
ARGS			=	

VALGRIND-TOOL	=	memcheck
VALGRIND-OPTIONS=	

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
					$(SRCS_DIR)/utils.c \
					$(SRCS_DIR)/string.c \
				#	$(SRCS_DIR)/parse.c \
					$(SRCS_DIR)/pipe.c \
					$(SRCS_DIR)/signal.c \
					$(SRCS_DIR)/simulation.c \
					$(SRCS_DIR)/valid.c

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
	echo "target remote | vgdb\nc" > .gdbinit
	gdb --args $(NAME) $(ARGS)

debug: clear all
	gdb --args $(NAME) $(ARGS)

debugf: clear all
	vi .gdbinit && gdb --args $(NAME) $(ARGS)

arg_norme	?=	
norme:
	while [ 1 ] ; do sleep 2 ; clear ; norminette $(SRCS_DIR)/$(notdir $(arg_norme)) ; done

compile:
	while [ 1 ] ; do sleep 2 ; clear ; make ; done
