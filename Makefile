# Define the target executable name
NAME = minishell

# Directories
SRC_DIR = src
OBJ_DIR = build
INCLUDE_DIR = build

# Source files
SRCS =	${SRC_DIR}/main/minishell.c	\
		${SRC_DIR}/utils/utils1.c	\
		${SRC_DIR}/utils/utils2.c	\
		${SRC_DIR}/utils/utils3.c	\
		${SRC_DIR}/test/test.c	\
		${SRC_DIR}/simulation/simulation.c	\
		${SRC_DIR}/init/init.c	\
		${SRC_DIR}/signal/signal.c	\
		${SRC_DIR}/valid/valid.c	\
		${SRC_DIR}/exit/exit.c	\
		${SRC_DIR}/parser/parsing.c	\
       # Add other source files as necessary

# Object files
OBJS = ${patsubst ${SRC_DIR}/%.c,${OBJ_DIR}/%.o,${SRCS}}

# Compiler and flags
CC = gcc
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
${OBJ_DIR}/%.o: ${SRC_DIR}/%.c
	@mkdir -p ${@D}
	${CC} ${FLAGS} -c $< -o $@

# Build the executable
${NAME}: ${OBJS}
	@echo "${GREEN}Compiling ${CLR_RMV} ${GOLD}${NAME} ${CLR_RMV}..."
	${CC} ${FLAGS} ${OBJS} ${LIBFLAGS} -o ${NAME}
	@echo "${GOLD}${NAME} created[0m "

# Build all
all: ${NAME}

# Create the object directory if it doesn't exist
objs:
	@mkdir -p ${OBJ_DIR}

# Clean object files
clean:
	@echo "${RED}Deleting ${LAVENDER}${NAME}'s ${CLR_RMV}objs"
	@${RM} ${OBJ_DIR}

# Clean all files
fclean: clean
	@echo "${RED}Deleting ${CYAN}${NAME}'s ${CLR_RMV}objs and executable"
	@${RM} ${NAME}

# Clean and rebuild
re: fclean all

# Custom command 'makex'
x: fclean all
	@echo "${GREEN}Running ${CYAN}${NAME} ${CLR_RMV}..."
	@./$(NAME)

clear:
		clear

mem: clear all
	valgrind --leak-check=full --suppressions=readline.supp ./minishell


.PHONY: all objs clean fclean re x clear mem