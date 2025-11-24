# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mairivie <mairivie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/27 11:19:55 by mairivie          #+#    #+#              #
#    Updated: 2025/11/24 15:23:03 by mairivie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CPP       = c++
CPPFLAGS  = -Wall -Wextra -Werror -std=c++98

NAME = bureaucrat
SRCS = main.cpp Bureaucrat.cpp AForm.cpp \
	RobotomyRequestForm.cpp \
	PresidentialPardonForm.cpp \
	ShruberryCreationForm.cpp
OBJ_DIR = obj
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(CPPFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: %.cpp
	@if [ ! -d obj ]; then mkdir -p $(@D); echo "mkdir -p $(@D)" ; fi
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	@if [ -d obj ]; then rm -r obj; echo "rm -r obj" ; fi

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

# TODO: creer un dossier src, 
# modif makefile pour src
# creer un dossier include
# modif les .cpp pour MAJ les .hpp 
# apprendre a gerer les .d
# modif makefile pour gestion des .d