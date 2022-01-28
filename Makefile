# Compiler options
CC=gcc
FLAGS=-Wall -Wextra -Werror
COMPILE=@$(CC) $(FLAGS)
EXE_NAME=gnl.out

BUFFER_S=42

# Binaries variables
SRCS =	get_next_line.c \
		get_next_line_utils.c \
		get_next_line_main.c

BINS = ${SRCS:%.c=bin/%.o}

MANDATORY = $(BINS)

all: $(EXE_NAME)

$(EXE_NAME): $(MANDATORY)
	$(info Compiling mandatory into $(EXE_NAME))
	@$(CC) $(FLAGS) -o $(EXE_NAME) $^

bin/%.o: %.c
	@echo "- Compiling $< -> $@"
	@mkdir -p bin
	@$(COMPILE) -c $< -o $@ -D BUFFER_SIZE=$(BUFFER_S)

# Clean logic
.PHONY: re fclean
re: fclean all

fclean:
	$(info Removing $(EXE_NAME))
	@rm -f $(EXE_NAME)
	$(info Removing binary directory)
	@rm -rf ./bin
	$(info Project now clean.)

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(wildcard *.c)
	gcc -nostartfiles -shared -o libft.so $(MANDATORY) $(BONUS_OBJ)
