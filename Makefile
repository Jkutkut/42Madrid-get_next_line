# Compiler options
CC				=	gcc
FLAGS			=	-Wall -Wextra # ! TODO -Werror
COMPILE			=	@$(CC) $(FLAGS)
MANDATORY_EXE	=	gnl.out
BONUS_EXE		=	gnl_bonus.out

BUFFER_S		=	42

# Binaries variables
SRCS_MANDATORY	=	get_next_line.c \
					get_next_line_utils.c
SRCS_BONUS		=	get_next_line_bonus.c \
					get_next_line_utils_bonus.c

BINS_MANDATORY	=	${SRCS_MANDATORY:%.c=bin/%.o}
BINS_BONUS		=	${SRCS_BONUS:%.c=bin/%.o}

MAN_MAIN_SRC	=	test_main/get_next_line_main.c
MAN_MAIN_BIN	=	${MAN_MAIN_SRC:%.c=bin/%.o}

BONUS_MAIN_SRC	=	""
BONUS_MAIN_BIN	=	${BONUS_MAIN_SRC:%.c=bin/%.o}

MANDATORY		=	$(BINS_MANDATORY) $(MAN_MAIN_BIN)
BONUS			=	$(BINS_BONUS) $(BONUS_MAIN_BIN)

# Triggers
all: $(MANDATORY_EXE)
bonus: $(BONUS_EXE)

$(MANDATORY_EXE): $(MANDATORY)
	$(info Compiling mandatory into $(MANDATORY_EXE))
	$(CC) $(FLAGS) -o $(MANDATORY_EXE) $^

$(BONUS_EXE): $(BONUS)
	$(info Compiling bonus into $(BONUS_EXE))
	$(CC) $(FLAGS) -o $(BONUS_EXE) $^

bin/%.o: %.c
	@echo "- Compiling $< -> $@"
	@mkdir -p bin
	$(COMPILE) -c $< -o $@ -D BUFFER_SIZE=$(BUFFER_S)

# Test
test_main/%.c: $(MANDATORY)
	$(info Compiling tester)
	$(CC) $(FLAGS) -o $(MANDATORY_EXE) $^ $@

test: $(MANDATORY_EXE)
	$(info Testing $(MANDATORY_EXE))
	./$(MANDATORY_EXE)

# Clean logic
.PHONY: re fclean

re: fclean all

fclean:
	$(info Removing $(MANDATORY_EXE), $(BONUS_EXE))
	@rm -f $(MANDATORY_EXE) $(BONUS_EXE)
	$(info Removing binary directory)
	@rm -rf ./bin
	$(info Project now clean.)
