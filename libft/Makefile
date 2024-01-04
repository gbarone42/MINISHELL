# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcorri <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/31 15:29:43 by fcorri            #+#    #+#              #
#    Updated: 2024/01/04 23:45:01 by filippo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	$(BUILD_DIR)/libft.a

CFLAGS			=	-g
REQUIRED_FLAGS	=	$(CFLAGS) -Wall -Wextra -Werror
CPPFLAGS		=	-I$(INC_DIR)/libft -I$(INC_DIR)

BUILD_DIR		=	build
INC_DIR			=	$(BUILD_DIR)/inc
OBJS_DIR		=	$(BUILD_DIR)/obj

SRCS_DIR		=	src
LIB_DIR			=	$(SRCS_DIR)/lib
BONUS_DIR		=	$(LIB_DIR)/bonus
UTILS_DIR		=	$(LIB_DIR)/utils
GNL_DIR			=	$(SRCS_DIR)/gnl

SRCS			=	$(LIB_DIR)/ft_atoi.c \
					$(LIB_DIR)/ft_atol.c \
					$(LIB_DIR)/ft_abs.c \
					$(LIB_DIR)/ft_bzero.c \
					$(LIB_DIR)/ft_calloc.c \
					$(LIB_DIR)/ft_error.c \
					$(LIB_DIR)/ft_isalnum.c \
					$(LIB_DIR)/ft_isalpha.c \
					$(LIB_DIR)/ft_isascii.c \
					$(LIB_DIR)/ft_isdigit.c \
					$(LIB_DIR)/ft_isprint.c \
					$(LIB_DIR)/ft_itoa.c \
					$(LIB_DIR)/ft_memchr.c \
					$(LIB_DIR)/ft_memcmp.c \
					$(LIB_DIR)/ft_memcpy.c \
					$(LIB_DIR)/ft_memmove.c \
					$(LIB_DIR)/ft_memset.c \
					$(LIB_DIR)/ft_putchar_fd.c \
					$(LIB_DIR)/ft_putendl_fd.c \
					$(LIB_DIR)/ft_putnbr_fd.c \
					$(LIB_DIR)/ft_putstr_fd.c \
					$(LIB_DIR)/ft_split.c \
					$(LIB_DIR)/ft_strchr.c \
					$(LIB_DIR)/ft_strdup.c \
					$(LIB_DIR)/ft_striteri.c \
					$(LIB_DIR)/ft_strjoin.c \
					$(LIB_DIR)/ft_strlcat.c \
					$(LIB_DIR)/ft_strlcpy.c \
					$(LIB_DIR)/ft_strlen.c \
					$(LIB_DIR)/ft_strmapi.c \
					$(LIB_DIR)/ft_strncmp.c \
					$(LIB_DIR)/ft_strndup.c \
					$(LIB_DIR)/ft_strnstr.c \
					$(LIB_DIR)/ft_strrchr.c \
					$(LIB_DIR)/ft_strtrim.c \
					$(LIB_DIR)/ft_substr.c \
					$(LIB_DIR)/ft_tolower.c \
					$(LIB_DIR)/ft_toupper.c \
					$(UTILS_DIR)/ft_malloc_soul.c \
					$(UTILS_DIR)/ft_memutils1.c \
					$(UTILS_DIR)/ft_memutils2.c \
					\
					$(LIB_DIR)/dlist/ft_int_dlist1.c \
					$(LIB_DIR)/dlist/ft_int_dlist2.c \
					\
					$(GNL_DIR)/get_next_line.c \
					$(GNL_DIR)/get_next_line_utils.c

BONUS_SRCS		=	$(BONUS_DIR)/ft_lstadd_back.c \
					$(BONUS_DIR)/ft_lstadd_front.c \
					$(BONUS_DIR)/ft_lstclear.c \
					$(BONUS_DIR)/ft_lstdelone.c \
					$(BONUS_DIR)/ft_lstiter.c \
					$(BONUS_DIR)/ft_lstlast.c \
					$(BONUS_DIR)/ft_lstmap.c \
					$(BONUS_DIR)/ft_lstnew.c \
					$(BONUS_DIR)/ft_lstsize.c \

LIBS			=	$(BUILD_DIR)/libftprintf.a

LIBS_DIR		=	$(SRCS_DIR)/printf

OBJS			=	$(SRCS:$(SRCS_DIR)%.c=$(OBJS_DIR)%.o) \
					$(BONUS_SRCS:$(SRCS_DIR)%.c=$(OBJS_DIR)%.o) \

AR				=	ar -crs
RM				=	rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(foreach LIB_DIR, $(LIBS_DIR), $(MAKE) -C $(LIB_DIR);)
	$(foreach LIB, $(LIBS), ar -x $(LIB))
	$(AR) $(NAME) $(OBJS) ./*.o
	$(RM) ./*.o

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) -c $< $(REQUIRED_FLAGS) $(CPPFLAGS) -o $@

clean:
	$(foreach LIB_DIR, $(LIBS_DIR), $(MAKE) clean -C $(LIB_DIR);)
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
