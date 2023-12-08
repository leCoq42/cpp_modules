NAME	:= a.out

## General ##
CC		:= g++
RM		:= rm -rf
CFLAGS	:= -Wall -Wextra -Werror -std=c++17 -g

## Directories ##
INC_DIR	:= include
SRC_DIR	:= src
OBJ_DIR	:= obj

## Files ##
SRC		:= main.cpp Harl.cpp
INCLUDE	:= -I $(INC_DIR)
OBJS	:= $(addprefix $(OBJ_DIR)/, $(SRC:%.cpp=%.o))

## Rules ##
all: $(NAME)

clean:
	@$(RM) $(OBJS)
	@$(RM) *.replace

fclean: clean
	@$(RM) $(OBJ_DIR)
	@$(RM) $(NAME)

re: fclean all

## Compilation ##
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDE) $(OBJS) -o $(NAME)

$(OBJS): $(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

## Phony ##
.PHONY: all clean fclean re
