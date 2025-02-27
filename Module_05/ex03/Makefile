# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: algultse <algultse@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/22 22:58:54 by algultse          #+#    #+#              #
#    Updated: 2025/01/26 23:41:30 by algultse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Intern

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

OBJDIR = ./obj/
SRCDIR = ./srcs/
INCDIR = ./include/

SRC = Bureaucrat.cpp AForm.cpp \
		ShrubberyCreationForm.cpp \
		RobotomyRequestForm.cpp \
		PresidentialPardonForm.cpp \
		Intern.cpp \
		main.cpp
OBJS = $(SRC:%.cpp=$(OBJDIR)%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(OBJDIR)%.o: $(SRCDIR)%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -I$(INCDIR) -c $< -o $@

clean:
	rm -rf $(OBJDIR)
# rm -f *_shrubbery

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re