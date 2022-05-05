# Colors:
NC			=	\033[0m
LRED		=	\033[0;31m
GREEN		=	\033[0;32m
LRED		=	\033[1;31m
LGREEN		=	\033[1;32m
YELLOW		=	\033[1;33m
LBLUE		=	\033[1;34m
TITLE		=	\033[38;5;33m

# Compiler options
CC				=	gcc
CC_LIB			=	ar
FLAGS			=	-Wall -Wextra -Werror
FLAGS_LIB		=	-rc
INCLUDE			=	-I ./include

COMPILE			=	@$(CC) $(FLAGS) $(INCLUDE)
COMPILE_LIB		=	@$(CC_LIB) $(FLAGS_LIB)
LIB				=	gnl.a

#BUFFER_S		=	42
BUFFER_S		=	2048

# Binaries variables
SRCS_MANDATORY	=	get_next_line.c \
					get_next_line_utils.c

SRCS_BONUS		=	$(SRCS_MANDATORY:%.c=%_bonus.c)

MANDATORY		=	${SRCS_MANDATORY:%.c=bin/%.o}
BONUS			=	${SRCS_BONUS:%.c=bin/%.o}


# Triggers
all: $(LIB)


TYPE			=	"mandatory"
$(LIB): $(MANDATORY)
	@echo "\n$(TITLE)Compiling $(YELLOW)$(TYPE) $(NC)into $(YELLOW)$(LIB)$(NC)\c"
	@$(COMPILE_LIB) $(LIB) $^
	@echo "$(GREEN) [OK]$(NC)\n"

bonus: $(BONUS)
	@make MANDATORY="$(BONUS)" TYPE="bonus"

bin/%.o: src/%.c
	@echo "- ${TITLE}Compiling${NC} $< -> $@\c"
	@mkdir -p $(dir $@)
	@$(COMPILE) -c $< -o $@ -D BUFFER_SIZE=$(BUFFER_S)
	@echo "${GREEN} [OK]${NC}"

# Clean logic
.PHONY: re fclean

re: fclean all

clean:
	@echo "${LRED}Cleaning ${NC}binaries\c"
	@rm -rf ./bin
	@echo "${LGREEN} [OK]${NC}"

fclean: clean
	@echo "${LRED}Cleaning ${NC}binaries\c"	
	@rm -f $(LIB)
	@echo "${LGREEN} [OK]${NC}"
