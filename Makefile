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

$(LIB): $(MANDATORY)
	$(info Compiling mandatory into $(LIB))
	$(COMPILE_LIB) $(LIB) $^

bonus: $(BONUS)
	$(info Compiling bonus into $(LIB))
	make MANDATORY="$(BONUS)"

bin/%.o: src/%.c
	@echo "- Compiling $< -> $@"
	@mkdir -p $(dir $@)
	$(COMPILE) -c $< -o $@ -D BUFFER_SIZE=$(BUFFER_S)

# Clean logic
.PHONY: re fclean

re: fclean all

clean:
	$(info Removing binary directory)
	@rm -rf ./bin

fclean: clean
	$(info Removing $(LIB))
	@rm -f $(LIB)
	$(info Project now clean.)
