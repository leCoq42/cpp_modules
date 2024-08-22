NAME	:= btc

## General ##
CC		:= c++
RM		:= rm -rf
CFLAGS	:= -Wall -Wextra -Werror -std=c++20

ifdef DEBUG
	CFLAGS += -g -fsanitize=address,undefined -D DEBUG
endif

## Directories ##
INC_DIR	:= include
SRC_DIR	:= src
OBJ_DIR	:= obj

## Files ##
SRC		:= main.cpp BitcoinExchange.cpp

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
.PHONY: all debug clean fclean re rebug
