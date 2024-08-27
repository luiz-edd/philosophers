NAME				=	philo
CC					=	cc
CFLAGS				=	-Wextra -Wall -Werror -Wunreachable-code -g3 -pthread #-fsanitize=thread 
HEADERS				=	-I .
FILES				= 	main.c \
						validate_args.c \
						utils.c \
						init_data.c
						
OBJS				= 	$(FILES:%.c=$(OBJ_DIR)/%.o)
OBJ_DIR				= 	obj

all: $(NAME) 

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(HEADERS) -o $(NAME)

$(OBJ_DIR)/%.o : %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@ && printf "Compiling: $(notdir $<\n)"

clean:
	@rm -rf $(OBJ_DIR)
	@echo "Deleted object files"

fclean: clean
	@rm -rf $(NAME)
	@echo "Deleted executable files and static libraries"

re: fclean all

norm:
	@norminette -R CheckForbiddenSourceHeader

val: all
	valgrind \
		--leak-check=full \
		--show-leak-kinds=all \
		--track-origins=yes \
		--trace-children=yes \
		./$(NAME) 5 10000 200 200 5
#       --log-file=valgrind-out.txt \

hel: all
	valgrind \
		--tool=helgrind \
		--history-level=none \
		-s \
		./$(NAME) 5 10000 200 200 5
#       --log-file=helgrind-out.txt \

drd: all
	valgrind \
		--tool=drd \
		-s \
		./$(NAME) 5 1800 200 200 5
#       --log-file=drd-out.txt \

.PHONY: all, clean, fclean, re, norm, val, hel, drd