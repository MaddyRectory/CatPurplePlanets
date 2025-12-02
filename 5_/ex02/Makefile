# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mairivie <mairivie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/27 11:19:55 by mairivie          #+#    #+#              #
#    Updated: 2025/12/02 17:02:05 by mairivie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CPP       = c++
CPPFLAGS  = -Wall -Wextra -Werror -std=c++98

NAME = bureaucrat

SRCS = main.cpp Bureaucrat.cpp AForm.cpp \
	RobotomyRequestForm.cpp \
	PresidentialPardonForm.cpp \
	ShruberryCreationForm.cpp
	
SRC_DIR = src
SRC = $(addprefix $(SRC_DIR)/, $(SRCS))

OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/, $(SRCS:.cpp=.o))
DEP = $(addprefix $(OBJ_DIR)/, $(SRCS:.cpp=.d))


all: $(NAME)

$(NAME): $(OBJ)
	$(CPP) $(CPPFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@if [ ! -d obj ]; then mkdir -p $(@D); echo "mkdir -p $(@D)" ; fi
	$(CPP) $(CPPFLAGS) -MMD -c $< -o $@

-include ${DEP}

clean:
	@if [ -d obj ]; then rm -r obj; echo "rm -r obj" ; fi
	@if [ -f *_shrubbery ]; then rm *_shrubbery ; echo "rm *_shrubbery" ; fi

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re


# ABOUT .d pour gestion modif .h

# # C'est assez facile de faire une dépendance d'entête en faisant du pur make POSIX (compatible BSD et GNU).
# # Il suffit d'utiliser -MMD avec gcc/clang.

# # # SRCS= foo.c bar.c quux.c
# # # OBJS= ${SRCS:.c=.o}
# # # DEPS= ${SRCS:.c=.d}
 
# # # all: main
 
# # # .c.o:
# # #     ${CC} ${CFLAGS} -MMD -c $< -o $@
 
# # # # la magie ici
# # # -include ${DEPS}
 
# # # main: ${OBJS}
 
# # # clean:
# # #     rm -f main ${OBJS} ${DEPS}
 
# # # .PHONY: all clean

# # De ce fait, pendant la compilation, 
# # le compilateur créé des fichiers .d compatible make 
# # qui contient les dépendance d'entête pour chaque fichier objet. 
# # Par conséquent make sait qui reconstruire si on modifie un entête.