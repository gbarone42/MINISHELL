# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/21 19:02:33 by fcorri            #+#    #+#              #
#    Updated: 2023/10/10 16:20:43 by fcorri           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	$(BUILD_DIR)/test
ARGS			=	


CFLAGS			=	-g
REQUIRED_CFLAGS	=	$(CFLAGS) -Wall -Wextra -Werror
CPPFLAGS		=	$(addprefix -I, $(LIBFT_DIR)/$(INC_DIR))
LDFLAGS			=	$(addprefix -L, $(LIBFT_DIR)/$(BUILD_DIR))
LDLIBS			=	$(addprefix -l, ft)

BUILD_DIR		=	build
INC_DIR			=	$(BUILD_DIR)/inc
OBJS_DIR		=	$(BUILD_DIR)/obj
LIBFT_DIR		=	..
SRCS_DIR		=	src
P_HEADER		=	$(SRCS_DIR)/

SRCS			=	$(SRCS_DIR)/main.c \
					$(LIBFT_DIR)/src/printf/src/ft_printf.c

OBJS			=	$(SRCS:$(SRCS_DIR)%.c=$(OBJS_DIR)%.o)

RM				=	rm -fr

all: $(NAME)

$(NAME): $(LIBFT_DIR)/$(BUILD_DIR)/libft.a $(OBJS)
	$(CC) $(OBJS) $(TEST) $(REQUIRED_CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS) -o $(NAME)

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

run: all
	clear ; $(NAME) $(ARGS)

mem: all
	clear ; valgrind --track-origins=yes $(NAME) $(ARGS)

vgdb: all
	valgrind --track-origins=yes --vgdb-error=0 $(NAME) $(ARGS)

debug: all
	clear ; gdb --args $(NAME) $(ARGS)

debugf: all
	clear ; vi .gdbinit && gdb --args $(NAME) $(ARGS)
