# Color codes for output messages
CLR_RMV = \033[0m
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
BLUE = \033[1;34m
CYAN = \033[1;36m
GOLD = \033[1;33m

# Define the target executable name
NAME			=	$(BUILD_DIR)/minishell

# Directories
BUILD_DIR		=	build
INC_DIR			=	$(BUILD_DIR)/inc
OBJ_DIR			=	$(BUILD_DIR)/obj
LIBFT_DIR		=	libft
SRC_DIR			=	src
EXEC_DIR		=	$(SRC_DIR)/executor
PARSER_DIR		=	$(SRC_DIR)/parser
BUILTINS_DIR	=	$(SRC_DIR)/builtins

# Compiler and flags
CC				=	cc
CFLAGS			=	-g3
REQUIRED_FLAGS	=	$(CFLAGS) -Wall -Wextra -Werror
CPPFLAGS		=	$(addprefix -I, $(INC_DIR) $(LIBFT_DIR)/$(INC_DIR) /usr/local/include)
LDFLAGS			=	$(addprefix -L, $(LIBFT_DIR)/$(BUILD_DIR) /usr/local/lib)
LDLIBS			=	$(addprefix -l, ft readline)

RM				=	rm -rf

SRCS			=	$(SRC_DIR)/minishell.c \
					$(SRC_DIR)/utils1.c \
					$(SRC_DIR)/utils2.c \
					$(SRC_DIR)/utils3.c \
					$(SRC_DIR)/simulation.c \
					$(SRC_DIR)/init.c \
					$(SRC_DIR)/signal.c \
					$(SRC_DIR)/valid.c \
					$(BUILTINS_DIR)/exit.c \
					$(BUILTINS_DIR)/historyh.c \
					$(BUILTINS_DIR)/pwds.c \
					$(BUILTINS_DIR)/echos.c \
					$(BUILTINS_DIR)/cdd.c \
					$(BUILTINS_DIR)/cdd2.c \
					$(BUILTINS_DIR)/handlebuiltins.c \
					$(BUILTINS_DIR)/envv.c \
					$(BUILTINS_DIR)/export_unset.c \
					$(EXEC_DIR)/clist_utils.c \
					$(EXEC_DIR)/exec_starter.c \
					$(EXEC_DIR)/execution.c \
					$(EXEC_DIR)/free.c \
					$(EXEC_DIR)/priority.c \
					$(EXEC_DIR)/redir_handler.c \
					$(EXEC_DIR)/redir.c \
					$(EXEC_DIR)/tools_file.c \
					$(PARSER_DIR)/clist.c \
					$(PARSER_DIR)/env.c \
					$(PARSER_DIR)/free.c \
					$(PARSER_DIR)/ilist.c \
					$(PARSER_DIR)/init.c \
					$(PARSER_DIR)/lexer.c \
					$(PARSER_DIR)/parser.c \
					$(PARSER_DIR)/parser_io_lists.c \
					$(PARSER_DIR)/parser_others.c \
					$(PARSER_DIR)/rlist.c \
					$(PARSER_DIR)/string.c \
					$(PARSER_DIR)/tlist.c \
					$(PARSER_DIR)/utils.c

HEADERS			=	$(INC_DIR)/minishell.h \
					$(INC_DIR)/executor_p.h \
					$(INC_DIR)/lexer_p.h \
					$(INC_DIR)/builtins_p.h \
					$(INC_DIR)/parser_p.h

OBJS			=	$(SRCS:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

all: $(NAME)

$(NAME): $(LIBFT_DIR)/$(BUILD_DIR)/libft.a $(OBJS)
	$(CC) $(OBJS) $(REQUIRED_CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS) -o $(NAME)

$(LIBFT_DIR)/$(BUILD_DIR)/libft.a:
	make -C $(LIBFT_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	@mkdir -p $(@D)
	$(CC) -c $< $(REQUIRED_CFLAGS) $(CPPFLAGS) -o $@

clean:
	make -C libft clean
	$(RM) $(OBJS)

fclean: clean
	make -C libft fclean
	$(RM) $(NAME)

re: fclean all

clear:
	clear

run: clear all
	$(NAME)

VALGRIND-TOOL	=	memcheck
VALGRIND-OPTIONS=	--track-origins=yes --leak-check=full --show-leak-kinds=all --suppressions=resources/readline.supp

mem: clear all
	valgrind $(VALGRIND-OPTIONS) $(NAME)

vgdb: clear all
	valgrind --tool=$(VALGRIND-TOOL) $(VALGRIND-OPTIONS) --vgdb-error=0 $(NAME)

gdb: clear all
	echo "target remote | vgdb\nb main\nc" > .gdbinit
	gdb --args $(NAME)

debug: clear all
	gdb --args $(NAME)

debugf: clear all
	vi .gdbinit && gdb --args $(NAME)

TIME			=	2

arg_norme		?=	src
norme:
	while [ 1 ] ; do sleep $(TIME) ; clear ; norminette $(arg_norme) ; done

compile:
	while [ 1 ] ; do sleep $(TIME) ; clear ; make ; done

.PHONY: all clean fclean re x clear run mem vgdb gdb debug debugf norme compile
