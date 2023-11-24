NAME	:= megaphone

CC		:= g++
RM		:= rm -rf
CFLAGS	:= -Wall -Wextra -Werror -std=c++98

SRC		:= megaphone.cpp
ODIR	:= obj
OBJS	:= $(addprefix $(ODIR)/, $(SRC:%.cpp=%.o))

all: $(NAME)

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(ODIR)
	@$(RM) $(NAME)

re: fclean all

## Compile ##
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJS): $(ODIR)/%.o: %.cpp
	mkdir -p $(ODIR)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re
