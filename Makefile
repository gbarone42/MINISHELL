# Define the target executable name
NAME = build/minishell

# Directories
SRC_DIR = src
OBJ_DIR = build
EXEC_DIR = executor
PARSER_DIR = parser
INCLUDE_DIR = include  # Change this to the appropriate folder for header files


# Source files
SRCS =	${SRC_DIR}/minishell.c	\
		${SRC_DIR}/utils1.c	\
		${SRC_DIR}/utils2.c	\
		${SRC_DIR}/utils3.c	\
		${SRC_DIR}/test.c	\
		${SRC_DIR}/simulation.c	\
		${SRC_DIR}/init.c	\
		${SRC_DIR}/signal.c	\
		${SRC_DIR}/valid.c	\
		${SRC_DIR}/builtins/exit.c	\
		${SRC_DIR}/builtins/historyh.c	\
		${SRC_DIR}/builtins/pwds.c	\
		${SRC_DIR}/builtins/echos.c	\
		${SRC_DIR}/builtins/cdd.c	\
		${SRC_DIR}/builtins/cdd2.c	\
		${SRC_DIR}/builtins/handlebuiltins.c	\
		${SRC_DIR}/builtins/envv.c	\
		${SRC_DIR}/builtins/export_unset.c	\
		${SRC_DIR}/${EXEC_DIR}/clist_utils.c \
		${SRC_DIR}/${EXEC_DIR}/exec_starter.c \
		${SRC_DIR}/${EXEC_DIR}/execution.c \
		${SRC_DIR}/${EXEC_DIR}/free.c \
		${SRC_DIR}/${EXEC_DIR}/priority.c \
		${SRC_DIR}/${EXEC_DIR}/redir_handler.c \
		${SRC_DIR}/${EXEC_DIR}/redir.c \
		${SRC_DIR}/${EXEC_DIR}/tools_file.c \
		${SRC_DIR}/${PARSER_DIR}/clist.c \
		${SRC_DIR}/${PARSER_DIR}/env.c \
		${SRC_DIR}/${PARSER_DIR}/free.c \
		${SRC_DIR}/${PARSER_DIR}/ilist.c \
		${SRC_DIR}/${PARSER_DIR}/init.c \
		${SRC_DIR}/${PARSER_DIR}/lexer.c \
		${SRC_DIR}/${PARSER_DIR}/minishell_p.h \
		${SRC_DIR}/${PARSER_DIR}/parser.c \
		${SRC_DIR}/${PARSER_DIR}/parser_io_lists.c \
		${SRC_DIR}/${PARSER_DIR}/parser_others.c \
		${SRC_DIR}/${PARSER_DIR}/rlist.c \
		${SRC_DIR}/${PARSER_DIR}/string.c \
		${SRC_DIR}/${PARSER_DIR}/tlist.c \
		${SRC_DIR}/${PARSER_DIR}/utils.c

		# Add other source files as necessary

# Header files
HDRS = ${wildcard ${INCLUDE_DIR}/*.h}

# Object files
OBJS = ${patsubst ${SRC_DIR}/%.c,${OBJ_DIR}/%.o,${SRCS}}

# Compiler and flags
CC = cc
RM = rm -rf
FLAGS = -g -Wall -Wextra -Werror -I${INCLUDE_DIR}
MAKEFLAGS += --silent
LIBFLAGS = -lreadline

# Color codes for output messages
CLR_RMV = \033[0m
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
BLUE = \033[1;34m
CYAN = \033[1;36m
GOLD = \033[1;33m

# Rule to compile individual source files
${OBJ_DIR}/%.o: ${SRC_DIR}/%.c ${HDRS}
	@mkdir -p ${@D}
	${CC} ${FLAGS} -c $< -o $@

# Build the executable
${NAME}: ${OBJS}
	@echo "${GREEN}Compiling ${CLR_RMV} ${GOLD}${NAME} ${CLR_RMV}..."
	make -C libft
	${CC} ${FLAGS} ${OBJS} ${LIBFLAGS} -o ${NAME} libft/build/libft.a
	@echo "${GOLD}${NAME} created[0m "

# Build all
all: ${NAME}

# Clean object files
clean:
	make -C libft clean
	@echo "${RED}Deleting ${LAVENDER}${NAME}'s ${CLR_RMV}objs"
	@find ${OBJ_DIR} -name "*.o" -type f -delete

# Clean all files
fclean: clean
	make -C libft fclean
	@echo "${RED}Deleting ${CYAN}${NAME}'s ${CLR_RMV}objs and executable"
	@${RM} ${NAME}

# Clean and rebuild
re: fclean all

# Custom command 'makex'
x: fclean all


	@echo "${GREEN}Running ${CYAN}${NAME} ${CLR_RMV}..."
	-@./$(NAME)
#i've added '-' in front of @./$(NAME) because i wanted to silence this error "make: *** [Makefile:75: x] Error 130".
#i've havent solved the problem at the root, i just silenced this problem that only happens if im compiling with "make x"

clear:
		clear

mem:clear all
	valgrind --leak-check=full --show-leak-kinds=all --suppressions=EXTRA/readline.supp ./build/minishell

.PHONY: all clean fclean re x clear mem