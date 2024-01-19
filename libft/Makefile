# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdel-gra <sdel-gra@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/05 15:24:57 by sdel-gra          #+#    #+#              #
#    Updated: 2023/03/01 16:25:01 by sdel-gra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= libft.a

SRCS			=	ft_bzero.c\
ft_isalnum.c\
ft_isalpha.c\
ft_isascii.c\
ft_isdigit.c\
ft_islower.c\
ft_isprint.c\
ft_isupper.c\
ft_iswhitespace.c\
ft_memcpy.c\
ft_memset.c\
ft_memcmp.c\
ft_memmove.c\
ft_memchr.c\
ft_strrchr.c\
ft_strchr.c\
ft_strchri.c\
ft_strlen.c\
ft_calloc.c\
ft_strdup.c\
ft_strlcat.c\
ft_strlcpy.c\
ft_atoi.c\
ft_atoibase.c\
ft_strmapi.c\
ft_substr.c\
ft_strjoin.c\
ft_strtrim.c\
ft_strncmp.c\
ft_strnstr.c\
ft_split.c\
ft_itoa.c\
ft_striteri.c\
ft_putchar_fd.c\
ft_putstr_fd.c\
ft_putendl_fd.c\
ft_putnbr_fd.c\
ft_tolower.c\
ft_toupper.c\
get_next_line_utils.c\
get_next_line.c\

OBJS			= $(SRCS:.c=.o)

BONUS_OBJS		= $(BONUS:.c=.o)

CC			= gcc
RM			= rm -f
CFLAGS			= -Wall -Wextra -Werror -I. -c

all:			$(NAME)

$(NAME):		$(OBJS)
			ar -rc $(NAME) $(OBJS)

clean:			
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

bonus:			$(OBJS) $(BONUS_OBJS)
				ar -rc $(NAME) $(OBJS) $(BONUS_OBJS)

.PHONY: all clean fclean re
