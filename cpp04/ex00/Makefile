NAME	:= polymorphism

## General ##
CC		:= g++
RM		:= rm -rf
CFLAGS	:= -Wall -Wextra -Werror -std=c++17

ifdef DEBUG
	CFLAGS += -g -D DEBUG
endif

## Directories ##
INC_DIR	:= include
SRC_DIR	:= src
OBJ_DIR	:= obj

## Files ##
SRC		:= main.cpp Animal.cpp Cat.cpp Dog.cpp WrongAnimal.cpp WrongCat.cpp
INCLUDE	:= -I $(INC_DIR)
OBJS	:= $(addprefix $(OBJ_DIR)/, $(SRC:%.cpp=%.o))

## Rules ##
all: $(NAME)

debug:
	$(MAKE) DEBUG=1

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(OBJ_DIR)
	@$(RM) $(NAME)

re: fclean all

rebug: fclean debug

## Compilation ##
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDE) $(OBJS) -o $(NAME)

$(OBJS): $(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

## Phony ##
.PHONY: all clean fclean re
