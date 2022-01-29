# Compiler options
CC=gcc
FLAGS=-Wall -Wextra # ! TODO -Werror
COMPILE=@$(CC) $(FLAGS)
EXE_NAME=gnl.out

BUFFER_S=42

# Binaries variables
SRCS =	get_next_line.c \
		get_next_line_utils.c
BINS = ${SRCS:%.c=bin/%.o}

EXE_MAIN_SRC = test_main/get_next_line_main.c

EXE_MAIN = ${EXE_MAIN_SRC:%.c=bin/%.o}

MANDATORY = $(BINS)

all: $(EXE_NAME)

$(EXE_NAME): $(MANDATORY) $(EXE_MAIN)
	$(info Compiling mandatory into $(EXE_NAME))
	@$(CC) $(FLAGS) -o $(EXE_NAME) $(EXE_MAIN) $^

test: $(EXE_NAME)
	$(info Testing $(EXE_NAME))
	./$(EXE_NAME)

test_main/%.c: $(MANDATORY)
	$(info Compiling tester)
	@$(CC) $(FLAGS) -o $(EXE_NAME) $^ $@

bin/%.o: %.c
	@echo "- Compiling $< -> $@"
	@mkdir -p bin
	@$(COMPILE) -c $< -o $@ -D BUFFER_SIZE=$(BUFFER_S)

# Clean logic
.PHONY: re fclean
re: fclean all

fclean:
	$(info Removing $(EXE_NAME) and executables)
	@rm -f $(EXE_NAME) *.out
	$(info Removing binary directory)
	@rm -rf ./bin
	$(info Project now clean.)

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(wildcard *.c)
	gcc -nostartfiles -shared -o libft.so $(MANDATORY) $(BONUS_OBJ)
