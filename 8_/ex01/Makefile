# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mairivie <mairivie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/12 14:00:22 by mairivie          #+#    #+#              #
#    Updated: 2026/01/21 14:08:25 by mairivie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CPP       = c++
CPPFLAGS  = -Wall -Wextra -Werror -std=c++98

NAME = span

SRCS = main.cpp Span.cpp
	
SRC_DIR = src
SRC = $(addprefix $(SRC_DIR)/, $(SRCS))

OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/, $(SRCS:.cpp=.o))
DEP = $(addprefix $(OBJ_DIR)/, $(SRCS:.cpp=.d))


all: $(NAME)
	@echo "-----\nAll good ! Use ./$(NAME) to start the program\n-----"
.PHONY: all

$(NAME): $(OBJ)
	$(CPP) $(CPPFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@if [ ! -d obj ]; then mkdir -p $(@D); echo "mkdir -p $(@D)" ; fi
	$(CPP) $(CPPFLAGS) -MMD -c $< -o $@

-include ${DEP}

clean:
	@if [ -d obj ]; then rm -r obj; echo "rm -r obj" ; fi
.PHONY: clean

fclean: clean
	rm -f $(NAME)
.PHONY: fclean

re: fclean all
.PHONY: re