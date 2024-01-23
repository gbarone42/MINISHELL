# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcorri <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/08 16:34:06 by fcorri            #+#    #+#              #
#    Updated: 2023/04/01 17:56:36 by fcorri           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	$(BUILD_DIR)/libftprintf.a

CFLAGS			=	-Wall -Wextra -Werror

BUILD_DIR		=	../../build
INC_DIR			=	$(BUILD_DIR)/inc
OBJS_DIR		=	$(BUILD_DIR)/obj/printf
LIBFT_OBJS_DIR	=	$(BUILD_DIR)/obj/lib

SRCS_DIR		=	./src
PRNTRS_DIR		= 	$(SRCS_DIR)/printers
LIBFT_DIR		=	../lib

SRCS			=	$(SRCS_DIR)/ft_printf.c \
					$(SRCS_DIR)/specification.c \
					$(SRCS_DIR)/utils.c \
					$(PRNTRS_DIR)/printer.c \
					$(PRNTRS_DIR)/default_printer.c \
					$(PRNTRS_DIR)/default_num_printer.c \
					$(PRNTRS_DIR)/char_printer.c \
					$(PRNTRS_DIR)/string_printer.c \
					$(PRNTRS_DIR)/pointer_printer.c \
					$(PRNTRS_DIR)/decimal_integer_printer.c \
					$(PRNTRS_DIR)/unsigned_printer.c \
					$(PRNTRS_DIR)/hex_printer.c \
					$(PRNTRS_DIR)/min_hex_printer.c \
					$(PRNTRS_DIR)/max_hex_printer.c \
					$(PRNTRS_DIR)/percentage_printer.c \

LIBFT_SRCS		=	$(LIBFT_DIR)/utils/ft_malloc_soul.c \
					$(LIBFT_DIR)/utils/ft_memutils1.c \
					$(LIBFT_DIR)/utils/ft_memutils2.c \
					$(LIBFT_DIR)/ft_atoi.c \
					$(LIBFT_DIR)/ft_memcpy.c \
					$(LIBFT_DIR)/ft_strdup.c \
					$(LIBFT_DIR)/ft_strlen.c \
					$(LIBFT_DIR)/ft_isdigit.c \
					$(LIBFT_DIR)/ft_strndup.c \
					$(LIBFT_DIR)/ft_memchr.c \


OBJS			=	$(SRCS:$(SRCS_DIR)%.c=$(OBJS_DIR)%.o)
LIBFT_OBJS		=	$(LIBFT_SRCS:$(LIBFT_DIR)%.c=$(LIBFT_OBJS_DIR)%.o)

AR				=	ar crs
RM				=	rm -fr

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_OBJS)
	$(AR) $(NAME) $(OBJS) $(LIBFT_OBJS)

$(OBJS_DIR)/%.o: $(addprefix $(SRCS_DIR)/, $(notdir %.c))
	@mkdir -p $(@D)
	cc -I $(INC_DIR) -I $(SRCS_DIR) -c $< -o $@

$(LIBFT_OBJS_DIR)/%.o: $(addprefix $(LIBFT_DIR)/, $(notdir %.c))
	cc -I $(INC_DIR)/libft -c $< -o $@

bonus: all

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
